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
    int i = 0;

    while (hashTable[(index + i) % SIZE] != -1)
        i++;

    hashTable[(index + i) % SIZE] = key;
}

int main() {
    init();
    insert(10);
    insert(17);
    insert(24);

    for (int i = 0; i < SIZE; i++)
        cout << i << " : " << hashTable[i] << endl;
}
