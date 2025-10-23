// ==========================
// 📘 BASICS OF C++ REVISION
// Covers:
// 1️⃣ Input / Output
// 2️⃣ Variables & Data Types
// 3️⃣ Operators
// 4️⃣ Conditional Statements
// 5️⃣ Loops (for, while, do-while)
// 6️⃣ Functions (with & without return)
// 7️⃣ Arrays
// 8️⃣ Class & Object
// 9️⃣ Static Members
// ==========================

#include <iostream>
using namespace std;

// ---------- Function Declaration ----------
int add(int a, int b);                // Function with return type
void greet();                         // Function without return type

// ---------- Class Definition ----------
class Student {
public:
    string name;
    int age;
    static int count; // Static Member

    // Constructor
    Student(string n, int a) {
        name = n;
        age = a;
        count++;
    }

    // Member Function
    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }

    // Static Function
    static void showCount() {
        cout << "Total Students: " << count << endl;
    }
};

// Definition of static variable
int Student::count = 0;

// ---------- Function Definitions ----------
int add(int a, int b) {
    return a + b;
}

void greet() {
    cout << "Hello! Welcome to C++ Basics 🚀" << endl;
}

// ---------- Main Function ----------
int main() {

    // 1️⃣ Basic Input / Output
    greet();
    cout << "\n=== Basic I/O ===" << endl;
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "You entered: " << num << endl;

    // 2️⃣ Variables and Operators
    int x = 5, y = 10;
    cout << "\n=== Operators ===" << endl;
    cout << "x + y = " << x + y << endl;
    cout << "x * y = " << x * y << endl;
    cout << "y / x = " << y / x << endl;

    // 3️⃣ Conditional Statements
    cout << "\n=== If-Else ===" << endl;
    if (x < y)
        cout << "y is greater than x" << endl;
    else
        cout << "x is greater or equal" << endl;

    // 4️⃣ Loops
    cout << "\n=== For Loop ===" << endl;
    for (int i = 1; i <= 5; i++)
        cout << i << " ";

    cout << "\n\n=== While Loop ===" << endl;
    int i = 1;
    while (i <= 3) {
        cout << "Hi " << i << endl;
        i++;
    }

    cout << "\n=== Do-While Loop ===" << endl;
    int j = 1;
    do {
        cout << "Count: " << j << endl;
        j++;
    } while (j <= 3);

    // 5️⃣ Functions
    cout << "\n=== Functions ===" << endl;
    cout << "Sum of 5 + 10 = " << add(5, 10) << endl;

    // 6️⃣ Arrays
    cout << "\n=== Arrays ===" << endl;
    int arr[5] = {10, 20, 30, 40, 50};
    cout << "Array elements: ";
    for (int k = 0; k < 5; k++)
        cout << arr[k] << " ";
    cout << endl;

    // 7️⃣ Class & Objects
    cout << "\n=== Class and Object ===" << endl;
    Student s1("Arav", 21);
    Student s2("Ram", 22);
    s1.display();
    s2.display();
    Student::showCount();

    // 8️⃣ Static Member Function Demo
    cout << "\n=== Static Demo ===" << endl;
    Student s3("Kumar", 23);
    Student::showCount();

    cout << "\n Program Completed Successfully!" << endl;

    return 0;
}
