#include <iostream>
#include <iomanip>
using namespace std;

class Vehicle {
protected:
    double fuelEfficiency;
    double maximumCapacity;

public:
    Vehicle(double efficiency, double capacity) {
        fuelEfficiency = efficiency;
        maximumCapacity = capacity;
    }
};

class Car : public Vehicle {
protected:
    double maxRange; 

public:
    Car(double efficiency, double capacity) : Vehicle(efficiency, capacity) {
        maxRange = fuelEfficiency * maximumCapacity;
    }

    void calculateMaxRange() {
        cout << "Maximum Range: " << fixed << setprecision(2) << maxRange << " km" << endl;
    }
};

class EmilyCar : public Car {
public:
    EmilyCar(double efficiency, double capacity) : Car(efficiency, capacity) {}

    void calculatePayloadCapacity() {
        double payloadFactor = 0.8;
        double payloadCapacity = payloadFactor * maximumCapacity; 
    
        double totalWeight = payloadCapacity + (fuelEfficiency * maximumCapacity); 
        cout << "Payload Capacity: " << fixed << setprecision(2) << payloadCapacity << " kg" << endl;
        cout << "Fully loaded Weight: " << fixed << setprecision(2) << totalWeight << " kg" << endl;
    }
};

int main() {
    double efficiency, capacity;
    cin >> efficiency >> capacity;

    EmilyCar emilysCar(efficiency, capacity);

    emilysCar.calculateMaxRange();
    emilysCar.calculatePayloadCapacity();

    return 0;
}