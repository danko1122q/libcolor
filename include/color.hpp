#pragma once
#include <cstdint>
#include <ostream>
#include <string>

namespace ansi {

struct RGB {
    uint8_t r, g, b;
    constexpr RGB(uint8_t r, uint8_t g, uint8_t b) : r(r), g(g), b(b) {}
};

namespace color {
    constexpr RGB Red             {220,  20,  60};
    constexpr RGB Crimson         {220,  20,  60};
    constexpr RGB DarkRed         {139,   0,   0};
    constexpr RGB Firebrick       {178,  34,  34};
    constexpr RGB IndianRed       {205,  92,  92};
    constexpr RGB LightCoral      {240, 128, 128};
    constexpr RGB Salmon          {250, 128, 114};
    constexpr RGB DarkSalmon      {233, 150, 122};
    constexpr RGB LightSalmon     {255, 160, 122};
    constexpr RGB OrangeRed       {255,  69,   0};
    constexpr RGB Tomato          {255,  99,  71};

    constexpr RGB Orange          {255, 165,   0};
    constexpr RGB DarkOrange      {255, 140,   0};
    constexpr RGB Gold            {255, 215,   0};
    constexpr RGB Yellow          {255, 255,   0};
    constexpr RGB LightYellow     {255, 255, 224};
    constexpr RGB LemonChiffon    {255, 250, 205};
    constexpr RGB Khaki           {240, 230, 140};
    constexpr RGB DarkKhaki       {189, 183, 107};

    constexpr RGB Green           {  0, 128,   0};
    constexpr RGB LimeGreen       { 50, 205,  50};
    constexpr RGB Lime            {  0, 255,   0};
    constexpr RGB DarkGreen       {  0, 100,   0};
    constexpr RGB ForestGreen     { 34, 139,  34};
    constexpr RGB SeaGreen        { 46, 139,  87};
    constexpr RGB MediumSeaGreen  { 60, 179, 113};
    constexpr RGB SpringGreen     {  0, 255, 127};
    constexpr RGB GreenYellow     {173, 255,  47};
    constexpr RGB Chartreuse      {127, 255,   0};
    constexpr RGB OliveDrab       {107, 142,  35};
    constexpr RGB Olive           {128, 128,   0};
    constexpr RGB DarkOliveGreen  { 85, 107,  47};
    constexpr RGB Teal            {  0, 128, 128};
    constexpr RGB DarkCyan        {  0, 139, 139};
    constexpr RGB Aquamarine      {127, 255, 212};
    constexpr RGB MediumAquamarine{102, 205, 170};
    constexpr RGB PaleGreen       {152, 251, 152};

    constexpr RGB Cyan            {  0, 255, 255};
    constexpr RGB Aqua            {  0, 255, 255};
    constexpr RGB LightCyan       {224, 255, 255};
    constexpr RGB Blue            {  0,   0, 255};
    constexpr RGB DarkBlue        {  0,   0, 139};
    constexpr RGB MediumBlue      {  0,   0, 205};
    constexpr RGB NavyBlue        {  0,   0, 128};
    constexpr RGB RoyalBlue       { 65, 105, 225};
    constexpr RGB CornflowerBlue  {100, 149, 237};
    constexpr RGB SteelBlue       { 70, 130, 180};
    constexpr RGB LightSteelBlue  {176, 196, 222};
    constexpr RGB DodgerBlue      { 30, 144, 255};
    constexpr RGB DeepSkyBlue     {  0, 191, 255};
    constexpr RGB SkyBlue         {135, 206, 235};
    constexpr RGB LightSkyBlue    {135, 206, 250};
    constexpr RGB LightBlue       {173, 216, 230};
    constexpr RGB PowderBlue      {176, 224, 230};
    constexpr RGB MidnightBlue    { 25,  25, 112};
    constexpr RGB SlateBlue       {106,  90, 205};
    constexpr RGB MediumSlateBlue {123, 104, 238};
    constexpr RGB DarkSlateBlue   { 72,  61, 139};

    constexpr RGB Purple          {128,   0, 128};
    constexpr RGB DarkMagenta     {139,   0, 139};
    constexpr RGB Magenta         {255,   0, 255};
    constexpr RGB Fuchsia         {255,   0, 255};
    constexpr RGB Violet          {238, 130, 238};
    constexpr RGB Orchid          {218, 112, 214};
    constexpr RGB MediumOrchid    {186,  85, 211};
    constexpr RGB MediumPurple    {147, 112, 219};
    constexpr RGB BlueViolet      {138,  43, 226};
    constexpr RGB DarkViolet      {148,   0, 211};
    constexpr RGB DarkOrchid      {153,  50, 204};
    constexpr RGB Indigo          { 75,   0, 130};
    constexpr RGB Lavender        {230, 230, 250};
    constexpr RGB Plum            {221, 160, 221};
    constexpr RGB Thistle         {216, 191, 216};

    constexpr RGB Pink            {255, 192, 203};
    constexpr RGB LightPink       {255, 182, 193};
    constexpr RGB HotPink         {255, 105, 180};
    constexpr RGB DeepPink        {255,  20, 147};
    constexpr RGB MediumVioletRed {199,  21, 133};
    constexpr RGB PaleVioletRed   {219, 112, 147};

    constexpr RGB Brown           {165,  42,  42};
    constexpr RGB Maroon          {128,   0,   0};
    constexpr RGB SaddleBrown     {139,  69,  19};
    constexpr RGB Sienna          {160,  82,  45};
    constexpr RGB Chocolate       {210, 105,  30};
    constexpr RGB Peru            {205, 133,  63};
    constexpr RGB BurlyWood       {222, 184, 135};
    constexpr RGB Tan             {210, 180, 140};
    constexpr RGB RosyBrown       {188, 143, 143};
    constexpr RGB Sandy           {244, 164,  96};
    constexpr RGB Wheat           {245, 222, 179};
    constexpr RGB Bisque          {255, 228, 196};
    constexpr RGB Moccasin        {255, 228, 181};
    constexpr RGB NavajoWhite     {255, 222, 173};
    constexpr RGB PeachPuff       {255, 218, 185};

    constexpr RGB White           {255, 255, 255};
    constexpr RGB Snow            {255, 250, 250};
    constexpr RGB HoneyDew        {240, 255, 240};
    constexpr RGB MintCream       {245, 255, 250};
    constexpr RGB Azure           {240, 255, 255};
    constexpr RGB AliceBlue       {240, 248, 255};
    constexpr RGB GhostWhite      {248, 248, 255};
    constexpr RGB WhiteSmoke      {245, 245, 245};
    constexpr RGB SeaShell        {255, 245, 238};
    constexpr RGB Beige           {245, 245, 220};
    constexpr RGB OldLace         {253, 245, 230};
    constexpr RGB FloralWhite     {255, 250, 240};
    constexpr RGB Ivory           {255, 255, 240};
    constexpr RGB AntiqueWhite    {250, 235, 215};
    constexpr RGB Linen           {250, 240, 230};
    constexpr RGB LavenderBlush   {255, 240, 245};
    constexpr RGB MistyRose       {255, 228, 225};
    constexpr RGB Gainsboro       {220, 220, 220};
    constexpr RGB LightGray       {211, 211, 211};
    constexpr RGB Silver          {192, 192, 192};
    constexpr RGB DarkGray        {169, 169, 169};
    constexpr RGB Gray            {128, 128, 128};
    constexpr RGB DimGray         {105, 105, 105};
    constexpr RGB LightSlateGray  {119, 136, 153};
    constexpr RGB SlateGray       {112, 128, 144};
    constexpr RGB DarkSlateGray   { 47,  79,  79};
    constexpr RGB Black           {  0,   0,   0};

    constexpr RGB BrightRed       {255,  50,  50};
    constexpr RGB BrightGreen     { 50, 255,  50};
    constexpr RGB BrightBlue      { 50, 100, 255};
    constexpr RGB BrightYellow    {255, 255,  50};
    constexpr RGB BrightCyan      { 50, 255, 255};
    constexpr RGB BrightMagenta   {255,  50, 255};
    constexpr RGB BrightOrange    {255, 140,  30};
    constexpr RGB BrightPink      {255,  80, 180};
}

namespace color256 {
    constexpr uint8_t Black       =   0;
    constexpr uint8_t Maroon      =   1;
    constexpr uint8_t Green       =   2;
    constexpr uint8_t Olive       =   3;
    constexpr uint8_t NavyBlue    =   4;
    constexpr uint8_t Purple      =   5;
    constexpr uint8_t Teal        =   6;
    constexpr uint8_t Silver      =   7;
    constexpr uint8_t Grey        =   8;
    constexpr uint8_t Red         =   9;
    constexpr uint8_t Lime        =  10;
    constexpr uint8_t Yellow      =  11;
    constexpr uint8_t Blue        =  12;
    constexpr uint8_t Fuchsia     =  13;
    constexpr uint8_t Aqua        =  14;
    constexpr uint8_t White       =  15;

    constexpr uint8_t DarkBlue          =  17;
    constexpr uint8_t NavyBlue2         =  18;
    constexpr uint8_t DarkBlue2         =  19;
    constexpr uint8_t Blue2             =  20;
    constexpr uint8_t Blue3             =  21;
    constexpr uint8_t DarkGreen         =  22;
    constexpr uint8_t DeepSkyBlue       =  23;
    constexpr uint8_t DeepSkyBlue2      =  24;
    constexpr uint8_t DeepSkyBlue3      =  25;
    constexpr uint8_t DodgerBlue        =  26;
    constexpr uint8_t DodgerBlue2       =  27;
    constexpr uint8_t Green2            =  28;
    constexpr uint8_t SpringGreen       =  29;
    constexpr uint8_t Turquoise         =  30;
    constexpr uint8_t DeepSkyBlue4      =  31;
    constexpr uint8_t DeepSkyBlue5      =  32;
    constexpr uint8_t DodgerBlue3       =  33;
    constexpr uint8_t Green3            =  34;
    constexpr uint8_t SpringGreen2      =  35;
    constexpr uint8_t DarkCyan          =  36;
    constexpr uint8_t LightSeaGreen     =  37;
    constexpr uint8_t DeepSkyBlue6      =  38;
    constexpr uint8_t DeepSkyBlue7      =  39;
    constexpr uint8_t Green4            =  40;
    constexpr uint8_t SpringGreen3      =  41;
    constexpr uint8_t SpringGreen4      =  42;
    constexpr uint8_t Cyan              =  43;
    constexpr uint8_t DarkTurquoise     =  44;
    constexpr uint8_t Turquoise2        =  45;
    constexpr uint8_t Green5            =  46;
    constexpr uint8_t SpringGreen5      =  47;
    constexpr uint8_t SpringGreen6      =  48;
    constexpr uint8_t MediumSpringGreen =  49;
    constexpr uint8_t Cyan2             =  50;
    constexpr uint8_t Cyan3             =  51;

    constexpr uint8_t Gold              = 142;
    constexpr uint8_t Orange            = 214;
    constexpr uint8_t OrangeRed         = 202;
    constexpr uint8_t HotPink           = 205;
    constexpr uint8_t DeepPink          = 198;
    constexpr uint8_t MediumVioletRed   = 126;
    constexpr uint8_t Magenta           = 201;
    constexpr uint8_t Orchid            = 170;
    constexpr uint8_t MediumOrchid      = 134;
    constexpr uint8_t BlueViolet        =  57;
    constexpr uint8_t DarkViolet        =  92;
    constexpr uint8_t DarkOrchid        = 134;
    constexpr uint8_t Indigo            =  54;
    constexpr uint8_t Plum              = 183;
    constexpr uint8_t Thistle           = 182;
    constexpr uint8_t SaddleBrown       =  94;
    constexpr uint8_t Brown             = 130;
    constexpr uint8_t Sienna            = 131;
    constexpr uint8_t Chocolate         = 166;
    constexpr uint8_t Peru              = 173;
    constexpr uint8_t BurlyWood         = 180;
    constexpr uint8_t Sandy             = 215;

    constexpr uint8_t Grey3  = 232;
    constexpr uint8_t Grey7  = 233;
    constexpr uint8_t Grey11 = 234;
    constexpr uint8_t Grey15 = 235;
    constexpr uint8_t Grey19 = 236;
    constexpr uint8_t Grey23 = 237;
    constexpr uint8_t Grey27 = 238;
    constexpr uint8_t Grey30 = 239;
    constexpr uint8_t Grey35 = 240;
    constexpr uint8_t Grey39 = 241;
    constexpr uint8_t Grey42 = 242;
    constexpr uint8_t Grey46 = 243;
    constexpr uint8_t Grey50 = 244;
    constexpr uint8_t Grey54 = 245;
    constexpr uint8_t Grey58 = 246;
    constexpr uint8_t Grey62 = 247;
    constexpr uint8_t Grey66 = 248;
    constexpr uint8_t Grey70 = 249;
    constexpr uint8_t Grey74 = 250;
    constexpr uint8_t Grey78 = 251;
    constexpr uint8_t Grey82 = 252;
    constexpr uint8_t Grey85 = 253;
    constexpr uint8_t Grey89 = 254;
    constexpr uint8_t Grey93 = 255;

    constexpr uint8_t cube(uint8_t r, uint8_t g, uint8_t b) {
        return static_cast<uint8_t>(16 + 36*r + 6*g + b);
    }
    constexpr uint8_t gray(uint8_t step) {
        return static_cast<uint8_t>(232 + (step < 24 ? step : 23));
    }
}

namespace detail {
    struct Escape {
        std::string seq;
        explicit Escape(std::string s) : seq(std::move(s)) {}
        operator std::string() const { return seq; }
        std::string str() const { return seq; }
        friend std::ostream& operator<<(std::ostream& os, const Escape& e) {
            return os << e.seq;
        }
    };

    std::string fg_seq(uint8_t r, uint8_t g, uint8_t b);
    std::string bg_seq(uint8_t r, uint8_t g, uint8_t b);
    std::string fg256_seq(uint8_t n);
    std::string bg256_seq(uint8_t n);
    uint8_t     clamp_u8(float v);
}

struct ResetT {};
constexpr ResetT reset{};
inline std::ostream& operator<<(std::ostream& os, ResetT) { return os << "\033[0m"; }
inline std::string   reset_str() { return "\033[0m"; }

detail::Escape reset_fg();
detail::Escape reset_bg();

detail::Escape fg(uint8_t r, uint8_t g, uint8_t b);
detail::Escape fg(RGB c);
detail::Escape bg(uint8_t r, uint8_t g, uint8_t b);
detail::Escape bg(RGB c);
detail::Escape fg256(uint8_t n);
detail::Escape bg256(uint8_t n);

detail::Escape bold();
detail::Escape dim();
detail::Escape italic();
detail::Escape underline();
detail::Escape blink();
detail::Escape inverse();
detail::Escape strikethrough();

bool supports_truecolor();
bool supports_256color();

class Style {
    std::string _seq;
public:
    Style() = default;
    Style& fg(uint8_t r, uint8_t g, uint8_t b);
    Style& fg(RGB c);
    Style& bg(uint8_t r, uint8_t g, uint8_t b);
    Style& bg(RGB c);
    Style& fg256(uint8_t n);
    Style& bg256(uint8_t n);
    Style& bold();
    Style& dim();
    Style& italic();
    Style& underline();
    Style& blink();
    Style& inverse();
    Style& strikethrough();
    const std::string& str() const { return _seq; }
    friend std::ostream& operator<<(std::ostream& os, const Style& s) { return os << s._seq; }
};

std::string paint(const std::string& text, RGB c);
std::string paint(const std::string& text, RGB fc, RGB bc);
std::string paint(const std::string& text, uint8_t r, uint8_t g, uint8_t b);
std::string paint256(const std::string& text, uint8_t n);
std::string paint256(const std::string& text, uint8_t fn, uint8_t bn);

RGB from_hsl(float h, float s, float l);
RGB from_hex(const char* hex);
RGB from_hex(const std::string& hex);

} // namespace ansi
