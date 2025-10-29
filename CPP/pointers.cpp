#include <iostream>
using namespace std;
int main() {
    // int a=10;
    // int *p=&a;
    // int **q=&p;
    // int *ptr=nullptr;  // null pointer
    //  int *ptrn;     //wild pointer, not intialized
    // int  *ptrd = new int(10);
    // delete ptrd;
    // ptrd=nullptr; //fix
    
    
    int a =10;
    float b= 3.123;
    void *ptr;
    
    ptr=&a;
    cout<<"Integer value :"<<*(int*)ptr<<endl;
    
    ptr=&b;
    cout<<"float value:"<<*(float*)ptr<<endl;
    
    1.	Create a void pointer and make it point to an int, a float, and a char — print each using typecasting.
2.	Write a function printValue(void *ptr, char type) that prints value depending on type (‘i’, ‘f’, ‘c’).

    
    // cout<<"value of a:"<<a<<endl;
    // cout<<"address of a:"<<&a<<endl;
    // cout<<" value stored in p (address of a)"<<p<<endl;
    // cout<<"value pointed by p (*p):"<<*p<<endl;
    // cout<<"value of **q:"<<**q<<endl;
    
    

    return 0;
}