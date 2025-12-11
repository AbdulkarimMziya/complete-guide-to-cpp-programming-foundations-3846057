
# Preprocessor Directives (Super Simple)

Preprocessor directives are special instructions that are processed before your C++ code is actually compiled. They always start with a `#` symbol and are used to control how your code is built.

## Why use preprocessor directives?
- Include code from other files
- Define constants or macros
- Control which parts of code get compiled

## Common preprocessor directives

- `#include` — Adds code from another file (like libraries)
	```cpp
	#include <iostream> // Lets you use std::cout and std::endl
	#include "myheader.h" // Includes your own header file
	```
- `#define` — Creates a constant or a macro
	```cpp
	#define PI 3.14159
	#define SQUARE(x) ((x)*(x))
	```
- `#ifdef`, `#ifndef`, `#endif` — Compiles code only if something is (or isn’t) defined
	```cpp
	#define DEBUG

	#ifdef DEBUG
	std::cout << "Debug mode!" << std::endl;
	#endif
	```
- `#pragma once` — Makes sure a file is only included once (avoids duplicate code)
	```cpp
	#pragma once
	```

## Key things to remember
- Preprocessor directives are not C++ statements—they’re handled before your code is compiled
- They help organize, simplify, and control your code

Preprocessor directives make your code more flexible and easier to manage!
