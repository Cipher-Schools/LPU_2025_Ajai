#include <iostream>
#include <iomanip>
using namespace std;
template <typename T>
class MissionTracker {
private:
    T completed;
    T total;
public:
    MissionTracker(T c, T t) : completed(c), total(t) {}
    
    double calculateSuccessRate() {
        return (static_cast<double>(completed) / total) * 100;
    }
};

int main() {
    int completed, total;
    
    cin >> completed;
    cin >> total;
    
    MissionTracker<int> mission(completed, total);
    cout << fixed << setprecision(2);
    cout << "Success rate: " << mission.calculateSuccessRate() << endl;
    
    return 0;
}