# Functions: Passing and Returning Values

## Passing Values to a Function

- **By value:** The function receives a copy of the argument. Changes inside the function do not affect the caller.
	- Syntax: `void f(int x)`; call with `f(n);`
	- Pros: Simple, safe; caller data cannot be modified.
	- Cons: Copies can be expensive for large objects.

- **By pointer:** The function receives an address to the object; it can modify the original via dereferencing.
	- Syntax: `void f(int* p)`; call with `f(&n);` and use `*p` inside.
	- Pros: Can indicate optional/null (`nullptr`), can modify caller state.
	- Cons: Requires null checks; a bit more verbose; ownership/aliasing considerations.

- **By reference:** The function receives an alias to the object; it can modify the original directly.
	- Syntax: `void f(int& r)`; call with `f(n);`
	- Pros: Clean syntax, no explicit dereference, no null; efficient (no copy).
	- Cons: Can unexpectedly mutate caller data; cannot bind to `nullptr`.

- **Const reference (read-only):** Pass large objects without copying while preventing mutation.
	- Syntax: `void print(const std::string& s)`; call with `print(name);`
	- Pros: Efficient and safe for read-only access.

- **Rvalue reference (move):** Accept temporaries to move resources instead of copying.
	- Syntax: `void set(std::string&& s)`; call with `set(std::move(name));` or a temporary.
	- Pros: Enables move semantics for performance.

## Returning Values from Functions

- **Built-in or value types:** Return by value for small/cheap-to-copy types (e.g., `int`, `double`) and for objects where move/copy is acceptable.
	- Syntax: `int add(int a, int b) { return a + b; }`

- **Return by pointer:** Return an address when the caller should handle `nullptr` or ownership is explicit.
	- Syntax: `T* find(...);`
	- Notes: Document ownership clearly. Prefer smart pointers for dynamic allocation: `std::unique_ptr<T>` or `std::shared_ptr<T>`.

- **Return by reference:** Return a reference to an existing object when the callee guarantees it will remain valid.
	- Syntax: `T& at(size_t i);`
	- Warning: Never return a reference to a local variable (dangling). Safe sources: static storage, globals, objects owned elsewhere, or elements inside data structures that outlive the call.

- **Const reference return:** Avoids copying while preventing mutation of the returned object.
	- Syntax: `const T& front() const;`
	- Note: Valid only if the referenced object outlives the call.

- **Void return:** Use `void` when no value is produced.
	- Syntax: `void log(const std::string& msg);`

- **NRVO and moves:** Modern compilers perform Named Return Value Optimization (NRVO) and use move semantics, making `return obj;` efficient even for large objects.

## Quick Examples

```cpp
// Pass by value
int square(int x) { return x * x; }

// Pass by pointer (nullable)
void setZero(int* p) {
		if (!p) return; // check for nullptr
		*p = 0;
}

// Pass by (const) reference
void appendExclaim(std::string& s) { s += "!"; }
void printName(const std::string& s) { std::cout << s << "\n"; }

// Return by value with NRVO/move
std::string makeGreeting(std::string name) {
		std::string g = "Hello, " + name;
		return g; // NRVO likely; else move
}

// Return by pointer with ownership
std::unique_ptr<int> makeInt(int v) {
		return std::make_unique<int>(v);
}

// Return by reference to stable storage
int& elementAt(std::vector<int>& v, size_t i) {
		return v.at(i); // reference remains valid while v is alive
}
```

## Guidelines

- Prefer passing by value for small types; use `const T&` for large read-only objects; use `T&` to mutate; use pointers when `nullptr` or optional semantics are needed.
- Prefer returning by value; rely on NRVO/move. Use references only when lifetime is guaranteed. Use smart pointers for dynamic ownership transfer.
- Avoid returning references or pointers to locals; ensure lifetimes are clear and documented.
---

## Function Overloading

- **Function overloading** allows you to define multiple functions with the same name but different parameter lists (number, types, or order of parameters).
- The compiler selects the correct function to call based on the arguments provided (at compile time).
- Overloading cannot be done solely by differing return types.

### Example

```cpp
void print(int x) {
    std::cout << "int: " << x << "\n";
}

void print(double x) {
    std::cout << "double: " << x << "\n";
}

void print(const std::string& s) {
    std::cout << "string: " << s << "\n";
}

// Usage:
print(42);         // Calls print(int)
print(3.14);       // Calls print(double)
print("hello"s);   // Calls print(const std::string&)
```

### Guidelines

- Use overloading to provide intuitive interfaces for related operations.
- Avoid ambiguous overloads (where the compiler cannot decide which function to call).
- Overloading based only on return type is not allowed.
- Default arguments can interact with overloading; use with care.

---
</br>
</br>
</br>
---

# Default Arguments in C++

Default arguments let you specify values for function parameters that are used if the caller omits those arguments. This makes functions more flexible and can reduce the need for multiple overloads.

## What are Default Arguments?

- Default arguments are values assigned in a function's declaration.
- If a call omits an argument, the default is used for that parameter.
- You can call the same function with different numbers of arguments.

### Syntax Example

```cpp
void createZombie(const std::string& name = "Zombie", int health = 100) {
    std::cout << name << " has " << health << " health points.\n";
}

createZombie();                // Uses "Zombie", 100
createZombie("Crawler");       // Uses "Crawler", 100
createZombie("Runner", 150);   // Uses "Runner", 150
```

## Rules for Default Arguments

- **Order matters:** Once a parameter has a default value, all parameters to its right must also have defaults.
- **Declaration vs. definition:** If you separate declaration and definition, specify defaults in the declaration only.
- **Overloading:** Default arguments can reduce the need for multiple overloads.

## Example: Player Settings

```cpp
void initializePlayer(const std::string& name = "Survivor", int lives = 3, int difficulty = 1) {
    std::cout << "Player: " << name << "\n";
    std::cout << "Lives: " << lives << "\n";
    std::cout << "Difficulty Level: " << difficulty << "\n";
}

initializePlayer();                   // "Survivor", 3, 1
initializePlayer("Explorer");         // "Explorer", 3, 1
initializePlayer("Hero", 5);          // "Hero", 5, 1
initializePlayer("Veteran", 2, 3);    // "Veteran", 2, 3
```

## When to Use Default Arguments

- To simplify function calls with common values.
- To reduce the number of overloads.
- For backward compatibility when adding new parameters.

## Best Practices

- Use meaningful, sensible default values.
- Keep defaults consistent with program logic.
- Avoid ambiguous or surprising defaults.
- Document default values and their intent.

## Summary

Default arguments make C++ functions more flexible and concise. They help simplify calls, reduce overloads, and improve code readability and maintainability.