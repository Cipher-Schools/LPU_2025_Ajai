// Create a class Book with members title and price.
// Store information for n books using an array of objects.
// Display all books whose price > 500.


#include <iostream>
using namespace std;

class Book {
private:
    string title;
    float price;

public:
    // Function to input book details
    void getData() {
        cout << "Enter book title: ";
        cin.ignore();          // to ignore newline left in the input buffer
        getline(cin, title);
        cout << "Enter book price: ";
        cin >> price;
    }

    // Function to display book details
    void display() {
        cout << "Title: " << title << ", Price: " << price << endl;
    }

    // Function to check price > 500
    bool isExpensive() {
        return price > 500;
    }
};

int main() {
    int n;
    cout << "Enter number of books: ";
    cin >> n;

    Book books[n];  // Array of objects

    // Input details for all books
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for book " << i + 1 << ":\n";
        books[i].getData();
    }

    // Display books with price > 500
    cout << "\nBooks with price greater than 500:\n";
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (books[i].isExpensive()) {
            books[i].display();
            found = true;
        }
    }

    if (!found)
        cout << "No books with price greater than 500.\n";

    return 0;
}
