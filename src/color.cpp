#include "color.hpp"
#include <cstdio>
#include <cstdlib>

namespace ansi {

namespace detail {

std::string fg_seq(uint8_t r, uint8_t g, uint8_t b) {
    char buf[24];
    std::snprintf(buf, sizeof(buf), "\033[38;2;%d;%d;%dm", r, g, b);
    return buf;
}

std::string bg_seq(uint8_t r, uint8_t g, uint8_t b) {
    char buf[24];
    std::snprintf(buf, sizeof(buf), "\033[48;2;%d;%d;%dm", r, g, b);
    return buf;
}

std::string fg256_seq(uint8_t n) {
    char buf[16];
    std::snprintf(buf, sizeof(buf), "\033[38;5;%dm", n);
    return buf;
}

std::string bg256_seq(uint8_t n) {
    char buf[16];
    std::snprintf(buf, sizeof(buf), "\033[48;5;%dm", n);
    return buf;
}

uint8_t clamp_u8(float v) {
    if (v <= 0.f) return 0;
    if (v >= 1.f) return 255;
    return static_cast<uint8_t>(v * 255.f);
}

} // namespace detail

detail::Escape reset_fg() { return detail::Escape("\033[39m"); }
detail::Escape reset_bg() { return detail::Escape("\033[49m"); }

detail::Escape fg(uint8_t r, uint8_t g, uint8_t b) { return detail::Escape(detail::fg_seq(r, g, b)); }
detail::Escape fg(RGB c)                            { return fg(c.r, c.g, c.b); }
detail::Escape bg(uint8_t r, uint8_t g, uint8_t b) { return detail::Escape(detail::bg_seq(r, g, b)); }
detail::Escape bg(RGB c)                            { return bg(c.r, c.g, c.b); }
detail::Escape fg256(uint8_t n)                     { return detail::Escape(detail::fg256_seq(n)); }
detail::Escape bg256(uint8_t n)                     { return detail::Escape(detail::bg256_seq(n)); }

detail::Escape bold()          { return detail::Escape("\033[1m"); }
detail::Escape dim()           { return detail::Escape("\033[2m"); }
detail::Escape italic()        { return detail::Escape("\033[3m"); }
detail::Escape underline()     { return detail::Escape("\033[4m"); }
detail::Escape blink()         { return detail::Escape("\033[5m"); }
detail::Escape inverse()       { return detail::Escape("\033[7m"); }
detail::Escape strikethrough() { return detail::Escape("\033[9m"); }

bool supports_truecolor() {
    const char* ct = std::getenv("COLORTERM");
    if (!ct) return false;
    std::string s(ct);
    return s == "truecolor" || s == "24bit";
}

bool supports_256color() {
    const char* ct = std::getenv("COLORTERM");
    if (ct) return true;
    const char* t = std::getenv("TERM");
    if (!t) return false;
    std::string ts(t);
    return ts.find("256") != std::string::npos || ts == "xterm" || ts == "screen";
}

Style& Style::fg(uint8_t r, uint8_t g, uint8_t b) { _seq += detail::fg_seq(r, g, b); return *this; }
Style& Style::fg(RGB c)        { return fg(c.r, c.g, c.b); }
Style& Style::bg(uint8_t r, uint8_t g, uint8_t b) { _seq += detail::bg_seq(r, g, b); return *this; }
Style& Style::bg(RGB c)        { return bg(c.r, c.g, c.b); }
Style& Style::fg256(uint8_t n) { _seq += detail::fg256_seq(n); return *this; }
Style& Style::bg256(uint8_t n) { _seq += detail::bg256_seq(n); return *this; }
Style& Style::bold()           { _seq += "\033[1m"; return *this; }
Style& Style::dim()            { _seq += "\033[2m"; return *this; }
Style& Style::italic()         { _seq += "\033[3m"; return *this; }
Style& Style::underline()      { _seq += "\033[4m"; return *this; }
Style& Style::blink()          { _seq += "\033[5m"; return *this; }
Style& Style::inverse()        { _seq += "\033[7m"; return *this; }
Style& Style::strikethrough()  { _seq += "\033[9m"; return *this; }

std::string paint(const std::string& text, RGB c) {
    return detail::fg_seq(c.r, c.g, c.b) + text + "\033[0m";
}
std::string paint(const std::string& text, RGB fc, RGB bc) {
    return detail::fg_seq(fc.r, fc.g, fc.b) + detail::bg_seq(bc.r, bc.g, bc.b) + text + "\033[0m";
}
std::string paint(const std::string& text, uint8_t r, uint8_t g, uint8_t b) {
    return detail::fg_seq(r, g, b) + text + "\033[0m";
}
std::string paint256(const std::string& text, uint8_t n) {
    return detail::fg256_seq(n) + text + "\033[0m";
}
std::string paint256(const std::string& text, uint8_t fn, uint8_t bn) {
    return detail::fg256_seq(fn) + detail::bg256_seq(bn) + text + "\033[0m";
}

RGB from_hsl(float h, float s, float l) {
    auto hue2rgb = [](float p, float q, float t) -> float {
        if (t < 0.f) t += 1.f;
        if (t > 1.f) t -= 1.f;
        if (t < 1.f/6) return p + (q - p) * 6 * t;
        if (t < 1.f/2) return q;
        if (t < 2.f/3) return p + (q - p) * (2.f/3 - t) * 6;
        return p;
    };
    float r, g, b;
    if (s == 0.f) {
        r = g = b = l;
    } else {
        float q = l < .5f ? l * (1 + s) : l + s - l * s;
        float p = 2 * l - q;
        float hf = h / 360.f;
        r = hue2rgb(p, q, hf + 1.f/3);
        g = hue2rgb(p, q, hf);
        b = hue2rgb(p, q, hf - 1.f/3);
    }
    return RGB{detail::clamp_u8(r), detail::clamp_u8(g), detail::clamp_u8(b)};
}

RGB from_hex(const char* hex) {
    if (*hex == '#') ++hex;
    unsigned v = 0;
    for (int i = 0; i < 6 && *hex; ++i, ++hex) {
        char c = *hex;
        v <<= 4;
        if      (c >= '0' && c <= '9') v |= static_cast<unsigned>(c - '0');
        else if (c >= 'a' && c <= 'f') v |= static_cast<unsigned>(c - 'a' + 10);
        else if (c >= 'A' && c <= 'F') v |= static_cast<unsigned>(c - 'A' + 10);
    }
    return RGB{static_cast<uint8_t>(v >> 16),
               static_cast<uint8_t>(v >>  8),
               static_cast<uint8_t>(v)};
}

RGB from_hex(const std::string& hex) { return from_hex(hex.c_str()); }

} // namespace ansi
