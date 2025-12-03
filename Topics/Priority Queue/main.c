//Functions of Prio Queue

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 10

typedef char string[255];

typedef struct{
    string username;
    int priority;
}Cell, List[MAX];

typedef struct{
    List L;
    int size;
}Queue;

void Enqueue(Queue* PQ, int priority, const char* username);
Cell Dequeue(Queue* PQ);
Cell peek(Queue PQ);
bool isEmpty(Queue PQ);
int getSize(Queue PQ);

void heapify(Queue* PQ, int i); // minheap;
void initQueue(Queue* PQ);
void swap(Cell* a, Cell* b);

void display(Queue PQ);


int main(){
    Queue PQ;
    
    initQueue(&PQ);
    
    Enqueue(&PQ, 1, "Max");
    Enqueue(&PQ, 5, "Steph");
    Enqueue(&PQ, 3, "JL");
    Enqueue(&PQ, 4, "Pan");
    Enqueue(&PQ, 2, "Jan");
    
    display(PQ);
    
    Cell del = Dequeue(&PQ);
    
    (del.priority != -1) ? printf("%s has been removed from the queue.\n", del.username): printf("Unable to dequeue.\n");
    
    display(PQ);
    
    return 0;
}


void Enqueue(Queue* PQ, int priority, const char* username){
    if (getSize(*PQ) == MAX-1) return;
    
    PQ->L[getSize(*PQ)].priority = priority;
    strcpy(PQ->L[getSize(*PQ)].username, username);
    
    PQ->size++;
    
    for(int i = PQ->size / 2 - 1; i >= 0; i--){
        heapify(PQ, i);
    }
    
}
Cell Dequeue(Queue* PQ){
    Cell empty = {"", -1};
    
    if(isEmpty(*PQ)) return empty;
    
    Cell temp = peek(*PQ);
    
    swap(&PQ->L[PQ->size-1], &PQ->L[0]);
    
    PQ->size--;
    
    for(int i = PQ->size / 2 - 1; i >= 0; i--){
        heapify(PQ, i);
    }
    
    return temp;
}
Cell peek(Queue PQ){
    return PQ.L[0];
}
bool isEmpty(Queue PQ){
    return PQ.size == 0;
}
int getSize(Queue PQ){
    return PQ.size;
}

void heapify(Queue* PQ, int i){
    int smallest = i;
    int left = i * 2 + 1, right = i * 2 + 2;
    
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
void initQueue(Queue* PQ){
    PQ->size = 0;
}
void swap(Cell* a, Cell* b){
    Cell temp = *a;
    *a = *b;
    *b = temp;
}
void display(Queue PQ){
    printf("\n----DISPLAY----\n");
    printf("Size: %d\n", (getSize(PQ)));
    for(int i = 0; i < getSize(PQ); i++){
        printf("%d : %10s\n", PQ.L[i].priority, PQ.L[i].username);
    }
    printf("\n----END----\n");
}






