#include <iostream>
#include <iomanip>
using namespace std;

class UtilityBill {
public:
    double current_balance;
    double monthly_charge;
    double payment_received;

    void calculate() {
        double late_fee = 0.0;
        if (payment_received < monthly_charge) {
            late_fee = 0.05 * monthly_charge;
            cout << "Late fee: Rs." << fixed << setprecision(2) << late_fee << endl;
        }
        current_balance = current_balance + monthly_charge - payment_received + late_fee;
        cout << "Adjusted balance: Rs." << fixed << setprecision(2) << current_balance;
    }
};

int main() {
    UtilityBill bill;
    UtilityBill* billPtr = &bill;

    cin >> billPtr->current_balance;
    cin >> billPtr->monthly_charge;
    cin >> billPtr->payment_received;

    billPtr->calculate();

    return 0;
}

