// array queue with sacrificial space

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int elems[MAX];
    int front;
    int rear;
} Queue;

Queue* initializeQueue();
bool isFull(Queue *q);
bool isEmpty(Queue *q);
bool enqueue(Queue *q, int elem);
int dequeue(Queue *q);
int front(Queue *q);
void display(Queue *q);

int main(){
    Queue *q = initializeQueue();
    
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    
    display(q);
    
    dequeue(q);
    dequeue(q);
    
    display(q);
    
    
}

Queue* initializeQueue(){
    Queue *q = malloc(sizeof(Queue));
    q->front = 1;
    q->rear = 0;
}
bool isFull(Queue *q){
    return q->front == (q->rear + 2) % MAX;
}
bool isEmpty(Queue *q){
    return q->front == (q->rear + 1) % MAX;
}
bool enqueue(Queue *q, int elem){
    if(!isFull(q)){
        q->rear = (q->rear + 1) % MAX;
        q->elems[q->rear] = elem;
        return true;
    } else {
        return false;
    }
}
int dequeue(Queue *q){
    if(!isEmpty(q)){
        int removedElem = front(q);
        q->front = (q->front + 1) % MAX;
        return removedElem;
    } else {
        return -1;
    }
}
int front(Queue *q){
    return q->elems[q->front];
}
void display(Queue *q){
    printf("\n--- Displaying Queue ---\n");
    if(!isEmpty(q)){
        printf("Front: ");
        for(int trav = q->front; trav != ((q->rear + 2) % MAX)-1; trav = (trav + 1) % MAX){
            printf("%d ", q->elems[trav]);
            if(trav < ((q->rear + 2) % MAX) - 2){
                printf("-> ");
            }
        }
        printf("\n");
    } else {
        printf("Queue is empty.\n");
    }
}


