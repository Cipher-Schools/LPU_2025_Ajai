#include <iostream>
#include <stdexcept>
#include <iomanip>
using namespace std;


void calculateStrength(double force, double distance) {
    if (force < 0) {
        throw invalid_argument("Negative force");
    }
    cout << fixed << setprecision(2);
    cout << "Strength value: " << force * distance << endl;
}

// New function that handles rethrow
void handleStrength(double force, double distance) {
    try {
        calculateStrength(force, distance);
    }
    catch (invalid_argument& e) {
        cout << "Error detected in handleStrength" << endl;
        throw;  // Rethrow the exception to the caller
    }
}



int main() {
    double force, distance;
    
    cin >> force;
    cin >> distance;
    
    try {
        handleStrength(force, distance);
    }
    catch (invalid_argument& e) {
        cout << "Caught in main: " << e.what() << endl;
    }
    
    return 0;
}