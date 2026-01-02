#include <iostream>
using namespace std;
 

class Library {
public:
    virtual int getFine(int days) = 0;
};
 
class Book : public Library {
public:
    int getFine(int days) {
        int fine = 0;
        if(days > 5) {
            fine = (days - 5) * 2;
        }
        return fine;
    }
};
 
class Magazine : public Library {
public:
    int getFine(int days) {
        int fine = 0;
        if(days > 2) {
            fine = (days - 2) * 1;
        }
        return fine;
    }
};
 

int main() {
    int type;
    cin >> type;
    int days;
    cin >> days;
    Library* item;
    if(type == 1) {
        item = new Book();
    } else {
        item = new Magazine();
    }
    int fine = item->getFine(days);
    cout << "Fine: " << fine << endl;
    delete item;
    return 0;
}
 