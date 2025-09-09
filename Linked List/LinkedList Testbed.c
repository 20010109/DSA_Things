#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int num;
    struct node* link;
} Node;

typedef Node *NodePtr;

typedef struct{
    NodePtr List;
    int count;
} LinkedList;

void initList(LinkedList* );
NodePtr createNode(int );
int getNumber();
int getPosition();
void insertLast(LinkedList*, int);
void insertFirst(LinkedList*, int);
void insertAt(LinkedList* , int, int);
void deleteLast(LinkedList* );
void deleteFirst(LinkedList* );
void deleteAt(LinkedList* , int);
void display(LinkedList );

int main(){
    LinkedList l;
    int position, num, choice = 0;
    
    initList(&l);
    
    while(choice != 7){
        printf("\n\n======Welcome to LinkedList testbed!======\n\n");
        display(l);
        printf("\n\nSelect an option: \n");
        printf("1. insertLast\n2. insertFirst \n3. insertAt \n4. deleteLast \n5. deleteFirst \n6. deleteAt \n7. Exit Program\n\n");
        printf("Enter Option: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                insertLast(&l, getNumber());
            break;
            case 2:
                insertFirst(&l, getNumber());
            break;
            case 3:
                insertAt(&l, getNumber(), getPosition());
            break;
            case 4:
                deleteLast(&l);
            break;
            case 5:
                deleteFirst(&l);
            break;
            case 6:
                deleteAt(&l, getPosition());
            break;
            case 7:
                printf("Exiting program.....");
                return 0;
            break;
            
        }
    }
}

void initList(LinkedList* l){
    l->List = NULL;\
    l->count = 0;
    printf("List initialized\n\n");
}

NodePtr createNode(int num){
    NodePtr newNode = malloc(sizeof(Node));
    newNode->num = num;
    newNode->link = NULL;
    
    return newNode;
}

int getNumber(){
    int num = 0;
    
    printf("Enter element to add in list: ");
    scanf("%d", &num);
    
    return num;
}

int getPosition(){
    int position;
    
    printf("Enter postion: ");
    scanf("%d", &position);
    
    return position;
}

void insertLast(LinkedList* l, int num){
    
    NodePtr newNode = createNode(num);
    
    NodePtr* head = &(l->List);
    while(*head != NULL){
        head = &((*head)->link);
    }
    *head = newNode;
    l->count++;
}

void insertFirst(LinkedList* l, int num){
    NodePtr newNode = createNode(num);
    
    NodePtr* head = &(l->List);
    
    newNode->link = *head;
    
    *head = newNode;
    
    l->count++;
}

void insertAt(LinkedList* l, int num, int position){
    NodePtr newNode = createNode(num);
    NodePtr* head = &(l->List);
    
    if(position > l->count){
        printf("Error! Position is larger than size!");
    } else {
        for(int i = 0; i < position && head != NULL; i++){
            head = &((*head)->link);
        }
        newNode->link = *head;
        *head = newNode;
        
        l->count++;
    }
}

void deleteLast(LinkedList* l){
    NodePtr* head = &(l->List);
    //NodePtr temp = NULL; // no need for this
    
    if(*head == NULL){              
        printf("List is empty! Nothing to delete.\n");       //check if list is empty
        return;
    }
    
    while((*head)->link != NULL){
        head = &((*head)->link);
    }
    //printf(" TEST NUMBER : %d", (*head)->num); // test 
    free(*head);
    *head = NULL;
    l->count--;
}

void deleteFirst(LinkedList* l){
    NodePtr* head = &(l->List);
    NodePtr temp = (*head)->link;
    
    if(*head == NULL){
        printf("List is empty! Nothing to delete.\n");       //check if list is empty 
        return;
    }
        
    free(*head);
    
    *head = temp;
    l->count--;
}

void deleteAt(LinkedList* l, int position){
    if(l->List == NULL || position > (l->count - 1) || position < 0){
        printf("\nInvalid Position, Check if position is: \n1. Position is greater than count\n2. List is empty\n3. Position is less than 0");
        return;
    } else {
    
        NodePtr* head = &(l->List);
        NodePtr temp = NULL;
        
        for(int i = 0; i < position; i++){
            head = (&(*head)->link);
        }
        
        temp = *head;
        *head = temp->link;
        
        free(temp);
        
        l->count--;
    }
}

void display(LinkedList l){
    NodePtr head = l.List;
    printf("Printing List Details: \n");
    printf("List size count: %d \n", l.count);
    while(head != NULL){
        printf("%d ", head->num);
        head = head->link;
    }
}