Constructor Call Order in Inheritance (Optional)

class A {
public:
    A() { cout << "A constructor\n"; }
};

class B : public A {
public:
    B() { cout << "B constructor\n"; }
};

int main() {
    B obj;   
}
