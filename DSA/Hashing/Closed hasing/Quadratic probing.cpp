#include <iostream>
using namespace std;

#define SIZE 7

int hashTable[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

void insert(int key) {
    int index = key % SIZE;

    for (int i = 0; i < SIZE; i++) {
        int newIndex = (index + i * i) % SIZE;
        if (hashTable[newIndex] == -1) {
            hashTable[newIndex] = key;
            return;
        }
    }
}

int main() {
    init();
    insert(10);
    insert(17);
    insert(24);

    for (int i = 0; i < SIZE; i++)
        cout << i << " : " << hashTable[i] << endl;
}
