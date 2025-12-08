// Hybrid Inheritance (Multiple + Multilevel)

#include <iostream>
using namespace std;

class A {
public:
    void msgA() { cout << "Class A\n"; }
};

class B : public A {
public:
    void msgB() { cout << "Class B\n"; }
};

class C {
public:
    void msgC() { cout << "Class C\n"; }
};

// D inherits from B and C
class D : public B, public C {
public:
    void msgD() { cout << "Class D\n"; }
};

int main() {
    D obj;
    obj.msgA(); // from A → B → D
    obj.msgB();
    obj.msgC();
    obj.msgD();
}
