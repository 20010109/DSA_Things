#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10
#define EMPTY '~'
#define DELETED '!'

typedef char Dictionary[MAX];
typedef enum {TRUE, FALSE} Boolean;

void initDictionary(Dictionary D);
void displayDictionary(Dictionary D);
int hash(char elem);
Boolean isMember(Dictionary D, char elem);
void insertUnique(Dictionary D, char elem);
void deleteMember(Dictionary D, char elem);


int main(){
    Dictionary D;
    initDictionary(D);
    
    //initial inserts
    insertUnique(D, 'a');
    insertUnique(D, 'b');
    insertUnique(D, 'c');
    
    //test collisions    
    insertUnique(D, 'W');
    insertUnique(D, 'X');
    insertUnique(D, 'Y');
    
    //secondary inserts
    insertUnique(D, 'S');
    insertUnique(D, 'T');
    insertUnique(D, 'U');
    insertUnique(D, 'V');

    //Test deletes
    deleteMember(D, 'a');
    deleteMember(D, 'W');
    deleteMember(D, 'T');
    
    //isMember Test
    char c = 'X';
    printf("%c %s", c, (isMember(D, c) == TRUE) ? "is found.\n" : "is not found.\n");
    
    displayDictionary(D);
    return 0;
}

void initDictionary(Dictionary D){
    for(int i = 0; i < MAX; i++){
        D[i] = EMPTY;
    }
}
void displayDictionary(Dictionary D){
    printf("[i] | ELEMENT\n");
    printf("-------------\n");
    for(int i = 0; i < MAX; i++){
        printf("[%d] : ",i);
        if(D[i] == '!' || D[i] == '~'){
            printf("%s\n", (D[i] == DELETED) ? "DELETED" : "EMPTY");
        } else {
            printf("%c\n", D[i]);
        }
    }
}
int hash(char elem){
    return elem % MAX;
}
Boolean isMember(Dictionary D, char elem){
    int index, s1;
    
    for(index = hash(elem), s1 = 0; s1 != MAX-1 && D[index] != elem && D[index] != EMPTY; s1++, index = (index + 1) % MAX){}
    
    return (D[index] == elem) ? TRUE : FALSE;
    
    
}
void insertUnique(Dictionary D, char elem){
    int index, s1;
    
    for(index = hash(elem), s1 = 0; s1 < MAX && D[index] != elem && (D[index] != DELETED && D[index] != EMPTY); s1++, index = (index + 1) % MAX){}
    if(D[index] != elem && s1 != MAX-1){
        D[index] = elem;
    } else {
        printf("Unable to insertUnique.\n");
    }
    
    
}
void deleteMember(Dictionary D, char elem){
    int index, s1;
    
    for(index = hash(elem), s1 = 0; s1 != MAX-1 && D[index] != elem && (D[index] != EMPTY || D[index] != DELETED); s1++, index = (index + 1) % MAX){}
    if(D[index] == elem && s1 != MAX-1){
        D[index] = DELETED;
    } else {
        printf("Unable to deleteMember.\n");
    }
}

