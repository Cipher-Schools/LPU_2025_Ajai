// Practice 1 – Bank Account (Static + Non-Static)

#include <iostream>
using namespace std;

class BankAccount {
public:
    float balance;
    static float interestRate;

    BankAccount(float b) {
        balance = b;
    }

    void totalAmount() {
        cout << "Total Amount: " << balance + (balance * interestRate / 100) << endl;
    }
};

float BankAccount::interestRate = 5.0;

int main() {
    BankAccount b1(10000);
    b1.totalAmount();
    return 0;
}
