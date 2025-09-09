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

List* initialize();                                 //done
void empty(List *list);                             //done
void insertFirst(List *list, int data);             //done
void insertLast(List *list, int data);              //done
void insertPos(List *list, int data, int index);    //done
void deleteStart(List *list);                       //done
void deleteLast(List *list);                        //done
void deletePos(List *list, int index);              //done
int retrieve(List *list, int index);                //done
int locate(List *list, int data);                   //done
void display(List *list);                           //done

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
    insertLast(L, 6);
    
    display(L);
    
    //delete
    //deleteStart(L);
    // deleteLast(L);
    // deleteLast(L);
    // deleteLast(L);
    // deleteLast(L);
    // deleteLast(L);
    // deleteLast(L);
    
    deletePos(L,5);

    display(L);
    
    //retrieve
    int retindex = 3, ret = retrieve(L, retindex);
    (ret != -1) ? printf("%d found on index %d!\n", ret, retindex) : printf("");
    
    //empty(L);
    int x = 6, loc = locate(L, x);
    (loc != -1) ? printf("%d located on index %d!\n", x, loc) : printf("");
    
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

void empty(List *list){
    Node *current = list->head;
    Node *temp;
    while(current != NULL){
        temp = current;
        current = current->next;
        free(temp);
    }
    list->head = NULL;
    list->count = 0;
}

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
    Node *current = list->head;
    if(list->count == 1){
        deleteStart(list);
    } else {
        for(int i = 0; i < list->count-2; i++, current = current->next){
        }
        free(current->next);
        current->next = NULL;
        list->count--;
    }
}

void deletePos(List *list, int index){
    Node *current = list->head;
    if(index == 0){
        deleteStart(list);
    } else {
        if(index <= list->count){
            for(int i = 0; i < index-1; i++, current = current->next){
            }
            Node *temp = current->next;
            current->next = temp->next;
            free(temp);
            list->count--;
        } else {
            printf("Index is greater than count!\n");
        }
    }
}

int retrieve(List *list, int index){
    if(index < list->count){
        Node *current = list->head;
        for(int i = 0; i < index; i++, current = current->next){
        }
        return current->data;
    } else {
        printf("Unable to retrieve data!\n");
        return -1;
    }
}

int locate(List *list, int data){
    if(list->head == NULL){
        printf("List is null, unable to locate!\n");
        return -1;
    } else {
        Node *current = list->head;
        int i = 0;
        for(; current != NULL && current->data != data; i++, current = current->next){
        }
        if(i < list->count){
            return i;
        } else {
            printf("Unable to locate %d!\n", data);
            return -1;
        }
    }
}

void display(List *list){
    printf("Printing list details:\n");
    if(list->head != NULL){
        for(Node* trav = list->head; trav != NULL; trav = trav->next){
        printf("%d ", trav->data);
        }
    } else {
        printf("List is Empty");
    }
    printf("\ncount = %d\n", list->count);
}
