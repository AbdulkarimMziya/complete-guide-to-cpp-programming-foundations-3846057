# If Statements in C++ (Super Simple)

`if` statements let your program make decisions. They check a condition, and if it's true, they run a block of code.

## Basic Syntax

```cpp
if (condition) {
    // code runs if condition is true
}
```

## Example

```cpp
int score = 80;
if (score > 50) {
    std::cout << "You passed!" << std::endl;
}
```

## if-else

Use `else` to run code when the condition is false:

```cpp
if (score > 50) {
    std::cout << "You passed!" << std::endl;
} else {
    std::cout << "Try again!" << std::endl;
}
```

## else if

Check multiple conditions in order:

```cpp
if (score > 90) {
    std::cout << "Excellent!" << std::endl;
} else if (score > 50) {
    std::cout << "You passed!" << std::endl;
} else {
    std::cout << "Try again!" << std::endl;
}
```

## Key Points

- The condition must be something that evaluates to `true` or `false`.
- Use `{}` braces for blocks, even for one line (good habit).
- You can nest `if` statements inside each other.

**Tip:** Always use `==` for comparison, not `=` (which is assignment).

```cpp
if (lives == 0) { // correct
    // ...
}
```
</br>
</br>
</br>

# Ternary Statements in C++ (Super Simple)

A ternary statement is a shortcut for simple `if-else` decisions. It lets you choose between two values based on a condition, all in one line.

## Basic Syntax

```cpp
condition ? value_if_true : value_if_false;
```

## Example

```cpp
int score = 80;
std::string result = (score > 50) ? "You passed!" : "Try again!";
std::cout << result << std::endl;
```

## How it works

- If the condition is true, the first value is used.
- If the condition is false, the second value is used.

## When to use

- For quick, simple choices between two values.
- Not for complex logic or multiple statements.

**Tip:** The ternary operator is also called the "conditional operator."
</br>
</br>
</br>
</br>

# Switch Statements in C++ (Super Simple)

A `switch` statement lets you choose between many options based on the value of a variable. It's like a cleaner way to write lots of `if-else` statements when checking the same variable.

## Basic Syntax

```cpp
switch (expression) {
    case value1:
        // code if expression == value1
        break;
    case value2:
        // code if expression == value2
        break;
    // more cases...
    default:
        // code if no case matches
}
```

## Example

```cpp
int level = 2;
switch (level) {
    case 1:
        std::cout << "Easy mode" << std::endl;
        break;
    case 2:
        std::cout << "Normal mode" << std::endl;
        break;
    case 3:
        std::cout << "Hard mode" << std::endl;
        break;
    default:
        std::cout << "Unknown mode" << std::endl;
}
```

## Key Points

- The `expression` must be an integer, `char`, or enum (not a string or float).
- Each `case` checks for a specific value.
- Use `break;` to stop after a match—otherwise, code "falls through" to the next case.
- The `default` case runs if no other case matches (like an "else").

**Tip:** Always use `break;` unless you want to intentionally fall through to the next case.
</br>
</br>
</br>
</br>


# Loops in C++ (Super Simple)

Loops let you repeat actions in your code. There are several types of loops in C++: `for`, `while`, and `do-while`.

## For Loop

A `for` loop is great when you know how many times you want to repeat something.

```cpp
for (int i = 0; i < 5; ++i) {
    std::cout << "i is " << i << std::endl;
}
```

## While Loop

A `while` loop repeats as long as a condition is true.

```cpp
int count = 0;
while (count < 3) {
    std::cout << "count is " << count << std::endl;
    ++count;
}
```

## Do-While Loop

A `do-while` loop always runs at least once.

```cpp
int num = 0;
do {
    std::cout << "num is " << num << std::endl;
    ++num;
} while (num < 2);
```

# Looping Through Vectors

Vectors are super easy to loop through!

## Using a for loop with indices

```cpp
std::vector<int> scores = {100, 90, 80};
for (size_t i = 0; i < scores.size(); ++i) {
    std::cout << scores[i] << std::endl;
}
```

## Using a range-based for loop

```cpp
for (int score : scores) {
    std::cout << score << std::endl;
}
```

## Using vector methods `begin()` and `end()`

You can use iterators to loop through a vector:

```cpp
for (auto it = scores.begin(); it != scores.end(); ++it) {
    std::cout << *it << std::endl;
}
```

- `begin()` returns an iterator to the first element.
- `end()` returns an iterator just past the last element.

**Tip:** Iterators are like pointers that let you move through the vector.

# Key Things to Remember

- Use `for` loops for counting or when you know how many times to repeat.
- Use `while` loops when you want to repeat until something changes.
- Use range-based for loops or iterators for easy vector access.
</br>
</br>


# Why Use `const auto&` in Range-Based For Loops?

When looping through a vector (or any container), you can use different ways to access each element:

- `for (auto item : container)` — makes a copy of each element.
- `for (auto& item : container)` — gives you a reference to each element (no copy).
- `for (const auto& item : container)` — gives you a read-only reference (no copy, can't modify).

**Why does this matter?**

- If your objects are large, copying them is slow and uses more memory.
- If you only need to read the elements (not change them), `const auto&` is safest and fastest.

**Example:**

```cpp
std::vector<std::string> names = {"Alice", "Bob", "Charlie"};

// Best practice for read-only access:
for (const auto& name : names) {
    std::cout << name << std::endl;
}
```

- Use `auto&` if you want to modify the elements.
- Use `const auto&` for efficient, read-only access.
- Avoid plain `auto` unless the objects are very small and copying is cheap.