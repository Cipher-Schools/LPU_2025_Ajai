#include<iostream>
#include<fstream>
using namespace std;


int main(){
    ifstream file("sample.txt");

    string line;
    
    while(getline(file,line)){
        cout<<line<<endl;
    }
     


    file.close();
  
    
 return 0;
}

practice problem

1) write a program to store 5 names in a text file
2) read all from a file and print them
3) count the number of lines in a.txt file.
4) create a log file where every run stores: Program started at: <time>
