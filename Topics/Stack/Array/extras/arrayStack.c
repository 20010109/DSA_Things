// Stack array

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct{
    int elems[MAX];
    int top;
}Stack;

// core functions

void initializeStack(Stack* s);
void push(Stack *s, int elem);
int pop(Stack* s);
int peek(Stack* s);
bool isFull(Stack *s);
bool isEmpty(Stack *s);
void display(Stack s);

// extra functions

// void displayMenu();
// int getChoice();
// int getNumber();


int main(){
    Stack s;
    initializeStack(&s);
    
    push(&s, 10);
    push(&s, 20);
    push(&s, 25);
    push(&s, 50);
    
    display(s);
    
    pop(&s);
    pop(&s);
    
    display(s);
    
    return 0;
}

//core functions

void initializeStack(Stack* s){
    s->top = 0;
}

void push(Stack *s, int elem){
    if(!isFull(s)){
        s->elems[s->top++] = elem;
    }
}
int pop(Stack* s){
    if(!isEmpty(s)){
        int removedElem = s->elems[s->top];
        s->top--;
    }
}
bool isFull(Stack *s){
    return s->top == MAX-1;
}
bool isEmpty(Stack *s){
    return s->top == 0;
}
int peek(Stack* s){
    return s->elems[s->top];
}
void display(Stack s){
    printf("\n--- Stack Details ---\n");
    if(!isEmpty(&s)){
        for(int i = s.top-1; i >= 0; i--){
            printf("%d ", s.elems[i]);
            if(i > 0){
                printf("-> ");
            }
        }
        printf("\n");
    } else {
        printf("Stack is empty.\n");
    }
}