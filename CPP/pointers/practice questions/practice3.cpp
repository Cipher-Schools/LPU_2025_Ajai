// Create a class Account with balance.
// Write a member function setBalance() that uses the this pointer to assign a value and another function show() to display it.

#include <iostream>
using namespace std;

class Account {
private:
    float balance;

public:
    // Function to set balance using 'this' pointer
    void setBalance(float balance) {
        this->balance = balance;  // 'this' resolves ambiguity
    }

    // Function to display balance
    void show() {
        cout << "Current Balance: " << balance << endl;
    }
};

int main() {
    Account acc;

    float amount;
    cout << "Enter account balance: ";
    cin >> amount;

    acc.setBalance(amount);
    acc.show();

    return 0;
}
