# Arrays (Super Simple)

Arrays let you store a fixed number of values of the same type in a single variable. Think of them as a row of boxes, each holding a value, and you can access each box by its position (index).

## Why use arrays?
- Store lots of related values together (like scores, names, or positions)
- Access any value quickly by its index

## How do you make an array?
You declare an array by specifying the type and the number of elements:
```cpp
int numbers[5]; // An array of 5 integers
```
You can also set the values when you create the array:
```cpp
int scores[3] = {100, 90, 80};
```

## Using Macros for Array Size
To make your code easier to update, use a macro for the array size:
```cpp
#define ARRAY_SIZE 10
int data[ARRAY_SIZE];
```

## Using size_t for Indexing
`size_t` is an unsigned integer type used for sizes and indexing. It’s the safest type for array indices and loops:
```cpp
#include <cstddef>
for (size_t i = 0; i < ARRAY_SIZE; ++i) {
	data[i] = i * 2;
}
```

## How do you use an array?
You access each value by its index (starting at 0):
```cpp
int firstScore = scores[0]; // 100
scores[1] = 95; // Change the second score to 95
```

## Key things to remember
- Array indices start at 0 (the first element is index 0)
- The size of an array is fixed when you create it
- All elements must be the same type


Arrays help you organize and manage lots of data easily!

# Pointers (Super Simple)

Pointers are variables that store memory addresses. They let you work directly with memory and are a powerful feature in C++.

## Why use pointers?
- Access and modify data in different places in memory
- Work with dynamic memory (like creating arrays at runtime)
- Pass large data to functions efficiently

## How do you declare a pointer?
You use the `*` symbol:
```cpp
int* ptr; // pointer to an int
```

## How do you use a pointer?
- Use `&` to get the address of a variable
- Use `*` to access the value at that address (dereference)
```cpp
int value = 42;
int* ptr = &value; // ptr stores the address of value
std::cout << *ptr << std::endl; // prints 42
```

## Changing values with pointers
You can change the value of a variable through its pointer:
```cpp
*ptr = 100; // value is now 100
```

## Key things to remember
- Always initialize your pointers (don’t leave them pointing nowhere)
- Use `nullptr` (C++11 and later) to show a pointer doesn’t point to anything
- Be careful: using pointers incorrectly can cause bugs or crashes

Pointers give you lots of control, but use them carefully!


# How Arrays and Pointers Are Related

Arrays and pointers are closely related in C++. In many cases, the name of an array acts like a pointer to its first element.

## What does this mean?
- The name of the array (like `numbers`) is actually the address of the first element.
- You can use a pointer to access array elements.

## Example
```cpp
int numbers[3] = {10, 20, 30};
int* ptr = numbers; // ptr points to numbers[0]
std::cout << *ptr << std::endl;     // prints 10
std::cout << *(ptr + 1) << std::endl; // prints 20
```

You can also use array indexing with pointers:
```cpp
std::cout << ptr[2] << std::endl; // prints 30
```

## Key things to remember
- `numbers` and `&numbers[0]` are the same address
- You can use pointers to loop through arrays
- Changing values through a pointer changes the array

Understanding this relationship helps you write more flexible and powerful C++ code!
</br>
</br>
</br>
</br>


# The Memory Model: Stack vs Heap

When you run a C++ program, your variables and data live in two main places: the **stack** and the **heap**.

- **Stack:**
	- Fast and automatic.
	- Stores variables made inside functions (like local variables and function parameters).
	- When the function ends, these variables disappear automatically.

	**Example:**
	```cpp
	void makeMonster() {
			int health = 100; // health lives on the stack, disappears when function ends
	}
	// health is gone here
	```

- **Heap:**
	- Big and flexible, but you have to manage it yourself.
	- Use `new` to create variables on the heap, and `delete` to clean them up.
	- Data on the heap stays around until you delete it—even after a function ends.

	**Example:**
	```cpp
	struct Character {
			int health;
			int strength;
	};
	Character* hero = new Character; // hero lives on the heap
	// ... use hero ...
	delete hero; // Clean up heap memory when done!
	```

**Summary:**
- Use the stack for short-lived, simple variables.
- Use the heap for data that needs to last longer or is too big for the stack.

### Why do we need pointers?
- **Access dynamic memory:** Only pointers can reach the heap.
- **Build cool data structures:** Linked lists, trees, and more all use pointers.
- **Share and change data:** Pointers let functions work with the same data, not just copies.

### Memory Leaks and Dangling Pointers
- **Memory leak:** You forget to delete memory you made with `new`. The program slowly eats up all your memory!
- **Dangling pointer:** You delete memory, but a pointer still points to it. Using it can crash your program.

**Tip:** Always set pointers to `nullptr` after deleting!

### Scope and Automatic Variables
Variables made inside a function only exist while the function runs. If you want them to last longer, use the heap and pointers.

### Void Pointers (Super Simple)
A `void*` pointer can point to any type of data, but you have to cast it back before using it.
```cpp
float playerHealth = 100.0f;
void* genericPointer = &playerHealth;
float actualHealth = *(static_cast<float*>(genericPointer));
```

### Smart Pointers (Even Smarter!)
Smart pointers (like `std::unique_ptr` and `std::shared_ptr`) help you manage memory automatically. They clean up for you, so you don’t forget!
```cpp
#include <memory>
struct Enemy { int health; };
std::unique_ptr<Enemy> boss = std::make_unique<Enemy>();
boss->health = 200;
// No need to call delete!
```

**Bottom line:**
Pointers give you superpowers in C++, but you have to use them carefully. Smart pointers make life easier and safer!

</br>
</br>
</br>
</br>

# Vectors (Super Simple)

Vectors are like arrays, but better! They can grow or shrink in size as your program runs, and they’re super easy to use in C++.

## Why use vectors?
- You don’t have to decide the size ahead of time
- They automatically manage memory for you
- You get lots of helpful functions (like adding, removing, or finding elements)

## How do you make a vector?
You need to include the vector library:
```cpp
#include <vector>

std::vector<int> numbers; // An empty vector of integers
```
You can also create a vector with some values:
```cpp
std::vector<int> scores = {100, 90, 80};
```

## How do you use a vector?
Add values with `push_back`:
```cpp
numbers.push_back(42); // Adds 42 to the end
```
Access values by index (just like arrays):
```cpp
int first = scores[0]; // 100
scores[1] = 95; // Change the second score
```
Get the size of a vector:
```cpp
size_t n = scores.size();
```
Loop through a vector:
```cpp
for (size_t i = 0; i < scores.size(); ++i) {
	std::cout << scores[i] << std::endl;
}
```
Or use a range-based for loop:
```cpp
for (int score : scores) {
	std::cout << score << std::endl;
}
```

## Key things to remember
- Vectors can grow and shrink as needed
- They manage memory for you (no need for new/delete)
- You need `#include <vector>` to use them

Vectors make handling lists of data in C++ much easier!

# Dynamic Allocation of Vectors

You can also create a vector on the heap using `new`. This gives you a pointer to a vector, which you must remember to delete when done.

```cpp
std::vector<int>* v1 = new std::vector<int>({1, 2, 3});
v1->push_back(4); // Use '->' to access vector methods
std::cout << (*v1)[0] << std::endl; // prints 1
delete v1; // Don't forget to free the memory!
```

Usually, you don't need this—just use normal vectors unless you have a special reason.

# Arrays of References? (Why Not!)

C++ does **not** allow arrays of references. This is because references must always refer to a valid object, and arrays need to be able to change their elements. If you need something similar, use an array of pointers or `std::reference_wrapper`.

**Example with pointers:**
```cpp
int a = 1, b = 2, c = 3;
int* arr[3] = {&a, &b, &c};
std::cout << *arr[0] << *arr[1] << *arr[2]; // prints 123
```

If you try to write:
```cpp
// int& arr[3] = {a, b, c}; // This won't compile!
```
You'll get a compiler error.

# More Vector Tips

- To get the number of elements in a vector, use `.size()`:
  ```cpp
  std::vector<int> nums = {1, 2, 3};
  size_t count = nums.size(); // count is 3
  ```
- To access the first and last elements:
  ```cpp
  std::cout << nums.front(); // prints 1
  std::cout << nums.back();  // prints 3
  ```
- Vectors manage their own memory, so you don't need to use `new` or `delete` for normal use.
</br>
</br>
</br>
</br>

# Strings in C++ (Super Simple)

C++ provides a powerful and easy-to-use `std::string` class for working with text. It’s much safer and more flexible than using character arrays.

## Why use `std::string`?
- Automatically manages memory for you
- Can grow or shrink as needed
- Comes with lots of helpful functions for manipulating text

## How do you use `std::string`?
First, include the string library:
```cpp
#include <string>
```

Create and assign strings:
```cpp
std::string name = "PlayerOne";
std::string greeting = "Hello, " + name + "!";
```

Get the length of a string:
```cpp
size_t len = name.length(); // or name.size()
```

Access individual characters (like an array):
```cpp
char firstLetter = name[0]; // 'P'
name[0] = 'p'; // change to 'playerOne'
```

## Common string operations

- **Concatenate (join) strings:**
  ```cpp
  std::string full = "Level " + std::to_string(2);
  ```

- **Compare strings:**
  ```cpp
  if (name == "PlayerOne") {
      // Do something
  }
  ```

- **Find a substring:**
  ```cpp
  size_t pos = greeting.find("Player");
  if (pos != std::string::npos) {
      // Found!
  }
  ```

- **Extract a substring:**
  ```cpp
  std::string sub = name.substr(0, 6); // "player"
  ```

- **Replace part of a string:**
  ```cpp
  name.replace(0, 6, "Hero"); // "HeroOne"
  ```

- **Convert numbers to strings and back:**
  ```cpp
  int score = 100;
  std::string scoreStr = std::to_string(score);
  int again = std::stoi(scoreStr);
  ```

## Key things to remember
- Always use `std::string` for text in C++ (not char arrays)
- Strings are easy to copy, assign, and compare
- You need `#include <string>` to use them

Strings make handling and manipulating text in C++ simple and safe!