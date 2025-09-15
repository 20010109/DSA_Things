#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 4

typedef struct{
    int elem;
    int next;
}Cell, HeapSpace[MAX];

typedef struct {
    HeapSpace H;
    int avail;
}VHeap;

typedef int List;

void initialize(VHeap *V);
int allocSpace(VHeap *V);
void deallocSpace(VHeap *V, int index);
void insertFirst(int *L, VHeap *V, int elem);
void insertLast(int* L, VHeap *V, int elem);
void insertSorted(int *L, VHeap *V, int elem);
void delete(int *L, VHeap *V, int elem);
void deleteAllOccurrence(int *L, VHeap *V, int elem);
void display(int L, VHeap V);

int main(){
    List L = -1;
    VHeap V;
    initialize(&V);
    
    insertLast(&L, &V, 20);
    insertLast(&L, &V, 20);
    insertLast(&L, &V, 20);
    insertLast(&L, &V, 20);
    
    deleteAllOccurrence(&L, &V, 20);
    
    
    //delete(&L, &V, 40);
    //delete(&L, &V, 10);
    
    display(L, V);
}

void initialize(VHeap *V){
    V->avail = 0;
    for(int i = 0; i < MAX; i++){
        V->H[i].next = i+1;
    }
    V->H[MAX-1].next = -1;
}

int allocSpace(VHeap *V){
    int ret = V->avail;
    if(ret != -1){
        V->avail = V->H[ret].next;
    }
    return ret;
}

void deallocSpace(VHeap *V, int index){
    V->H[index].next = V->avail;
    V->avail = index;
}

void insertFirst(int *L, VHeap *V, int elem){
    int newCell = allocSpace(V);
    if(newCell != -1){
        V->H[newCell].elem = elem;
        V->H[newCell].next = *L;
    }
    *L = newCell;
}

void insertLast(int* L, VHeap *V, int elem){
    int newCell = allocSpace(V);
    if(newCell != -1){
        V->H[newCell].elem = elem;
        V->H[newCell].next = -1;
        int *trav = L;
        while(*trav != -1){
            trav = &V->H[*trav].next;
        }
        *trav = newCell;
    } 
}

void insertSorted(int *L, VHeap *V, int elem){
    int *trav = L;
    int newCell = allocSpace(V);
    if(newCell != -1){
        V->H[newCell].elem = elem;
        while(*trav != -1 && V->H[*trav].elem < elem){
            trav = &V->H[*trav].next;
        }
        V->H[newCell].next = *trav;
        *trav = newCell;
    }
}

void delete(int *L, VHeap *V, int elem){
    int *trav, temp;
    trav = L;
    while(*trav != -1 && V->H[*trav].elem != elem){
        trav = &V->H[*trav].next;
    }
    if(*trav != -1){
        temp = *trav;
        *trav = V->H[*trav].next;
        deallocSpace(V,temp);
    }
}

void deleteAllOccurrence(int *L, VHeap *V, int elem){
    int *trav = L;
    while(*trav != -1){
        if(V->H[*trav].elem == elem){
            delete(L, V, elem);
        }
    }
}

void display(int L, VHeap V){
    printf("\n--- Display ---\n");
    printf("L = %d\n", L);
    printf("%-5s | %-5s | %5s\n","Index","Elem", "Next");
    for(int i = 0, trav = L; trav != -1 && i < MAX; trav = V.H[trav].next, i++){
        printf("%-5d | %-5d | %5d\n",i , V.H[trav].elem, V.H[trav].next);
    }
}
