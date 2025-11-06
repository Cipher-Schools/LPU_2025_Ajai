#include <iostream>
#include <iomanip>
using namespace std;

class Circle {
public:
    float radius;

    void calculate() {
        float area = 3.14 * (this->radius * this->radius);
        float perimeter = 2 * 3.14 * this->radius;

        cout << fixed << setprecision(2);
        cout << "Area: " << area << endl;
        cout << "Perimeter: " << perimeter;
    }
};

int main() {
    Circle c;
    cin >> c.radius;
    c.calculate();
    return 0;
}
