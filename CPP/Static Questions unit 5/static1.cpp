#include <iostream>
#include <iomanip>
using namespace std;


int findMin(int a, int b, int c) {
    int m = a;
    if (b < m) m = b;
    if (c < m) m = c;
    return m;
}

double findMin(double a, double b, double c) {
    double m = a;
    if (b < m) m = b;
    if (c < m) m = c;
    return m;
}



int main() {
    int i1, i2, i3;
    double d1, d2, d3;

    cin >> i1 >> i2 >> i3;
    cin >> d1 >> d2 >> d3;

    cout << "Minimum integer: " << findMin(i1, i2, i3) << '\n';
    cout << fixed << setprecision(2)
         << "Minimum double-point value: " << findMin(d1, d2, d3);

    return 0;
}