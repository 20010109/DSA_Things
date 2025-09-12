#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct Stack{
    Node* top;
}Stack;

//core functions

Stack* initialize();
bool isFull(Stack* s);
bool isEmpty(Stack* s);
void push(Stack* s, int value);
int pop(Stack* s);
int peek(Stack* s);
void display(Stack* s);

// extra functions

Node* createNode(int value);
void displayMenu();
int getChoice();
int getNumber();

int main(){
    
    Stack *s = initialize();
    int choice = 0;
    while(choice < 5){
        displayMenu();
        choice = getChoice();
        switch(choice){
            case 1:
                push(s, getNumber());
            break;
            case 2:
                printf("Popped %d.\n",pop(s));
            break;
            case 3:
                (peek(s) != -1)? printf("peek = %d.\n", peek(s)): printf("");
            break;
            case 4:
                display(s);
            break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            break;
        }
    }
   
    
    
    return 0;
}

//core functions

Stack* initialize(){
    Stack *s = malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

bool isFull(Stack* s){
    return false;
}

bool isEmpty(Stack* s){
    return s->top == NULL;
}

void push(Stack* s, int value){
    Node* newNode = createNode(value);
    if(isEmpty(s)){
        s->top = newNode;
    } else {
        newNode->next = s->top;
        s->top = newNode;
    }
    printf("Pushed %d.\n", value);
}

int pop(Stack* s){
    if(!isEmpty(s)){
        int removedElem = s->top->data;
        Node* temp = s->top;
        s->top = s->top->next;
        free(temp);
        return removedElem;
    } else {
        printf("Unable to pop, Stack is empty.\n");
    }
}

int peek(Stack* s){
    if(!isEmpty(s)){
        return s->top->data;
    } else {
        printf("Unable to peek, Stack is empty.\n");
        return -1;
    }
}
void display(Stack* s){
    printf("Printing stack details:\n");
    printf("top -> ");
    for(Node* trav = s->top; trav != NULL; trav = trav->next){
        printf("%d ", trav->data);
        if(trav->next != NULL){
            printf("-> ");
        }
    }
    printf("\n");
}

// extra functions

Node* createNode(int value){
    Node* newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void displayMenu(){
    printf("\n--- LL STACK PROGRAM BY JL ---\n");
    printf("1. Push\n2. Pop\n3. Peek\n4. Display Stack\n5. Exit\n");
}

int getChoice(){
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int getNumber(){
    int value;
    printf("Enter value to push: ");
    scanf("%d", &value);
    return value;
}







