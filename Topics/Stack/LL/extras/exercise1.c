#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node, *NodePtr;

typedef struct{
    NodePtr top;
    int count;
}Stack;

bool initializeStack(Stack *s);
void push(Stack *s, int data);
int pop(Stack *s, Stack *s2);
int peek(Stack *s);
bool isFull(Stack *s);
bool isEmpty(Stack *s);
void display(Stack s, Stack s2);

int main(){
    Stack s;
    Stack s2;
    (initializeStack(&s) == true) ? printf("Stack initialized!\n"): printf("Stack failed to initialize.\n");
    (initializeStack(&s2) == true) ? printf("Stack initialized!\n"): printf("Stack failed to initialize.\n");

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);

    display(s, s2);

    pop(&s, &s2);
    pop(&s, &s2);

    display(s, s2);

    return 0;
}

NodePtr createNode(int data){
    NodePtr newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
}

bool initializeStack(Stack *s){
    s->top = NULL;
    s->count = 0;
    return true;
}

void push(Stack *s, int data){
    NodePtr newNode = createNode(data);
    if(isEmpty(s)){
        s->top = newNode;
    } else {
        newNode->next = s->top;
        s->top = newNode;
    }
}

int pop(Stack *s, Stack *s2){
    if(!isEmpty(s)){
        NodePtr temp = s->top;
        push(s2, temp->data);
        s->top = s->top->next;
        free(temp);
    }
}

int peek(Stack *s){
    return s->top->data;
}

bool isFull(Stack *s){
    return false; //always false since linked list implementation
}
bool isEmpty(Stack *s){
    return s->top == NULL;
}

void display(Stack s, Stack s2){
    printf("\n--- Displaying Stack ---\n");
    printf("\n--- Stack 1 ---\n");
    if(!isEmpty(&s)){
        printf("Top: ");
        for(NodePtr trav = s.top; trav != NULL; trav = trav->next){
            printf("%d ", trav->data);
            if(trav->next != NULL){
                printf("-> ");
            }
        }
    } else {
        printf("Stack is empty.\n");
    }
    printf("\n--- Stack 2 ---\n");
    if(!isEmpty(&s2)){
        printf("Top: ");
        for(NodePtr trav = s2.top; trav != NULL; trav = trav->next){
            printf("%d ", trav->data);
            if(trav->next != NULL){
                printf("-> ");
            }
        }
    } else {
        printf("Stack is empty.\n");
    }
}