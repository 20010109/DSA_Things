#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int data;
    struct node *next;
}Node;

typedef struct{
    Node *head;
    int count;
}List;

List* initialize();
void empty(List *list);
void insertFirst(List *list, int data);
void insertLast(List *list, int data);
void insertPos(List *list, int data, int index);
void deleteStart(List *list);
void deleteLast(List *list);
void deletePos(List *list, int index);
int retrieve(List *list, int index);
int locate(List *list, int data);
void display(List *list);

Node* createNode(int data);

int main(){
    List *L = initialize();
    
    //printf("%d count", L->count);
    
    insertFirst(L, 2);
    insertFirst(L, 1);
    insertLast(L, 3);
    insertLast(L, 4);
    insertPos(L, 5,2);
    insertPos(L, 0,0);
    insertPos(L, 10,7);
    
    display(L);
    
    //delete
    deleteStart(L);
    
    display(L);
    
    return 0;
}

//extra functions
Node* createNode(int data){
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    
    return newNode;
}

//main functions

List* initialize(){
    List *L = malloc(sizeof(List));
    L->head = NULL;
    L->count = 0;
    if (L->head == NULL && L->count == 0){
        printf("Memory allocation successful!\n");
        return L;
    } else {
        printf("Memory allocation failed!\n");
        return NULL;
    }
}

void empty(List *list);

void insertFirst(List *list, int data){
    Node *newNode = createNode(data);
    if(list != NULL){
        if(list->count == 0){
            list->head = newNode;
            list->count++;
        } else {
            newNode->next = list->head;
            list->head = newNode;
            list->count++;
        }
    } else {
        printf("List is NULL, unable to insertFirst!\n");
    }
}

void insertLast(List *list, int data){
    Node *newNode = createNode(data);
    Node *headref = list->head;
    if(list != NULL){
        if(list->count == 0){
            headref = newNode;
        } else {
            for(; headref->next != NULL; headref = headref->next){
            }
            headref->next = newNode;
        }
        list->count++;
    } else {
        printf("List is NULL, unable to insertLast!\n");
    }
}

void insertPos(List *list, int data, int index){
    Node *newNode = createNode(data);
    Node *current = list->head;
    if(list != NULL){
        if(index < list->count){
            if(index == 0){
                insertFirst(list, data);
            } else
            if(index == list->count){
                insertLast(list, data);
            } else {
                for(int i = 1; i < index-1 && current->next != NULL; i++, current = current->next){
                }
                newNode->next = current->next;
                current->next = newNode;
                list->count++;
            }
        }
    } else {
        printf("List is NULL, unable to insertPos!\n");
    }
}

void deleteStart(List *list){
    Node *current = list->head;
    list->head = current->next;
    list->count--;
    free(current);
}

void deleteLast(List *list){
    
}

void deletePos(List *list, int index);
int retrieve(List *list, int index);
int locate(List *list, int data);
void display(List *list){
    printf("Printing list details:\n");
    for(Node* trav = list->head; trav != NULL; trav = trav->next){
        printf("%d ", trav->data);
    }
    printf("\ncount = %d\n", list->count);
}

