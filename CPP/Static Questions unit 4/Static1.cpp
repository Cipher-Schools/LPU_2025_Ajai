#include <iostream>
#include <iomanip>
using namespace std;

class P {
protected:
    double v; 
    double i; 

public:
    P(double voltage, double current) {
        v = voltage;
        i = current;
    }

    double calcPower() {
        return v * i;
    }
};

class PE : public P {
private:
    double e; 

public:
    PE(double voltage, double current, double efficiency) : P(voltage, current){
        e = efficiency;
    }

    double calcUsefulPower() {
        return calcPower() * e;
    }

    double calcWastedPower() {
        return calcPower() * (1.0 - e);
    }
};

int main() {
    double voltage, current, efficiency;
    cin >> voltage;
    cin >> current;
    cin >> efficiency;

    PE device(voltage, current, efficiency);
    cout << fixed << setprecision(1);
    cout << "Power: " << device.calcPower() << "W" << endl;
    cout << "Useful Output Power: " << device.calcUsefulPower() << "W" << endl;
    cout << "Wasted Power: " << device.calcWastedPower() << "W" ;

    return 0;
}