// Problem Statement

// Dhanya is tasked with writing a program to merge data from two sensors into a single unified dataset. Each sensor produces an array of data readings over time. The goal is to create a program that takes the data arrays from two sensors, merges them, and produces a single sorted array of merged data readings. 

// Can you assist Dhanya in this?

// Input format :
// The first line of input consists of an integer n, representing the number of readings produced by the first sensor.

// The second line consists of an integer m, representing the number of readings produced by the second sensor.

// The third line consists of n space-separated integers, representing the readings from the first sensor.

// The fourth line consists of m space-separated integers, representing the readings from the second sensor.

// Output format :
// The output prints the merged and sorted sensor readings in ascending order, separated by space.



// Refer to the sample output for formatting specifications.

// Code constraints :
// 1 ≤ n, m ≤ 10

// 1 ≤ sensor readings ≤ 100

// Sample test cases :
// Input 1 :
// 3
// 4
// 1 2 8
// 3 5 6 7
// Output 1 :
// 1 2 3 5 6 7 8 
// Input 2 :
// 2
// 3
// 11 13
// 15 23 25
// Output 2 :
// 11 13 15 23 25 

#include <iostream>
using namespace std;


int main(){
    int n,m;
    cin>>n;
    cin>>m;
    
    int arr1[10],arr2[10],merged_arr[20];
    int i,j,k=0;
    
    // first read
    for(i=0;i<n;i++){
        cin>>arr1[i];
    }
    
    // second arr read
    for(i=0;i<m;i++){
        cin>>arr2[i];
    }
 
    for(i=0;i<n;i++){
        merged_arr[k++]=arr1[i];
    }
    
    for(i=0;i<m;i++){
        merged_arr[k++]=arr2[i];
    }
    
    
    //  sorting 
    for(i=0;i<k-1;i++){
        for(j=0;j<k-i-1;j++){
            if(merged_arr[j]>merged_arr[j+1]){
                int temp= merged_arr[j];
                merged_arr[j]=merged_arr[j+1];
                merged_arr[j+1]=temp;
            }
        }
    }
    
    
    // print
    for(i=0;i<k;i++){
        cout<<merged_arr[i]<<" ";
    }

    return 0;
}