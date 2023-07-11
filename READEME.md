# A 3D level with C raytracing

Using a C graphic library (minilibX), this project make the most of raytracing to create a 3D labyrinth in a 90's style.

Features:
- Print the level based on a .cub file
- Right and Left to rotate the camera
- W, A, S et D to move the camera
- Esc to quit the program
- Manage window changes
- Lose life when the character goes into sprites
- Export the initial view in save.bmp file
- No memory leak

## Installation

Use this command in a terminal : 

```bash
make
```

(make and clang needed)

## Usage

- Add #include "Map.hpp" in a cpp file (like in Test_Map.cpp)


#### Author : Alban Kerloc'h
#### Category: Low-level, 3D
#### Tag: C