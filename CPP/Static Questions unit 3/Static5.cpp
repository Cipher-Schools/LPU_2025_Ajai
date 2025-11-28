#include <iostream>
#include <iomanip>
using namespace std;

class DiscountCalculator {
public:
    double amount;

    DiscountCalculator(double a) : amount(a) {}

    void calculateDiscount() {
        double discount = 0;

        if (amount >= 5000) {
            discount = 0.2 * amount;
        }
        else if (amount >= 2000) {
            discount = 0.1 * amount;
        }
        else if (amount >= 1000) {
            discount = 0.05 * amount;
        }

        double finalAmount = amount - discount;
        
        cout << fixed << setprecision(2);
        cout << "Original Amount: " << amount << endl;
        cout << "Discount: " << discount << endl;
        cout << "Final Amount: " << finalAmount << endl;
    }
};


int main() {
    double amount;
    cin >> amount;

    DiscountCalculator calc(amount);
    calc.calculateDiscount();

    return 0;
}