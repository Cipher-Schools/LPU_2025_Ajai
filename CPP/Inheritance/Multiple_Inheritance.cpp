#include <iostream>
using namespace std;

class A {
public:
    void msgA() { cout << "Message from A\n"; }
};

class B {
public:
    void msgB() { cout << "Message from B\n"; }
};

// C inherits from A and B
class C : public A, public B {
public:
    void msgC() { cout << "Message from C\n"; }
};

int main() {
    C obj;
    obj.msgA();
    obj.msgB();
    obj.msgC();
}
