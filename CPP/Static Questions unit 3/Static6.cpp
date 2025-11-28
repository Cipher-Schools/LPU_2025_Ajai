#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    string name;
    int grade;
};

int main() {
    ofstream outfile;
    outfile.open("students.txt"); // Open file in text mode
    
    int n;
    cin >> n;
    
    if (n > 20) {
        return 0;
    }
    
    Student student;
    for (int i = 0; i < n; i++) {
        cin.ignore();
        getline(cin, student.name);  // Input name
        cin >> student.grade;
        
        // Write to text file with a delimiter
        outfile << student.name << "|" << student.grade << endl;
    }
    outfile.close();
    
    int position;
    cin >> position;
    
    if (position < 1 || position > n) {
        return 0;
    }
    
    ifstream infile;
    infile.open("students.txt"); // Open file in text mode
    
    string line;
    int currentPosition = 1;
    
    // Read through the file to find the desired position
    while (getline(infile, line) && currentPosition <= position) {
        if (currentPosition == position) {
            // Parse the line to extract name and grade
            size_t delimiterPos = line.find('|');
            if (delimiterPos != string::npos) {
                string name = line.substr(0, delimiterPos);
                int grade = stoi(line.substr(delimiterPos + 1));
                
                cout << name << endl;
                cout << grade << endl;
                break;
            }
        }
        currentPosition++;
    }
    
    infile.close();
    return 0;
}