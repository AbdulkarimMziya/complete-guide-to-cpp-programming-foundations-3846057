#include <iostream>
using namespace std;

class Point {
private:
    double x;
    double y;

public:
    // Constructors
    Point(double xVal = 0, double yVal = 0) : x(xVal), y(yVal) {}

    // 1: Overload the '+' operator (member function)
    Point operator+(const Point& p) const {
        return Point(x + p.getX(), y + p.getY());
    }

    // 2: Overload the '==' operator (const member function)
    bool operator==(const Point& p) const {
        return (x == p.getX() && y == p.getY());
    }

    // 3: Overload the '++' operator (prefix version)
    Point& operator++() {
        x++;
        y++;
        return *this;
    }

    // 4: Overload the '++' operator (postfix version)
    Point operator++(int) {
        Point temp = *this;
        x++;
        y++;
        return temp;
    }

    // 5: Overload the '<<' insertion operator (friend global function)
    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        os << '(' << p.getX() << ", " << p.getY() << ')';
        return os;
    }

    // Accessors for testing
    double getX() const { return x; }
    double getY() const { return y; }
};

// ===== Main for Testing =====
int main() {
    Point p1(2, 3);
    Point p2(4, 5);

    cout << "Initial Points: " << endl;
    cout << "p1 = " << p1 << ", p2 = " << p2 << endl;

    // Task 1: Test operator+
    Point p3 = p1 + p2;
    cout << "p3 = p1 + p2: " << p3 << endl;

    // Task 2: Test operator==
    cout << "p1 == p2 ? " << (p1 == p2 ? "True" : "False") << endl;

    // Task 3: Test pre-increment
    ++p1;
    cout << "After ++p1: " << p1 << endl;

    // Task 4: Test post-increment
    p2++;
    cout << "After p2++: " << p2 << endl;


    return 0;
}