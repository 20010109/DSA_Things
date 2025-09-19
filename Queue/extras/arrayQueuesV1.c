//variation 1 - no sacrificial space

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct{
    int elems[MAX];
    int count;
}List;

typedef struct{
    List list;
    int front;
    int rear;
}Queue;

void initializeQueue(Queue *q);
void enqueue(Queue *q, int elem);
int dequeue(Queue *q);
int front(Queue *q);
bool isFull(Queue *q);
bool isEmpty(Queue *q);
void display(Queue *q);

int main(){
    Queue q;
    initializeQueue(&q);
    
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    
    display(&q);
    
    dequeue(&q);
    
    display(&q);
    
    return 0;
}

void initializeQueue(Queue *q){
    q->list.count = 0;
    q->front = -1;
    q->rear = -1;
}
void enqueue(Queue *q, int elem){
    if(!isFull(q)){
        if(isEmpty(q)){
            q->front = 0;
            q->rear = 0;
        } else {
            q->rear = (q->rear + 1) % MAX;    
        }
        q->list.elems[q->rear] = elem;
        q->list.count++;
    }
}
int dequeue(Queue *q){
    if(!isEmpty(q)){
        int removedElem = front(q);
        if(q->list.count == 1){
            q->front = 0;
            q->rear = 0;
        } else {
            q->front = (q->front + 1) % MAX;
        }
        q->list.count--;
        return removedElem;
    }
}
int front(Queue *q){
    return q->list.elems[q->front];
}
bool isFull(Queue *q){
    return q->list.count == MAX-1;
}
bool isEmpty(Queue *q){
    return q->list.count == 0;
}
void display(Queue *q){
    printf("\n--- Displaying Queue ---\n");
    printf("count = %d\n", q->list.count);
    for(int i = 0, trav = q->front; i < q->list.count; i++){
        printf("%d ", q->list.elems[trav]);
        trav = (trav + 1) % MAX;
    }
}