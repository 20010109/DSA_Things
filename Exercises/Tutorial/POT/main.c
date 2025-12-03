#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 32

typedef char String[32];

typedef struct {
    int patient_id;
    int priority_num;
    String patient_name;
    String reason;
} PatientPriorityInfo;

typedef struct {
    PatientPriorityInfo patients[MAX];
    int last; // or size;
} HEAP;

void insertPatient(HEAP *heap, PatientPriorityInfo patient);
void deleteFirst(HEAP *heap);

void heapify(HEAP *heap, int i);
void buildMaxHeap(HEAP *heap);
void swap(PatientPriorityInfo* a, PatientPriorityInfo *b);

void display(HEAP heap);


int main(){
    
    HEAP Q;
    
    PatientPriorityInfo patients[] = {  {1, 3, "Dajao", "Sick si bro"},
                                        {2, 1, "Dusky", "Rabies"},
                                        {3, 2, "Jer", "No reason"},
                                        {4, 5, "Aaron", "Tripped"},
                                        {5, 4, "Lance", "Overdose"}
                                    };
    
    for(int i = 0; i < 5; i++){
        insertPatient(&Q, patients[i]);
    }
    
    display(Q);
    
    deleteFirst(&Q);
    
    display(Q);
    
    return 0;
}


void insertPatient(HEAP *heap, PatientPriorityInfo patient){
    // your code from activity 1
    heap->patients[heap->last++] = patient;
    
    buildMaxHeap(heap);
}

void deleteFirst(HEAP *heap){
    // insert your code here
    if(heap->last == 0){
        return;
    }
    
    swap(&heap->patients[0], &heap->patients[heap->last]);
    
    buildMaxHeap(heap);
    
    heap->last--;
}

void heapify(HEAP *heap, int i){
    int largest = i;
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    
    if(left < heap->last && heap->patients[largest].priority_num < heap->patients[left].priority_num){
        largest = left;
    }
    if(right < heap->last && heap->patients[largest].priority_num < heap->patients[right].priority_num){
        largest = right;
    }
    
    if(largest != i){
        swap(&heap->patients[largest], &heap->patients[i]);
        heapify(heap, largest);
    }
}
void buildMaxHeap(HEAP *heap){
    for(int i = heap->last / 2 - 1; i >= 0; i--){
        heapify(heap, i);
    }
}

void swap(PatientPriorityInfo* a, PatientPriorityInfo *b){
    PatientPriorityInfo temp = *a;
    *a = *b;
    *b = temp;
}

void display(HEAP heap){
    printf("\n----DISPLAY----\n");
    printf("id | priority number | patient name | reason \n");
    for(int i = 0; i < heap.last; i++){
        printf("%2d | %15d | %12s | %5s \n", heap.patients[i].patient_id, heap.patients[i].priority_num, heap.patients[i].patient_name, heap.patients[i].reason);
    }
    printf("\n----END DISPLAY----\n");
}
