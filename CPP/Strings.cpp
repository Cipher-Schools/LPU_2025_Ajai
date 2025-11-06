#include <iostream>
#include <string>
#include <cctype>   // for toupper, tolower, isalpha, etc.
#include <iomanip>
using namespace std;

/*
------------------------------------------------------
STRINGS IN C++  — Complete Teaching Program
------------------------------------------------------
This single code demonstrates:
1. Declaration & Initialization
2. Input & Output (cin / getline)
3. Important Built-in Functions
4. Iterating over characters
5. Conversion & Case operations
6. Hands-on Problem: Counting vowels, consonants, digits, spaces
------------------------------------------------------
*/

int main() {

    cout << "---------- 1️⃣ What is a String ----------" << endl;

    // String is a sequence of characters, similar to an array but more powerful
    string name = "Ajairaj";
    cout << "Hello, " << name << "!" << endl << endl;

    /*
       Story Tip:
       Think of a string as a necklace of characters — each bead (character)
       is linked together in sequence.
    */

    cout << "---------- 2️⃣ String Input & Output ----------" << endl;

    string fullName;
    cout << "Enter your full name: ";
    getline(cin, fullName);  // reads entire line (spaces included)
    cout << "Welcome, " << fullName << "!" << endl << endl;

    /*
       cin >> name; reads only one word
       getline(cin, name); reads full sentence including spaces
    */

    cout << "---------- 3️⃣ Built-in String Functions ----------" << endl;

    string s1 = "Ajai";
    string s2 = "raj";

    // Append (adds another string)
    s1.append(s2);   // Now s1 = "Ajairaj"
    cout << "Appended string: " << s1 << endl;

    // Length
    cout << "Length: " << s1.length() << endl;

    // Substring
    cout << "Substring (0,4): " << s1.substr(0,4) << endl;

    // Find
    cout << "Find 'raj': " << s1.find("raj") << endl;

    // Replace
    s1.replace(0,4,"Hello");
    cout << "After replace: " << s1 << endl;

    // Erase
    s1.erase(5,3);  // erase 3 chars starting from index 5
    cout << "After erase: " << s1 << endl;

    // Push and Pop
    s1.push_back('!');
    cout << "After push_back: " << s1 << endl;

    s1.pop_back();
    cout << "After pop_back: " << s1 << endl;

    // Compare
    string x = "apple", y = "banana";
    if (x.compare(y) < 0)
        cout << x << " comes before " << y << endl;
    else
        cout << y << " comes before " << x << endl;

    cout << endl;

    cout << "---------- 4️⃣ String Iteration & Character Access ----------" << endl;
    string greet = "Hello";

    cout << "Using indexing: ";
    for (int i = 0; i < greet.size(); i++)
        cout << greet[i] << " ";
    cout << endl;

    cout << "Using range-based for loop: ";
    for (char ch : greet)
        cout << ch << " ";
    cout << endl << endl;

    cout << "---------- 5️⃣ Conversion & Case Operations ----------" << endl;
    string str = "Ajairaj";

    // Convert to uppercase
    for (char &ch : str)
        ch = toupper(ch);
    cout << "Uppercase: " << str << endl;

    // Convert to lowercase
    for (char &ch : str)
        ch = tolower(ch);
    cout << "Lowercase: " << str << endl;

    // Number to string
    int num = 42;
    string snum = to_string(num);
    cout << "to_string Example: " << snum + "7" << endl;  // "427"

    cout << endl;

    cout << "---------- 6️⃣ Hands-on Problem ----------" << endl;
    cout << "Enter a sentence: ";
    string sentence;
    getline(cin, sentence);

    int vowels=0, consonants=0, digits=0, spaces=0;

    for (char ch : sentence) {
        ch = tolower(ch);
        if (isalpha(ch)) {
            if (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
                vowels++;
            else
                consonants++;
        } else if (isdigit(ch))
            digits++;
        else if (isspace(ch))
            spaces++;
    }

    cout << "Vowels: " << vowels << endl;
    cout << "Consonants: " << consonants << endl;
    cout << "Digits: " << digits << endl;
    cout << "Spaces: " << spaces << endl << endl;

    cout << "---------- 7️⃣ Wrap-up ----------" << endl;
    cout << "✅ Difference between char[] and string" << endl;
    cout << "✅ Common string methods" << endl;
    cout << "✅ Iteration and manipulation" << endl;
    cout << "✅ Practice more: reverse, palindrome, frequency count, remove vowels" << endl;

    return 0;
}
