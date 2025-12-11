# C++ Data Types Overview


## Integer Types
Used to store whole numbers. Common types include `int` for general integer values and `char` for text characters encoded as bytes, which can also be interpreted as small integers.

## Boolean Type (`bool`)

C++ supports a `bool` type to represent Boolean values, which can be either `true` or `false`.

[!NOTE]
In C++, `true` is any non-zero value, and `false` is zero.


This type is useful for conditional statements and controlling program flow.



## Floating-Point Types
Used to store real numbers with decimal points. There are several types of floating-point numbers in C++:

### Types of Floating-Point Numbers
- **float**: Single precision floating-point type with a smaller range and precision. It is less computationally expensive.
- **double**: Double precision floating-point type with a larger range and precision compared to float. It is more computationally expensive.
- **long double**: Extends the range and precision even further than double, useful for scenarios requiring extreme precision but with increased computational cost.

**Usage:** Floats are entered with a decimal point and at least one digit to the right. For example, `23.0f` or `0.0f`. Doubles are the default floating-point type and are written without the trailing `f`.

## Pointers
Variables that store memory addresses. They allow you to work directly with memory and manipulate data structures efficiently.


## C++ Qualifiers

### What are Qualifiers?
Qualifiers are special keywords in C++ that add extra rules or properties to variables, functions, and data types. They help you control how your code behaves. Here are the most common ones:

---

### `const` Qualifier
Declares variables that cannot be changed after they’re set. This helps prevent accidental changes to important values.

**Example:**
```cpp
const int maxHealth = 100; // maxHealth cannot be changed
```
Trying to change `maxHealth` later will cause an error.

You can also use `const` with function parameters to make sure the function doesn’t change the input:
```cpp
void displayScore(const std::string& playerName) {
	std::cout << "Player: " << playerName << std::endl;
}
```

---

### `volatile` Qualifier
Tells the compiler that a variable might change unexpectedly (for example, by hardware or another thread). The compiler won’t optimize away reads/writes to this variable.

**Example:**
```cpp
volatile int enemyStatus;
```

---

### `mutable` Qualifier
Lets you change a member variable even if the object is marked as `const`. Useful for keeping track of internal state.

**Example:**
```cpp
class Player {
public:
	void updateScore() const {
		++score;
	}
private:
	mutable int score = 0;
};
```

---

### `inline` Qualifier
Suggests to the compiler to copy the function’s code wherever it’s used, instead of making a regular function call. Good for small, simple functions.

**Example:**
```cpp
inline int calculateDamage(int baseDamage, int modifier) {
	return baseDamage + modifier;
}
```

---

### `constexpr` Qualifier
Means the value or function result can be calculated at compile time (before the program runs). This can make your code faster and safer.

**Example:**
```cpp
constexpr int maxLevel = 99;
constexpr int calculateExperience(int level) {
	return level * level * 100;
}
```

---

### Combining Qualifiers
You can use more than one qualifier together for extra control:
```cpp
constexpr const int maxSpeed = 100;
```

---

### Honorable Mention: `static` Specifier
Not a qualifier, but very important! `static` changes how variables and functions behave:

- **Static local variables** keep their value between function calls.
	```cpp
	void generateUniqueID() {
		static int id = 0;
		++id;
		std::cout << "Generated ID: " << id << std::endl;
	}
	```
- **Static class members** are shared by all objects of the class.
	```cpp
	class Enemy {
	public:
		static int enemyCount;
		Enemy() { ++enemyCount; }
		static void showEnemyCount() {
			std::cout << "Total Enemies: " << enemyCount << std::endl;
		}
	};
	int Enemy::enemyCount = 0;
	```
- **Static functions** in a file can only be used in that file (internal linkage).

---

### Summary
Qualifiers like `const`, `volatile`, `mutable`, `inline`, and `constexpr` help you write safer and more efficient C++ code. You’ll see these used often as you learn more about C++!


## Type Aliases

Type aliases allow you to create an alias for an existing type, making complex type definitions more manageable and improving code readability.

### Using Keyword
Introduced in C++11, the `using` keyword serves the same purpose as `typedef` but with improved syntax and capabilities. It is preferred over `typedef` for modern C++ development.

**Syntax:**
```cpp
using Score = unsigned long;
```
This creates an alias `Score` for the type `unsigned long`.

### Template Aliases
The `using` keyword supports template aliases, which `typedef` does not. This makes it more versatile and suitable for modern C++ programming.

**Example:**
If you want to create an alias for a high score type in a video game:
```cpp
using Score = unsigned long;
Score highScore;
Score player1_score;
```


### Advantages
- The `using` keyword enhances readability and maintainability of the code.
- It clearly separates the alias from the type definition, making it easier to understand at a glance.


## Enum Classes (Super Simple)

Enum classes are a way to group related constant values together. They make your code easier to read and help prevent mistakes.

### Why use enum classes?
- Keeps your code organized
- Stops you from mixing up values by accident
- Enum values are only available through the enum class, so you don’t get name clashes

### How do you write an enum class?
Here’s a basic example:
```cpp
enum class Color {
	Red,
	Green,
	Blue
};
```
This creates a new type called `Color` with three possible values: `Red`, `Green`, and `Blue`.

### How do you use an enum class?
You use the scope operator `::` to access the values:
```cpp
Color myColor = Color::Green;
if (myColor == Color::Green) {
	std::cout << "It's green!" << std::endl;
}
```

### Another example
```cpp
enum class GameState {
	Playing,
	Paused,
	GameOver
};

GameState state = GameState::Playing;
if (state == GameState::GameOver) {
	std::cout << "Game Over!" << std::endl;
}
```

### Key things to remember
- Enum classes don’t automatically turn into numbers (no accidental bugs)
- You can choose the underlying type if you want:
```cpp
enum class WeaponType : unsigned int {
	Sword = 1,
	Bow = 2,
	Staff = 3
};
```

Enum classes make your code safer and easier to understand!


## Structs

Structs are a way to group different pieces of data together under one name. They’re great for organizing related information, like stats for a player or properties of an object.

### Why use structs?
- Keep related data together
- Make your code easier to read and manage

### How do you write a struct?
Here’s a basic example:
```cpp
struct Player {
	std::string name;
	int health;
	int score;
};
```
This creates a new type called `Player` with three members: `name`, `health`, and `score`.

### How do you use a struct?
You can create a variable of your struct type and set its values:
```cpp
Player hero;
hero.name = "Hero";
hero.health = 100;
hero.score = 0;
```

You can also create and initialize a struct in one line:
```cpp
Player villain = {"Villain", 80, 10};
```

### Key things to remember
- Structs group different types of data together
- You access members using the dot `.` operator
- Structs are public by default (all members can be accessed directly)

Structs make your code neat and organized!


## Type Inference with auto

Type inference lets the compiler figure out the type of a variable for you. In C++, you do this with the `auto` keyword. This makes your code shorter and easier to read, especially when the type is long or complicated.

### Why use `auto`?
- Saves you from writing out long type names
- Makes your code easier to read
- Lets you focus on what your code does, not just the types

### How do you use `auto`?
Just use the `auto` keyword when declaring a variable:
```cpp
auto x = 5;           // x is an int
auto name = "Hero";  // name is a const char*
auto score = 99.5;    // score is a double
```

### Example with containers
`auto` is super useful with things like vectors:
```cpp
#include <vector>
std::vector<int> numbers = {1, 2, 3};
auto it = numbers.begin(); // it is a vector<int>::iterator
```

### Key things to remember
- The compiler decides the type based on the value you assign
- You still need to know what type you expect, but you don’t have to write it out

Type inference with `auto` helps keep your code clean and simple!


