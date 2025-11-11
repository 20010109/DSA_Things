// THIS IS USED AS AN EXAMPLE OR SANDBOX
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct{
    int elem[MAX];
    int size;
}Queue;

void initQueue(Queue *PQ);
void insertElem(Queue *PQ, int elem);
void swap(int *a, int *b);
void heapify(Queue *PQ, int i);
void display(Queue PQ);

int main() {
    // Write C code here
    int arr[] = {10, 30, 20, 50, 40}; // to test insertion
    
    Queue PQ;
    
    initQueue(&PQ);
    
    for(int i = 0; i < 5; i++){
        insertElem(&PQ, arr[i]);
    }
    
    display(PQ);
    
    return 0;
}

void initQueue(Queue *PQ){
    PQ->size = 0;
}
void insertElem(Queue *PQ, int elem){
    if(PQ->size == MAX-1) return;
    
    PQ->elem[PQ->size++] = elem;
        
    for(int i = PQ->size / 2 - 1; i >= 0; i--){
        heapify(PQ, i);
    }
}
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(Queue *PQ, int i){
    int largest = i;
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    
    if(left < PQ->size && PQ->elem[left] > PQ->elem[largest]){
        largest = left;
    } else if (right < PQ->size && PQ->elem[right] > PQ->elem[largest]){
        largest = right;
    }
    
    if(largest != i){
        swap(&PQ->elem[largest], &PQ->elem[i]);
        heapify(PQ, largest);
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

