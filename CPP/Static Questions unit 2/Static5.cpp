#include <iostream>
#include <iomanip>
using namespace std;

class WaterBill {
public:
    int* units; // pointer to store number of units

    WaterBill() {
        units = new int; // dynamically allocate memory
    }

    double calculateBill() {
        int u = *units;
        double total = 0;

        if (u <= 10)
            total = u * 5;
        else if (u <= 20)
            total = (10 * 5) + ((u - 10) * 8);
        else
            total = (10 * 5) + (10 * 8) + ((u - 20) * 10);

        return total;
    }
};

int main() {
    WaterBill bill;
    cin >> *bill.units;  // input through pointer

    cout << fixed << setprecision(0);
    cout << "Total Bill: " << bill.calculateBill();

    return 0;
}
