#include <iostream>
#include <iomanip>
using namespace std;

class Watch {
private:
    double price;
    int quantity;
    double discountRate;

public:
    Watch(double p, int q, double d) : price(p), quantity(q), discountRate(d) {
        cout << "Constructor called: Watch added to inventory" << endl;
    }

    ~Watch() {
        cout << "Destructor called: Watch removed from inventory" << endl;
    }

    double calculateTotal() {
        double totalPrice = price * quantity;
        double discount = totalPrice * discountRate;
        return totalPrice - discount;
    }
};

int main() {
    double price, discountRate;
    int quantity;

    cin >> price >> quantity >> discountRate;

    Watch watch(price, quantity, discountRate);
    double totalCost = watch.calculateTotal();

    cout << fixed << setprecision(2) << "Total cost after discount: " << totalCost << endl;

    return 0;
}
