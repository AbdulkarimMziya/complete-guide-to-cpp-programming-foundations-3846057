## Dummy-Proof C++ Classes, Operator Overloading, and Inheritance Manual

This guide covers the basics and more advanced topics for C++ classes, operator overloading, and inheritance/polymorphism, with simple explanations and code examples.

---

### 1. Class Basics
Start with the `class` keyword, a name, and curly brackets:
```cpp
class Inventory {
    // class contents go here
};
```

**Access Specifiers:**
- `private:` hides data from outside.
- `public:` lets you access functions/data from outside.

---

### 2. Data Members
Add variables inside your class:
```cpp
class Inventory {
private:
    std::vector<std::string> items;
    int capacity;
};
```

---

### 3. Member Functions (Setters, Getters, Overloading)
Add functions to interact with your data:
```cpp
class Inventory {
    // ...existing code...
public:
    void setCapacity(int newCapacity) { capacity = newCapacity; }
    int getCapacity() const { return capacity; }
    void print() const;
    void print(int count) const; // Overloaded
};
```

---

### 4. Constructors and Destructors
**Constructor:** Sets up your object.
**Destructor:** Cleans up when your object is deleted.
```cpp
class Inventory {
    // ...existing code...
public:
    Inventory() : capacity(0) {}
    Inventory(int cap) : capacity(cap) {}
    ~Inventory() {}
};
```
**Order:** Constructors run from base to derived. Destructors run from derived to base.

---

### 5. Objects as Data Members, Parameters, and Return Values
You can use objects inside other classes, as function parameters, or return them:
```cpp
class Player {
    Inventory bag;
};
void useInventory(Inventory inv);
Inventory makeInventory();
```

---

### 6. Static Members, Const Member Functions, this Pointer, Friend Functions

- **Static member:** Shared by all objects of the class. Only one copy exists, no matter how many objects you make.
- **Const member function:** Promises not to change any data members of the object. Safe to call on const objects.
- **this pointer:** A special pointer available inside class methods that points to the object calling the method.
- **Friend function:** A function that is not a member of the class but can access its private and protected members.

```cpp
class Example {
    static int count; // static member
    int value;
public:
    void setValue(int v) { value = v; }
    int getValue() const { return value; } // const member function
    void showAddress() { std::cout << this << std::endl; } // this pointer
    friend void showValue(const Example& e); // friend function
};
```

---

### 7. Operator Overloading
**Member vs Global:**
- Member: `Inventory& operator+=(const std::string& item);`
- Global: `Inventory operator+(const Inventory& a, const Inventory& b);`

**Unary Example:**
```cpp
Inventory& operator++(); // member
```
**Binary Example:**
```cpp
Inventory operator+(const Inventory& other) const; // member
friend Inventory operator+(const Inventory& a, const Inventory& b); // global


// Example usage:
Inventory a, b, c;
c = a + b; // Uses overloaded +

// Summary:
// - Unary operators work on one object (e.g., ++a)
// - Binary operators work on two objects (e.g., a + b)
// - You can overload operators as member or global functions depending on your needs
```


## Header Files in C++

### What is a Header File?
- A header file (`.h` or `.hpp`) contains class declarations, function prototypes, and constants.
- It helps organize code and allows sharing declarations between multiple `.cpp` files.

---

### Example: Splitting a Class into Header and Implementation

#### Inventory.h (Header File)
```cpp
#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <string>

class Inventory {
public:
    Inventory(int cap);
    void addItem(const std::string& item);
    int getItemCount() const;
private:
    std::vector<std::string> items;
    int capacity;
};

#endif // INVENTORY_H
```

#### Inventory.cpp (Implementation File)
```cpp
#include "Inventory.h"

Inventory::Inventory(int cap) : capacity(cap) {}

void Inventory::addItem(const std::string& item) {
    if (items.size() < capacity)
        items.push_back(item);
}

int Inventory::getItemCount() const {
    return items.size();
}
```

---

### How to Use
- Include the header in your main file:
    ```cpp
    #include "Inventory.h"
    ```
- This keeps your code organized and makes it easier to maintain.

## Basics of Using Operator Overloading

### Operator Types
- Operators can be:
    - **Unary**: Work on one object (e.g., `-a`, `++a`)
    - **Binary**: Work on two objects (e.g., `a + b`, `a -= b`)
    - **Ternary**: Work on three objects (only the `?:` operator, which cannot be overloaded)
- Most operator overloading in classes is for **binary operators**.

### Return Type
- Every overloaded operator must return a value.
- For binary operators, the return type cannot be `void`.
- Often, the operator returns a reference to the object so you can chain operations.

### Syntax
- Use the `operator` keyword followed by the operator symbol.
- Example for `+=`:
    ```cpp
    Inventory& operator+=(const Inventory& other);
    ```
- Example for `[]`:
    ```cpp
    std::string& operator[](int index);
    ```

### Implementation
- Declare the operator in the header file.
- Define its behavior in the implementation file.
- Make sure the return type and logic match the operator’s purpose.

**Header (Inventory.h):**
```cpp
class Inventory {
public:
        Inventory& operator+=(const Inventory& other);
        Inventory& operator-=(const Inventory& other);
        std::string& operator[](int index);
        // ... other members ...
};
```

**Implementation (Inventory.cpp):**
```cpp
Inventory& Inventory::operator+=(const Inventory& other) {
        // Add items from other to this inventory
        // (implementation details)
        return *this;
}

Inventory& Inventory::operator-=(const Inventory& other) {
        // Remove items found in other from this inventory
        // (implementation details)
        return *this;
}

std::string& Inventory::operator[](int index) {
        return items[index];
}
```

### Example Usage in Main
```cpp
Inventory a, b;
a += b;           // Uses overloaded +=
a -= b;           // Uses overloaded -=
std::string item = a[0]; // Uses overloaded []
```

**Summary:**  
Operator overloading lets you use natural syntax (like `+=` or `[]`) with your own classes, making your code easier to read and use.

## Inheritance and Polymorphism

### Inheritance
- Inheritance lets you create a new class (child/derived) based on an existing class (parent/base).
- The child class gets all the data and functions from the parent, and can add or change features.

**Example:**
```cpp
class Animal {
public:
    void speak() { std::cout << "Animal sound" << std::endl; }
};

class Dog : public Animal {
public:
    void bark() { std::cout << "Woof!" << std::endl; }
};

// Usage:
Dog d;
d.speak(); // from Animal
d.bark();  // from Dog
```

---

### Polymorphism
- Polymorphism lets you use a base class pointer or reference to call functions in derived classes.
- Use `virtual` in the base class to allow derived classes to override functions.

**Example:**
```cpp
class Animal {
public:
    virtual void speak() { std::cout << "Animal sound" << std::endl; }
};

class Cat : public Animal {
public:
    void speak() override { std::cout << "Meow!" << std::endl; }
};

// Usage:
Animal* a = new Cat();
a->speak(); // prints "Meow!" because of polymorphism
delete a;
```

---

**Summary:**
- Inheritance lets you reuse and extend code.
- Polymorphism lets you write flexible code that works with different types of objects using a common interface.

## Abstraction

- Abstraction means showing only the important details and hiding the complex parts.
- In C++, you use abstract classes (with at least one pure virtual function) to define a common interface for related classes.

**Example:**
```cpp
class Shape {
public:
    virtual double area() const = 0; // pure virtual function
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override { return 3.14159 * radius * radius; }
};

// Usage:
// Shape s; // Error: can't create an object of abstract class
Circle c(2.0);
double a = c.area(); // OK
```

**Summary:**
- Abstraction lets you focus on what an object does, not how it does it. It helps you design cleaner and more flexible code.