#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];

void insert(int key) {
    int index = key % SIZE;
    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;
    }
    hashTable[index] = key;
}

void display() {
    printf("Hash Table Contents:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] == -1)
            printf("%d -> EMPTY\n", i);
        else
            printf("%d -> %d\n", i, hashTable[i]);
    }
}

int main() {
    int n, key;

    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    printf("Enter number of employee records: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter 4-digit key: ");
        scanf("%d", &key);
        insert(key);
    }

    display();
    return 0;
}
