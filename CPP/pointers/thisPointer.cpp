#include <iostream>
using namespace std;

class Student{
    int id;
    
    public:
        void setId(int id){
            this->id=id;
        }
        
        void show(){
            cout<<"id is :"<<id<<endl;
        }
};


int main() {
    Student s1;
    int id1;
    cout<<"enter the s1 id:"<<endl;
    cin>>id1;
    
    s1.setId(id1);
    s1.show();

    return 0;
}