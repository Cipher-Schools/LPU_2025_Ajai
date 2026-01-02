#include <iostream>
using namespace std;

class Student {
public:
    int marks;
    Student* friend_ptr;
    
    Student(int m) {
        marks = m;
        friend_ptr = NULL;
    }
    
    void setFriend(Student* f) {
        friend_ptr = f;
    }
    
    int getTotalMarks() {
        int total = marks;
        
        if(friend_ptr != NULL) {
            total = total + friend_ptr->marks;
        }
        
        return total;
    }
};

int main() {
    int marks1;
    cin >> marks1;
    
    Student* s1 = new Student(marks1);
    
    int hasFriend;
    cin >> hasFriend;
    
    if(hasFriend == 1) {
        int marks2;
        cin >> marks2;
        
        Student* s2 = new Student(marks2);
        s1->setFriend(s2);
        
        int diff = marks1 - marks2;
        if(diff < 0) {
            diff = diff * -1;
        }
        
        cout << "Difference: " << diff << endl;
        
        if(marks1 > marks2) {
            cout << "Student 1 higher" << endl;
        } else if(marks2 > marks1) {
            cout << "Student 2 higher" << endl;
        } else {
            cout << "Both equal" << endl;
        }
        
        delete s2;
    } else {
        cout << "No friend" << endl;
    }
    
    delete s1;
    
    return 0;
}