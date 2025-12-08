#include <iostream>
using namespace std;

/*
    AMBIGUITY IN MULTIPLE INHERITANCE
    ---------------------------------
    Ambiguity occurs when two parent classes have a function 
    with the SAME NAME and the derived class inherits both.
    The compiler gets confused about which function to call.
*/

class A {
public:
    void show() {
        cout << "Show from Class A\n";
    }
};

class B {
public:
    void show() {
        cout << "Show from Class B\n";
    }
};

// C inherits both A and B → creates ambiguity
class C : public A, public B {

};

int main() {

    C obj;

    // obj.show();  
    // ❌ ERROR: ambiguous call
    // Compiler is confused:
    // Should it call A::show() or B::show()?

    // ✔ Solution: Use SCOPE RESOLUTION to tell the compiler exactly which one to use
    cout << "Calling A::show()\n";
    obj.A::show();   // Calls show() from Class A

    cout << "Calling B::show()\n";
    obj.B::show();   // Calls show() from Class B

    return 0;
}
