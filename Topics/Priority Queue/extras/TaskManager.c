#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 5

typedef char string[50];

typedef struct {
    string taskName;
    int priority;
} Task;

typedef struct {
    Task t[MAX_SIZE];
    int size;
} PQ;

/* Function Prototypes */
void initPQ(PQ *pq);
void enqueue(PQ *pq, Task task);
Task poll(PQ *pq);
Task peek(PQ *pq);
void buildHeap(PQ *pq, bool maxHeap);
void minHeapify(PQ *pq, int i);
void maxHeapify(PQ *pq, int i);
void swap(Task *a, Task *b);
void display(PQ pq);

int main() {
    PQ pq;
    initPQ(&pq);

    Task t1 = {"Jog", 1};
    Task t2 = {"Play", 4};
    Task t3 = {"Laundry", 3};
    Task t4 = {"Homework", 0};
    Task t5 = {"Gym", 2};

    enqueue(&pq, t1);
    enqueue(&pq, t2);
    enqueue(&pq, t3);
    enqueue(&pq, t4);
    enqueue(&pq, t5);

    display(pq);

    Task served = poll(&pq);
    printf("\nPolled Task: %s (Priority %d)\n", served.taskName, served.priority);

    display(pq);

    return 0;
}

/* ================= FUNCTIONS ================= */

void initPQ(PQ *pq) {
    pq->size = 0;
}

void enqueue(PQ *pq, Task task) {
    if (pq->size == MAX_SIZE) {
        printf("Queue is full.\n");
        return;
    }

    pq->t[pq->size++] = task;
    buildHeap(pq, true); // max heap
}

Task poll(PQ *pq) {
    if (pq->size == 0) {
        printf("Queue is empty.\n");
        Task empty = {"", -1};
        return empty;
    }

    Task root = pq->t[0];
    pq->t[0] = pq->t[--pq->size];
    maxHeapify(pq, 0);

    return root;
}

Task peek(PQ *pq) {
    if (pq->size == 0) {
        Task empty = {"", -1};
        return empty;
    }
    return pq->t[0];  // root of heap
}

void buildHeap(PQ *pq, bool maxHeap) {
    for (int i = pq->size / 2 - 1; i >= 0; i--) {
        if (maxHeap)
            maxHeapify(pq, i);
        else
            minHeapify(pq, i);
    }
}

void minHeapify(PQ *pq, int i) {
    int smallest = i;
    int left = i * 2 + 1;
    int right = i * 2 + 2;

    if (left < pq->size && pq->t[left].priority < pq->t[smallest].priority)
        smallest = left;

    if (right < pq->size && pq->t[right].priority < pq->t[smallest].priority)
        smallest = right;

    if (smallest != i) {
        swap(&pq->t[i], &pq->t[smallest]);
        minHeapify(pq, smallest);
    }
}

void maxHeapify(PQ *pq, int i) {
    int largest = i;
    int left = i * 2 + 1;
    int right = i * 2 + 2;

    if (left < pq->size && pq->t[left].priority > pq->t[largest].priority)
        largest = left;

    if (right < pq->size && pq->t[right].priority > pq->t[largest].priority)
        largest = right;

    if (largest != i) {
        swap(&pq->t[i], &pq->t[largest]);
        maxHeapify(pq, largest);
    }
}

void swap(Task *a, Task *b) {
    Task temp = *a;
    *a = *b;
    *b = temp;
}

void display(PQ pq) {
    printf("\n----- TASK MANAGER DISPLAY -----\n");
    printf("Tasks listed: %d\n", pq.size);
    printf("%-15s | %-8s\n", "TASK NAME", "PRIORITY");

    for (int i = 0; i < pq.size; i++) {
        printf("%-15s | %-8d\n", pq.t[i].taskName, pq.t[i].priority);
    }

    printf("----- END DISPLAY -----\n");
}
