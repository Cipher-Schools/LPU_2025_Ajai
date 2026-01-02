#include <iostream>
#include <list>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    list<double> times;
    
    for (int i = 0; i < n; i++) {
        double distance, velocity;
        cin >> distance;
        cin >> velocity;
        
        double time = distance / velocity;
        times.push_back(time);
    }
    
    cout << fixed << setprecision(2);
    cout << "Flight times:" << endl;
    for (list<double>::iterator it = times.begin(); it != times.end(); ++it) {
        cout << *it << endl;
    }
    
    return 0;
}