#include <iostream>
#include <iomanip>
using namespace std;

class Property {
public:
    int propertyID;
    double purchasePrice;
    double rentalIncome;

    double calculateROI() {
        return (rentalIncome / purchasePrice) * 100.0;
    }
};

int main() {
    int numProperties;
    cin >> numProperties;

    Property properties[10]; // Max 6 as per constraints, 10 is safe

    for (int i = 0; i < numProperties; i++) {
        cin >> properties[i].propertyID >> properties[i].purchasePrice >> properties[i].rentalIncome;
    }

    for (int i = 0; i < numProperties; i++) {
        double roi = properties[i].calculateROI();
        cout << properties[i].propertyID << " " << fixed << setprecision(2) << roi << "%" << endl;
    }

    return 0;
}
