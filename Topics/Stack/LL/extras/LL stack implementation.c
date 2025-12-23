#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int num;
    struct node* link;
}Node;

typedef Node* NodePtr;

typedef struct{
    NodePtr top;
    int count;
}Stack;


//core functions

void initStack(Stack* );
void push(Stack* , int );
void pop(Stack* );
void peek(Stack );
void display(Stack );

// non-core functions

NodePtr createNode(int num);
int getNum();
void displayMenu();


int main(){
    Stack s;
    initStack(&s);
    int choice;
    
    while(choice != 4){
        displayMenu();
        display(s);
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                //push
                push(&s, getNum());
            break;
            case 2:
                //pop
                pop(&s);
            break;
            case 3:
                //peek
                peek(s);
            break;
            case 4:
                //exit
                printf("\n\nExiting application.....");
                return 0;
            break;
        }
    }
    
}


void initStack(Stack* s){
    s->top = NULL;
    s->count = 0;
}

void push(Stack* s, int num){
    NodePtr* head = &(s->top);
    NodePtr newNode = createNode(num);
    
    if(*head == NULL){
        *head = newNode;
    } else {
        newNode->link = *head;
        *head = newNode;
    }
    s->count++;
}
void pop(Stack* s){
    NodePtr* head = &(s->top);
    NodePtr temp = NULL;
    temp = *head;
    *head = (*head)->link;
    free(temp);
    s->count--;
}

void peek(Stack s){
    int topNum = s.top->num;
    if(s.top == NULL){
        printf("\nStack is empty\n");
    } else {
        printf("\nPeek of stack: %d\n", topNum);
    }
}

void display(Stack s){
    NodePtr head = (s.top);
    printf("Stack count: %d\n", s.count);
    printf("Displaying stack:\n");
    if(head == NULL){
        printf("Stack is empty\n");
    } else {
        while(head != NULL){
            printf("%d ", head->num);
            head = head->link;
        }
    }
    printf("\n");
}

// non-core function definitions

NodePtr createNode(int num){
    NodePtr newNode = malloc(sizeof(Node));
    newNode->num = num;
    newNode->link = NULL;
    
    return newNode;
}

int getNum(){
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    return num;
}

void displayMenu(){
    printf("\n======STACK DASHBOARD======\n");
    printf("Choices:\n");
    printf("1. Push\n2. Pop\n3. Peek\n4. Exit Program\n\n");
}






