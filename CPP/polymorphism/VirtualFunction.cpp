#include <iostream>
using namespace std;

class A {
public:
    // Virtual function
    virtual void fun1() {
        cout << "[A::fun1] Base class A\n";
    }

    // Non virtual function
    void fun2() {
        cout << "[A::fun2] Base class A\n";
    }
};

class B : public A {
public:
    // Overrides virtual function
    void fun1() override {
        cout << "[B::fun1] Derived class B\n";
    }

    // Overrides non-virtual but NOT polymorphic
    void fun2() {
        cout << "[B::fun2] Derived class B\n";
    }
};

int main() {

    cout << "=== 1. Base class object ===\n";
    A a;
    a.fun1();   // Base
    a.fun2();   // Base

    cout << "\n=== 2. Derived class object ===\n";
    B b;
    b.fun1();   // Derived
    b.fun2();   // Derived

    cout << "\n=== 3. Base pointer → Base object ===\n";
    A* bp1 = &a;
    bp1->fun1();   // Base (virtual but points to A)
    bp1->fun2();   // Base

    cout << "\n=== 4. Base pointer → Derived object ===\n";
    A* bp2 = &b;
    bp2->fun1();   // Derived (virtual)
    bp2->fun2();   // Base (non-virtual → pointer type decides)

    cout << "\n=== 5. Derived pointer → Derived object ===\n";
    B* dp = &b;
    dp->fun1();   // Derived
    dp->fun2();   // Derived

    return 0;
}