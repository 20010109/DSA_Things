#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct{
    int items[MAX];
    int top;
}Stack;

Stack* initialize();
bool isFull(Stack* s);
bool isEmpty(Stack* s);
void push(Stack* s, int value);
int pop(Stack* s);
int peek(Stack* s);
void display(Stack* s);

int main()
{
    Stack* s = initialize();
    
    push(s, 2);
    push(s, 4);
    push(s, 6);
    
    display(s);
    
    pop(s);
    
    display(s);
    
    return 0;
}

Stack* initialize(){
    Stack* s = malloc(sizeof(Stack));
    s->top = -1;
    return s;
}

bool isFull(Stack* s){return s->top == MAX-1;}

bool isEmpty(Stack* s){return s->top == -1;}

void push(Stack* s, int value){
    if(isFull(s) != true){
        s->items[++s->top] = value;
    } else {
        printf("Unable to add item!\n");
    }
}

int pop(Stack* s){
    if(isEmpty(s) != true){
        int elem = s->items[s->top--];
        return elem;
    } else {
        printf("Unable to pop!\n");
    }
}

int peek(Stack* s){return s->items[s->top];}

void display(Stack* s){
    printf("Displaying Stack Details:\n");
    if(isEmpty(s) == true){
        printf("Stack is empty.\n");
    } else {
        printf("Top = ");
        for(int i = s->top; i > -1; i--){
            printf("%d ", s->items[i]);
            if(i > 0){
                printf("-> ");
            }
        }
    }
    printf("\nTop = %d\n", s->top);
}