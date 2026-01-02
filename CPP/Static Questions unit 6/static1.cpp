#include <iostream>
#include <stdexcept>
#include <iomanip>
using namespace std;

int main() {
    double voltage, resistance;
    
    cin >> voltage;
    cin >> resistance;
    
    try {
        if (resistance <= 0) {
            throw invalid_argument("Invalid resistance");
        }
        
        double power = (voltage * voltage) / resistance;
        cout << fixed << setprecision(2);
        cout << "Power output: " << power << endl;
    }
    catch (invalid_argument& e) {
        cout << e.what() << endl;
    }
    
    return 0;
}