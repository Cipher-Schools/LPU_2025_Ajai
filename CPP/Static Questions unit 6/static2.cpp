#include <iostream>
#include <iomanip>
using namespace std;

template <typename T>
T calculateEnergy(T mass, T velocity) {
    return mass * velocity * velocity;
}

int main() {
    double mass, velocity;
    
    cin >> mass;
    cin >> velocity;
    
    double energy = calculateEnergy(mass, velocity);
    cout << fixed << setprecision(2);
    cout << "Hammer energy: " << energy << endl;
    
    return 0;
}