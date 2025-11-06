#include <iostream>
using namespace std;

class Rectangle {
public:
    int length;
    int width;
};

int main() {
    Rectangle rect;
    int factor;

    cin >> rect.length >> rect.width;
    cin >> factor;

    int Rectangle::*ptr = &Rectangle::length;  // pointer to data member 'length'

    rect.*ptr = rect.*ptr * factor;  // update length using pointer to data member

    cout << rect.length;
    return 0;
}
