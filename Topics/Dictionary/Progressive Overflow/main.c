#include <stdio.h>

#define M 7          // primary table size
#define O 5          // overflow area size
#define EMPTY -1

int table[M + O];    // combined table

// Hash function
int hash(int key) {
    return key % M;
}

// Insert using progressive overflow
void insert(int key) {
    int index = hash(key);

    // If primary slot is empty, insert directly
    if (table[index] == EMPTY) {
        table[index] = key;
        return;
    }

    // Collision occurred → use overflow area
    for (int i = M; i < M + O; i++) {
        if (table[i] == EMPTY) {
            table[i] = key;
            return;
        }
    }

    printf("Overflow area full. Cannot insert %d\n", key);
}

// Display the table
void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < M + O; i++) {
        if (table[i] == EMPTY)
            printf("[%d] : EMPTY\n", i);
        else
            printf("[%d] : %d\n", i, table[i]);
    }
}

int main() {
    // Initialize table
    for (int i = 0; i < M + O; i++)
        table[i] = EMPTY;

    int keys[] = {15, 11, 18, 7, 22, 19, 13};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++)
        insert(keys[i]);

    display();
    return 0;
}
