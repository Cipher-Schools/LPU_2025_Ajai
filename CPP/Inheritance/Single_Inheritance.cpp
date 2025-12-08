#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    void eat() {
        cout << "Animal eats food\n";
    }
};

// Derived class
class Dog : public Animal {
public:
    void bark() {
        cout << "Dog barks\n";
    }
};

int main() {
    Dog d;
    d.eat();   // Inherited
    d.bark();  // Own function
}
