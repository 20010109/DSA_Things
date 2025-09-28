#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 50

typedef struct{
    char elem[MAX];
    int top;
} Stack;

// Helper Function | DO NOT TOUCH
void init(Stack *s);
bool isEmpty(Stack s);
bool isFull(Stack s);
char top(Stack s);
void pop(Stack *s);
void push(Stack *s, char data);
int findPrecedence(char op);

// YOUR TASK
Stack InfixTOPostfix(char infix[MAX]);

// Main Function | DO NOT TOUCH
int main(){
    char infix[256];

    printf("(STRICTLY NO SPACES!)\nEnter infix expression: ");
    scanf("%s", infix);

    Stack postfix = InfixTOPostfix(infix);

    printf("Postfix Expression: %s\n", postfix.elem);

    return 0;
}

// Your Task
Stack InfixTOPostfix(char infix[MAX]){
    // Implementation here...
    Stack result, s;
    init(&result);
    init(&s);

    for(int i = 0; infix[i] != '\0'; i++){
        char c = infix[i];
        if (isalnum(c)) {
            push(&result, c);
        } else if(c == '('){
            push(&s, c);
        } else if(c == ')'){
            while(!isEmpty(s) && top(s) != '('){
                push(&result, top(s));
                pop(&s);
            }
            pop(&s);
        } else {
            while(!isEmpty(s) && 
            ((findPrecedence(top(s)) > findPrecedence(c)) ||
            (findPrecedence(top(s)) == findPrecedence(c) && top(s) != '^'))
            && top(s) != '('){
                push(&result, top(s));
                pop(&s);
            }
            push(&s, c);
        }

    }
    while(!isEmpty(s)){
        push(&result, top(s));
        pop(&s);
    }

    return result;
}

// Helper Functions
void init(Stack *s){
    s->top = -1;
}

bool isEmpty(Stack s){
    return (s.top == -1) ? true : false;
}

bool isFull(Stack s){
    return (s.top == MAX - 1) ? true : false;
}

char top(Stack s){
    char d = '\0';
    return (!isEmpty(s)) ? s.elem[s.top] : d;
}

void pop(Stack *s){
    if (!isEmpty(*s)){
        s->top--;
    }
}

void push(Stack *s, char data){
    if (!isFull(*s)){
        s->elem[++s->top] = data;
    }
}

int findPrecedence(char op){
    switch (op){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}
