#include <iostream>
using namespace std;

#define SIZE 7

int hashTable[SIZE];

int h1(int key) {
    return key % SIZE;
}

int h2(int key) {
    return 1 + (key % (SIZE - 1));
}

void init() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

void insert(int key) {
    int index1 = h1(key);
    int index2 = h2(key);

    for (int i = 0; i < SIZE; i++) {
        int newIndex = (index1 + i * index2) % SIZE;
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
