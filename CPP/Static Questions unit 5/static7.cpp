#include <iostream>
using namespace std;

 
class Vehicle {
public:
    virtual int getPremium(int age) = 0;
};
 
class Car : public Vehicle {
public:
    int getPremium(int age) {
        int premium = 1000;
        if(age > 3) {
            int extra = (age - 3) * 100;
            premium = premium + extra;
        }
        return premium;
    }
};
 
class Bike : public Vehicle {
public:
    int getPremium(int age) {
        int premium = 500;
        if(age > 2) {
            int extra = (age - 2) * 50;
            premium = premium + extra;
        }
        return premium;
    }
};
 

int main() {
    int type;
    cin >> type;
    int age;
    cin >> age;
    Vehicle* v;
    if(type == 1) {
        v = new Car();
    } else {
        v = new Bike();
    }
    int premium = v->getPremium(age);
    cout << "Premium: " << premium << endl;
    delete v;
    return 0;
}