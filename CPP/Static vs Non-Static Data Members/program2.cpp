// Static Member Function
#include <iostream>
using namespace std;

class Account {
private:
    static int totalAccounts;
public:
    Account() { totalAccounts++; }

    static void showCount() {
        cout << "Total Accounts Created: " << totalAccounts << endl;
    }
};

int Account::totalAccounts = 0;

int main() {
    Account a1, a2;
    Account::showCount();
    return 0;
}
