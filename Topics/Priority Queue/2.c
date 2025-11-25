#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
<<<<<<< HEAD

#define MAX 10

typedef struct{
    int priority;
}Node;

typedef struct{
    Node L[MAX];
    int size;
}PriorityQueue;

bool initPQ(PriorityQueue* PQ);
bool insert(PriorityQueue *PQ, int elem);
void swap(Node *a, Node *b);
void heapify(PriorityQueue* PQ, int i);
Node poll(PriorityQueue* PQ);
void display(PriorityQueue PQ);



int main(){
    PriorityQueue PQ;
    
    initPQ(&PQ);
    
    insert(&PQ, 1);
    insert(&PQ, 2);
    insert(&PQ, 4);
    insert(&PQ, 3);
    
    display(PQ);
    
    Node del = poll(&PQ);
    
    (del.priority != -1) ? printf("Node %d polled.\n", del.priority): printf("Unable to poll.\n");
    
    display(PQ);
=======
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
    
    
>>>>>>> 6f562cded4e1f736d700580ccda55a30cc622e0d
    
    return 0;
}

<<<<<<< HEAD
bool initPQ(PriorityQueue* PQ){
    PQ->size = 0;
    if(PQ->size == 0){
        return true;
    }
}
bool insert(PriorityQueue *PQ, int elem){
    if(PQ->size == MAX-1) return false;
    
    PQ->L[PQ->size++].priority = elem;
    
    for(int i = PQ->size / 2 - 1; i >= 0; i--){
        heapify(PQ, i);
    }
    
}
void swap(Node *a, Node *b){
    Node temp = *a;
    *a = *b;
    *b = temp;
    
}
void heapify(PriorityQueue* PQ, int i){ // MIN heapify
    int smallest = i;
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    
    if(left < PQ->size && PQ->L[left].priority < PQ->L[smallest].priority){
        smallest = left;
    }
    if(right < PQ->size && PQ->L[right].priority < PQ->L[smallest].priority){
=======
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
>>>>>>> 6f562cded4e1f736d700580ccda55a30cc622e0d
        smallest = right;
    }
    
    if(smallest != i){
<<<<<<< HEAD
        swap(&PQ->L[smallest], &PQ->L[i]);
        heapify(PQ, smallest);
    }
    
}
Node poll(PriorityQueue* PQ){
    Node temp;
    temp.priority = -1;
    
    if(PQ->size == 0) return temp;
    
    temp = PQ->L[PQ->size-1];
    
    swap(&PQ->L[0], &temp);
    
    PQ->size--;
    
    for(int i = PQ->size / 2 - 1; i >= 0; i--){
        heapify(PQ, i);
    }
    
    return temp;
}

void display(PriorityQueue PQ){
    printf("---DISPLAY---\n");
    printf("Size: %d\n", PQ.size);
    for(int i = 0; i < PQ.size; i++){
        printf("%d\n", PQ.L[i].priority);
    }
}



=======
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


>>>>>>> 6f562cded4e1f736d700580ccda55a30cc622e0d
