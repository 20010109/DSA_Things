// Variation 3 - Boolean/enum array

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 8

// The set itself is just an array of booleans/integers.
typedef bool Set[ARRAY_SIZE];

void initialize(Set set);
void insert(Set set, int element);
void Delete(Set set, int element);
bool find(Set set, int element);
void Union(Set A, Set B, Set C);
void intersection(Set A, Set B, Set C);
void difference(Set A, Set B, Set C);
void display(unsigned char set, char setName);

// custom functions

unsigned char convertSetToChar(Set set);

int main(){
    Set A;
    Set B;
    Set C;
    initialize(A);
    initialize(B);
    initialize(C);
    
    insert(A, 0);
    insert(A, 1);
    insert(A, 3);
    insert(A, 7);
    insert(A, 6);
    
    insert(B, 2);
    insert(B, 4);
    insert(B, 5);
    // insert(B, 7);
    // insert(B, 6);
    
    display(convertSetToChar(A), 'A');
    display(convertSetToChar(B), 'B');
    
    difference(A, B, C);
    
    display(convertSetToChar(C), 'C');
    
    
    
}


void initialize(Set set){
    for(int i = 0; i <= ARRAY_SIZE-1; i++){
        set[i] = false;
    }
}
void insert(Set set, int element){
    if(element < ARRAY_SIZE){
        set[element] = true;
        printf("Inserted.\n");
    } else {
        printf("Insert: Element out of bounds.\n");
    }
}
void Delete(Set set, int element){
    if(element < ARRAY_SIZE){
        set[element] = false;
    } else {
        printf("Delete: Element out of bounds.\n");
    }
}
bool find(Set set, int element){
    if(element < ARRAY_SIZE){
        return (set[element] == true) ? true : false;
    } else {
        return false;
    }
}
void Union(Set A, Set B, Set C){
    printf("\nPerforming Union on Set A and Set B.\n");
    for(int i = 0; i < ARRAY_SIZE; i++){
        if(A[i] ^ B[i]){
            C[i] = true;
        }
    }
}
void intersection(Set A, Set B, Set C){
    printf("\nPerforming Intersection on Set A and Set B.\n");
    for(int i = 0; i < ARRAY_SIZE; i++){
        if(A[i] & B[i]){
            C[i] = true;
        }
    }
}
void difference(Set A, Set B, Set C){
    printf("\nPerforming Difference on Set A and Set B.\n");
    for(int i = 0; i < ARRAY_SIZE; i++){
        if(A[i] & ~(B[i])){
            C[i] = true;
        }
    }
}
void display(unsigned char set, char setName){
    printf("\n--- Displaying Set %c ---\n", setName);
    printf("Set = %d\n", set);
    printf("Binary of Set:\n");
    for(int i = ARRAY_SIZE-1; i >= 0; i--){
        printf("%d ", (set & (1 << i)) ? 1 : 0);
    }
    printf("\nElements in Set:\n");
    for(int i = 0; i < ARRAY_SIZE; i++){
        if(set & (1 << i)){
            printf("%d ", i);
        }
    }
    printf("\n");
}

//custom function

unsigned char convertSetToChar(Set set){
    unsigned char display = 0;
    for(int i = 0; i < ARRAY_SIZE; i++){
        if(set[i]){
            display |= (1 << i);
        }
    }
    return display;
}

