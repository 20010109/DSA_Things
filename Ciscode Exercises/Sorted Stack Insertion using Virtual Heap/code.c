#include <stdio.h>
#include <stdlib.h>

#define VHSIZE 50

typedef struct {
    int data;
} Element;

typedef struct {
    Element elem;
    int next;
} Node;

typedef struct {
    Node VHNode[VHSIZE];
    int avail;
} VHeap;

typedef int Stack;  // index of top element


/*************************************/
/*           YOUR TASKS              */
/*************************************/
// --- CB functions --- //
void initVHeap(VHeap *VH);
int allocSpace(VHeap *VH);
void freeSpace(VHeap *VH, int idx);

// --- Stack functions ---
void initStack(Stack *S);
void insertSorted(VHeap *VH, Stack *S, int data);
void printStack(VHeap VH, Stack S);

// --- Main program ---
int main() {
    VHeap VH;
    Stack S;
    int N, val;

    initVHeap(&VH);
    initStack(&S);

    printf("Enter size: ");
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &val);
        insertSorted(&VH, &S, val);
    }

    printStack(VH, S);

    return 0;
}

void initVHeap(VHeap *VH) {
    // Implementation here...
    VH->avail = 0;
    for(int i = 0; i < VHSIZE; i++){
        VH->VHNode[i].next = i + 1;
    }
    VH->VHNode[VHSIZE-1].next = -1;
}

int allocSpace(VHeap *VH) {
    // Implementation here...
    int ret = VH->avail;
    if(ret != -1){
        VH->avail = VH->VHNode[ret].next;
    }
    return ret;
}

void freeSpace(VHeap *VH, int idx) {
    // Implementation here...
    VH->VHNode[idx].next = VH->avail;
    VH->avail = idx; 
}

// --- Stack functions ---
void initStack(Stack *S) {
    // Implementation here...
    *S = -1;
}

void insertSorted(VHeap *VH, Stack *S, int data) {
    // Implementation here...
    int newCell = allocSpace(VH);
    if(newCell != -1){
        VH->VHNode[newCell].elem.data = data;
        int *trav = S;
        while(*trav != -1 && VH->VHNode[*trav].elem.data < data){
            trav = &VH->VHNode[*trav].next;
        }
        VH->VHNode[newCell].next = *trav;
        *trav = newCell;
    }
}

void printStack(VHeap VH, Stack S) {
    // Implementation here...
    printf("Sorted Stack: ");
    for(int trav = S; trav != -1; trav = VH.VHNode[trav].next){
        printf("%d ", VH.VHNode[trav].elem.data);
    }
}