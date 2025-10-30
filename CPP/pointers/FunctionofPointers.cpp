#include <iostream>
using namespace std;

void modifyValue(int **ptr) {
    **ptr += 5;
}

int main() {
    int x = 20;
    int *p = &x;
    int **q = &p;

    modifyValue(q);
    cout << "Updated value of x: " << x;
}

