#include "color.hpp"
#include <iostream>

int main() {
    // Access the namespace for easier use
    using namespace ansi;

    // 1. Basic Usage: Crimson text and Navy Blue background
    std::cout << fg(color::Crimson) << "This is Crimson text" << reset << "\n";
    std::cout << bg(color::NavyBlue) << "This has a Navy Blue background" << reset << "\n";
    std::cout << fg(color::White) << bg(color::Indigo) << "White text on Indigo" << reset << "\n\n";

    // 2. Color Input Methods
    std::cout << fg(255, 100, 0) << "Color via RGB (255, 100, 0)" << reset << "\n";
    std::cout << fg(from_hex("#FF6B6B")) << "Color via Hex #FF6B6B" << reset << "\n";
    std::cout << fg(from_hsl(200, 0.8f, 0.5f)) << "Color via HSL" << reset << "\n\n";

    // 3. Using the paint() wrapper (No manual reset needed)
    std::cout << paint("This green text resets automatically!", color::LimeGreen) << "\n";
    std::cout << paint("White on Indigo using paint()", color::White, color::Indigo) << "\n\n";

    // 4. 256-Color Palette
    std::cout << fg256(color256::Gold) << "Using 256-color Gold alias" << reset << "\n";
    std::cout << fg256(color256::cube(5, 2, 0)) << "Using 6x6x6 color cube" << reset << "\n\n";

    // 5. Style Builder for multiple attributes
    std::cout << Style().fg(color::Black).bg(color::Gold).bold() 
              << " Bold Black on Gold " << reset << "\n";
    
    std::cout << Style().fg256(color256::DeepPink).italic().underline() 
              << "Italic and Underlined Pink" << reset << "\n\n";

    // 6. Terminal Detection
    if (ansi::supports_truecolor()) {
        std::cout << "Your terminal supports TrueColor!\n";
    }

    return 0;
}