#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<double> powers;
    
    for (int i = 0; i < n; i++) {
        double base, multiplier;
        cin >> base;
        cin >> multiplier;
        
        double power = base * multiplier;
        powers.push_back(power);
    }
    
    sort(powers.begin(), powers.end());
    
    cout << fixed << setprecision(2);
    cout << "Sorted powers:" << endl;
    for (vector<double>::iterator it = powers.begin(); it != powers.end(); ++it) {
        cout << *it << endl;
    }
    
    double maxPower = *max_element(powers.begin(), powers.end());
    cout << "Maximum power: " << maxPower << endl;
    
    return 0;
}