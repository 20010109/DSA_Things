#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 5

typedef char *string[10];

typedef struct{
    string taskName;
    int priority;
}Task;

typedef struct{
    Task t[MAX_SIZE];
    int size;
}PQ;

void initPQ(PQ *pq);
void enqueue(PQ *pq, Task task);
Task poll(PQ *pq);
Task peek(PQ* pq);
void buildHeap(PQ* pq, bool maxHeap); // true for maxHeap, false for minHeap
void minHeapify(PQ* pq, int i);
void maxHeapify(PQ* pq, int i);
void swap(Task *a, Task *b);
void display(PQ pq);

int main(){
    
    PQ pq;
    //Task arr[5] = {{"Jog", 1}, {"Play", 4}, {"Do Laundry", 3}, {"Homework", 0}, {"Gym", 2}};
    
    Task task1 = {"Jog", 1};
    
    initPQ(&pq);
    
    //for(int i = 0; i < MAX_SIZE; i++){
        enqueue(&pq, task1);
    //}
    
    display(pq);
    
    
    
    return 0;
}

void initPQ(PQ *pq){
    pq->size = 0;
}
void enqueue(PQ *pq, Task task){
    if(pq->size == MAX_SIZE){
        printf("Queue is full.\n");
        return;
    }
    
    pq->t[pq->size++] = task;
    
    buildHeap(pq, true);
    
    return;
}
Task poll(PQ *pq){
    
}
Task peek(PQ* pq){
    return pq->t[pq->size];
}
void buildHeap(PQ* pq, bool maxHeap){   // true for maxHeap, false for minHeap
    for(int i = pq->size / 2 - 1; i >= 0; i--){
        if(maxHeap == true){
            maxHeapify(pq, i);
        } else {
            minHeapify(pq, i);
        }
    }
} 
void minHeapify(PQ* pq, int i){
    int left = i * 2 + 1, right = i * 2 + 2, smallest = i;
    
    if(left < pq->size && pq->t[left].priority < pq->t[smallest].priority){
        smallest = left;
    }
    if(right < pq->size && pq->t[right].priority < pq->t[smallest].priority){
        smallest = right;
    }
    
    if(smallest != i){
        swap(&pq->t[smallest], &pq->t[i]);
        minHeapify(pq, smallest);
    }
}
void maxHeapify(PQ* pq, int i){
    int left = i * 2 + 1, right = i * 2 + 2, largest = i;
    
    if(left < pq->size && pq->t[left].priority > pq->t[largest].priority){
        largest = left;
    }
    if(right < pq->size && pq->t[right].priority > pq->t[largest].priority){
        largest = right;
    }
    
    if(largest != i){
        swap(&pq->t[largest], &pq->t[i]);
        maxHeapify(pq, largest);
    }
}
void swap(Task *a, Task *b){
    Task temp = *a;
    *a = *b;
    *b = temp;
}
void display(PQ pq){
    printf("\n-----TASK MANAGER DISPLAY-----\n");
    printf("Tasks listed: %d\n", pq.size);
    printf("%5s | %-5s\n", "TASK NAME", "PRIORITY");
    for(int i = 0; i < pq.size; i++){
        printf("%5s | %-5d\n", pq.t[i].taskName, pq.t[i].priority);
    }
    printf("\n-----END DISPLAY-----\n");
}


