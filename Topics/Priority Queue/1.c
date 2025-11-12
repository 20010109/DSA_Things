// THIS IS USED AS AN EXAMPLE OR SANDBOX
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 11

typedef struct{
    int elem[MAX];
    int size;
}Queue;

void initQueue(Queue *PQ);
void insertElem(Queue *PQ, int elem);
int poll(Queue *PQ);
void swap(int *a, int *b);
void maxHeapify(Queue *PQ, int i);
void display(Queue PQ);

// test

void buildMinHeap(Queue *PQ);
void minHeapify(Queue *PQ, int i);

int main() {
    int arr[] = {10, 30, 20, 50, 40, 60, 100, 70, 90, 80}; // to test insertion
    
    Queue PQ;
    
    initQueue(&PQ);
    
    for(int i = 0; i < 10; i++){
        insertElem(&PQ, arr[i]);
    }
    
    display(PQ);
    
    // int removed = poll(&PQ);
    
    // (removed != -1) ? printf("%d has been removed.\n", removed): printf("Failed to remove.\n");
    
    display(PQ);
    
    buildMinHeap(&PQ);
    
    display(PQ);
    
    return 0;
}

void initQueue(Queue *PQ){
    PQ->size = 0;
    printf("Priority Queue initialized.\n");
}
void insertElem(Queue *PQ, int elem){
    if(PQ->size == MAX-1){
        printf("Failed to insert %d.\n", elem); 
        return;
    }    
    
    PQ->elem[PQ->size++] = elem;
        
    for(int i = PQ->size / 2 - 1; i >= 0; i--){
        maxHeapify(PQ, i);
    }
}
int poll(Queue *PQ){
    if(PQ->size == 0) return -1;
    
    int removed = PQ->elem[0];
    
    swap(&PQ->elem[0], &PQ->elem[PQ->size-1]);
    
    PQ->size--;
    
    for(int i = PQ->size / 2 - 1; i >= 0; i--){
        maxHeapify(PQ, i);
    }
    
    return removed;
}
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void maxHeapify(Queue *PQ, int i){
    int largest = i;
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    
    if(left < PQ->size && PQ->elem[left] > PQ->elem[largest]){
        largest = left;
    }
    if (right < PQ->size && PQ->elem[right] > PQ->elem[largest]){
        largest = right;
    }
    
    if(largest != i){
        swap(&PQ->elem[largest], &PQ->elem[i]);
        maxHeapify(PQ, largest);
    }
}
void display(Queue PQ){
    printf("\n---Display---\n");
    printf("Size: %d\n", PQ.size);
    printf("Array:\n");
    for(int i = 0; i < PQ.size; i++){
        printf("%d\n", PQ.elem[i]);
    }
    printf("\n---End of Display---\n");
}


// test


void buildMinHeap(Queue *PQ){
    for(int i = PQ->size / 2 - 1; i >= 0; i--){
        minHeapify(PQ, i);
    }
}
void minHeapify(Queue *PQ, int i){
    int smallest = i;
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    
    if(left < PQ->size && PQ->elem[left] < PQ->elem[smallest]){
        smallest = left;
    }
    if (right < PQ->size && PQ->elem[right] < PQ->elem[smallest]){
        smallest = right;
    }
    
    if(smallest != i){
        swap(&PQ->elem[smallest], &PQ->elem[i]);
        minHeapify(PQ, smallest);
    }
}
