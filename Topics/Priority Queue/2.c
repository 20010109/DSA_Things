#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
    
    return 0;
}

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
        smallest = right;
    }
    
    if(smallest != i){
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



