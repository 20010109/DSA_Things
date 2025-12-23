#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10

typedef struct Node{
    int data;
    struct Node* link;
}Node, *NodePtr;

typedef struct{
    NodePtr List[SIZE];
}Dictionary;


// main functions
void initDictionary(Dictionary* D);
int hashFunction(int key);
void insert(Dictionary *D, int key);
int search(Dictionary D, int key);
void delete(Dictionary *D, int key);
void display(Dictionary D);

// extra functions
NodePtr createNode(int key);


int main(){
    Dictionary D;
    initDictionary(&D);

    int SetA[] = {1 ,32 ,23 ,14 ,5, 15, 25, 35, 7, 17, 21, 52, 33};

    for(int i = 0; i < sizeof(SetA) / sizeof(int); i++){
        insert(&D, SetA[i]);
    }

    display(D);

    delete(&D, 23);
    delete(&D, 25);

    printf("After Deletion.\n");

    display(D);


}


// main functions
void initDictionary(Dictionary* D){
    for(int i = 0; i < SIZE; i++){
        D->List[i] = NULL;
    }
}
int hashFunction(int key){
    return key % SIZE;
}
void insert(Dictionary *D, int key){
    int hash = hashFunction(key);
    NodePtr newNode = createNode(key);

    NodePtr *trav = &D->List[hash];

    if(*trav == NULL){
        *trav = newNode;
    } else {
        while((*trav)->link != NULL){
            trav = &(*trav)->link;
        }
        (*trav)->link = newNode;
    }
}
int search(Dictionary D, int key){
    int hash = hashFunction(key);
    return (D.List[hash]->data == key) ? D.List[hash]->data: -1;
}
void delete(Dictionary *D, int key){
    int hash = hashFunction(key);
    NodePtr *trav = &D->List[hash];
    if(trav != NULL){
        for(; *trav != NULL; trav = &(*trav)->link){
            if((*trav)->data == key){
                NodePtr temp = *trav;
                if((*trav)->link != NULL){
                    *trav = (*trav)->link;
                }
                free(temp);
                break;
            }
        }
    } else {
        printf("Unable to delete.\n");
    }
}
void display(Dictionary D){
    printf("\n--- Display ---\n");
    for(int i = 0; i < SIZE; i++){
        printf("%5d|", i);
        if(D.List[i] == NULL){
            printf("Empty");
        } else {
            Node *trav = D.List[i];
            while(trav != NULL){
                printf("%-5d|", trav->data);
                trav = trav->link;
            }
        }
        printf("\n");
    }
    printf("\n");
}


// extra functions
NodePtr createNode(int key){
    NodePtr newNode = malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->link = NULL;

    return newNode;
}

void seachKey(Dictionary D, int key){
    int s = search(D, key);
    if(s != -1){
        printf("%d found!\n", key);
    } else {
        printf("%d not found!\n", key);
    }
}
