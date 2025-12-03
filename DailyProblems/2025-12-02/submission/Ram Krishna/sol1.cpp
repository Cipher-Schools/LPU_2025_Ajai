#include<iostream>
using namespace std;
int fib(int n){
    if(n==2 || n==1){
        return 1;
    }
    else if(n==0){
        return 0;
    }
    return fib(n-1) + fib(n-2);
}
int main(){
    int n;
    cout<<"Enter the number of terms: ";
    cin>>n;
    int d= fib(n);
    cout<<d<<" ";
    return 0;
}