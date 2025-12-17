#include <iostream>
#include <iomanip>
using namespace std;

class Market {
private:
    double price;
    int quantity;
    double discountThreshold;
    double discountRate;
    
public:
    Market(double p, int q, double dT, double dR) 
        : price(p), quantity(q), discountThreshold(dT), discountRate(dR) {}

    Market operator++() {
        double totalPrice = price * quantity;
        if (totalPrice > discountThreshold) {
            totalPrice -= totalPrice * discountRate;
        }
        cout << "Total price is " << fixed << setprecision(2) << totalPrice << endl;
        return *this;
    }
};

int main() {
    double price, discountThreshold, discountRate;
    int quantity;
    
    cin >> price >> quantity >> discountThreshold >> discountRate;
    
    Market obj(price, quantity, discountThreshold, discountRate);
    ++obj;
    
    return 0;
}
