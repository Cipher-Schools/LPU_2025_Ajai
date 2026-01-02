#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;


double calculateStrength(double thickness, double length) {
    return thickness * length;
}

double findMinimum(vector<double> strengths) {
    double minVal = strengths[0];
    for (int i = 1; i < strengths.size(); i++) {
        if (strengths[i] < minVal) {
            minVal = strengths[i];
        }
    }
    return minVal;
}

int main() {
    int n;
    cin >> n;
    
    vector<double> strengths;
    
    for (int i = 0; i < n; i++) {
        double thickness, length;
        cin >> thickness;
        cin >> length;
        
        double strength = calculateStrength(thickness, length);
        strengths.push_back(strength);
    }
    
    cout << fixed << setprecision(2);
    cout << "Web strengths:" << endl;
    for (int i = 0; i < strengths.size(); i++) {
        cout << strengths[i] << endl;
    }
    
    double minStrength = findMinimum(strengths);
    cout << "Minimum strength: " << minStrength << endl;
    
    return 0;
}