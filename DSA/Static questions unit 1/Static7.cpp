// Problem Statement

// John is tasked with organizing a set of numbers for a competition. He needs to sort the numbers using a simple sorting algorithm and display the state of the list after each iteration. 

// Can you help him sort the numbers and display the intermediate steps, as well as the final sorted list?

// You must solve this problem without using the library's sort function. Use the Selection sort algorithm.

// Input format :
// The first line of input consists of an integer n, representing the number of numbers in the list.

// The second line consists of n space-separated integers representing the numbers to be sorted.

// Output format :
// The first line of output prints the message "Initial array:" followed by the space-separated list of numbers in their original order.

// After each iteration, print the message "After iteration X:" followed by the updated list of numbers.

// Finally, print the message "Final sorted array:" followed by the numbers in ascending order.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 1 ≤ n ≤ 100

// 1 ≤ array elements ≤ 1000

// Sample test cases :
// Input 1 :
// 5
// 657 281 589 605 233 
// Output 1 :
// Initial array: 657 281 589 605 233 
// After iteration 1: 233 281 589 605 657 
// After iteration 2: 233 281 589 605 657 
// After iteration 3: 233 281 589 605 657 
// After iteration 4: 233 281 589 605 657 
// After iteration 5: 233 281 589 605 657 
// Final sorted array: 233 281 589 605 657 
// Input 2 :
// 7
// 538 289 316 283 80 172 163 
// Output 2 :
// Initial array: 538 289 316 283 80 172 163 
// After iteration 1: 80 289 316 283 538 172 163 
// After iteration 2: 80 163 316 283 538 172 289 
// After iteration 3: 80 163 172 283 538 316 289 
// After iteration 4: 80 163 172 283 538 316 289 
// After iteration 5: 80 163 172 283 289 316 538 
// After iteration 6: 80 163 172 283 289 316 538 
// After iteration 7: 80 163 172 283 289 316 538 
// Final sorted array: 80 163 172 283 289 316 538 


#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    cout<<"Initial array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    // selection sort
    for(int i=0;i<n;i++){
     int minIndex=i;
     for(int j=i+1;j<n;j++){
         if(arr[j]<arr[minIndex]){
             minIndex=j;
         }
     }
    // swap
    if(minIndex!=i){
        int temp=arr[i];
        arr[i]=arr[minIndex];
        arr[minIndex]=temp;
    }
    
    cout<<"After iteration "<<i+1<<": ";
    for(int k=0;k<n;k++){
        cout<<arr[k]<< " ";
        
    }
    cout<<endl;
    
    }
    
    cout<<"Final sorted array: " ;
    for(int i : arr){
        cout<<i<<" ";
    }
    cout<<endl;
    
    return 0;
}