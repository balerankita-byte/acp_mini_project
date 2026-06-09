# 2D Graphics Editor

A terminal-based 2D graphics drawing application using ncurses library.

## Features

- **Draw Rectangle**: Create filled rectangles on the canvas
- **Draw Line**: Draw horizontal or vertical lines
- **Draw Triangle**: Draw triangular shapes
- **Draw Circle**: Draw circular shapes
- **Delete Area**: Erase rectangular regions
- **Display Picture**: View your complete drawing
- **Clear Canvas**: Reset the entire canvas
- **Exit**: Quit the application

## Canvas Specifications

- Dimensions: 25 rows × 50 columns
- Background: `_` (underscore)
- Drawing character: `*` (asterisk)

## Requirements

- GCC compiler
- ncurses development library
- Unix/Linux environment

### Installation of Dependencies

**Ubuntu/Debian:**
```bash
sudo apt-get install libncurses-dev build-essential
```

**macOS (with Homebrew):**
```bash
brew install ncurses
```

**Fedora/RHEL:**
```bash
sudo dnf install ncurses-devel gcc
```

## Compilation

Using the provided Makefile:
```bash
make
```

Or manually:
```bash
gcc -Wall -Wextra -std=c99 -o graphics_editor graphics_editor.c -lncurses -lm
```

## Usage

Run the program:
```bash
make run
```

Or directly:
```bash
./graphics_editor
```

### Menu Options

1. **Draw Rectangle**: Enter `x y width height`
2. **Draw Line**: Enter `x1 y1 x2 y2` (horizontal or vertical only)
3. **Draw Triangle**: Enter `x y height`
4. **Draw Circle**: Enter `center_x center_y radius`
5. **Delete Area**: Enter `x y width height`
6. **Display Picture**: View the current canvas
7. **Clear Canvas**: Clear all drawings
8. **Exit**: Close the application

## Examples

### Draw a Rectangle
- Menu choice: `1`
- Input: `5 5 10 8` (x=5, y=5, width=10, height=8)

### Draw a Circle
- Menu choice: `4`
- Input: `25 12 5` (center_x=25, center_y=12, radius=5)

### Draw a Line
- Menu choice: `2`
- Input: `0 10 40 10` (horizontal line from (0,10) to (40,10))

## Cleanup

Remove the compiled executable:
```bash
make clean
```

## Notes

- Coordinates start from (0, 0) at the top-left
- All shapes are filled
- The circle drawing uses the distance formula
- Lines must be either horizontal or vertical
