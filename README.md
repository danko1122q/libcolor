# libcolor

C++11 ANSI color library. No dependencies. Named colors + true-color RGB + 256-color palette.

Available as a **static library** (`libcolor.a`) or **shared library** (`libcolor.so`).

## Build

```bash
make           # → libcolor.a
make shared    # → libcolor.so
make example   # build and run the demo
make clean
```

Install to system (default `/usr/local`):

```bash
make install              # install libcolor.a + color.hpp
make install-shared       # install libcolor.so + color.hpp
make PREFIX=/opt install  # custom prefix
```

## Linking

```bash
g++ -std=c++11 -Iinclude main.cpp -L. -lcolor -o myapp
```

After `make install`:

```bash
g++ -std=c++11 main.cpp -lcolor -o myapp
```

## Usage

```cpp
#include "color.hpp"
using namespace ansi;
```

### Basic

```cpp
std::cout << fg(color::Crimson) << "red text" << reset << "\n";
std::cout << bg(color::NavyBlue) << "blue background" << reset << "\n";
std::cout << fg(color::White) << bg(color::Indigo) << "both" << reset << "\n";
```

`reset` clears all attributes. `reset_fg()` and `reset_bg()` reset only color without touching other attributes.

### Color input

```cpp
fg(color::DodgerBlue)          // named color
fg(255, 100, 0)                // RGB values
fg(from_hex("#FF6B6B"))        // hex string
fg(from_hsl(200, 0.8f, 0.5f)) // HSL: h=0-360, s/l=0-1
```

### 256-color

```cpp
fg256(196)                     // by index directly
fg256(color256::Gold)          // named alias
fg256(color256::cube(5, 2, 0)) // 6x6x6 cube, each component 0-5
fg256(color256::gray(12))      // grayscale ramp, step 0-23
```

### paint()

Wraps text with color and resets automatically — no manual `<< reset` needed.

```cpp
std::cout << paint("hello", color::LimeGreen) << "\n";
std::cout << paint("hello", color::White, color::Indigo) << "\n"; // fg + bg
std::cout << paint256("hello", color256::Orange) << "\n";
std::cout << paint256("hello", color256::White, color256::DarkRed) << "\n";
```

### Style builder

```cpp
std::cout << Style().fg(color::Black).bg(color::Gold).bold() << "text" << reset << "\n";
std::cout << Style().fg256(color256::DeepPink).italic().underline() << "text" << reset << "\n";
```

Available attributes: `bold()` `dim()` `italic()` `underline()` `blink()` `inverse()` `strikethrough()`

### Terminal detection

```cpp
if (ansi::supports_truecolor()) { /* use fg(RGB) */ }
if (ansi::supports_256color())  { /* use fg256() */ }
```

Checks `$COLORTERM` and `$TERM`. Falls back gracefully — your code won't crash on dumb terminals, colors just won't show.

## Directory structure

```
libcolor/
├── include/
│   └── color.hpp
├── src/
│   └── color.cpp
├── example/
│   └── demo.cpp
├── Makefile
└── README.md
```
