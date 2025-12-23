# Priority Queues (Heap-Based Implementation in C)

## 1. What is a Priority Queue?
A **Priority Queue (PQ)** is an abstract data type where each element has a **priority**.
Elements with higher priority are served before lower-priority elements.

This implementation uses a **binary heap** stored in an **array**.

---

## 2. Data Structure

```c
#define MAX 11

typedef struct{
    int elem[MAX];
    int size;
} Queue;
```

- `elem[MAX]` stores heap elements
- `size` tracks the number of elements
- The heap is a **complete binary tree**

---

## 3. Array Representation of Heap

For index `i`:
- Parent: `(i - 1) / 2`
- Left child: `2i + 1`
- Right child: `2i + 2`

---

## 4. Types of Heaps

### Max Heap
- Parent ≥ children
- Root contains the **highest priority**

### Min Heap
- Parent ≤ children
- Root contains the **lowest priority**

---

## 5. Initialize Priority Queue

```c
void initQueue(Queue *PQ){
    PQ->size = 0;
}
```

Sets the queue as empty.

---

## 6. Insertion Operation

```c
void insertElem(Queue *PQ, int elem){
    PQ->elem[PQ->size++] = elem;
    for(int i = PQ->size / 2 - 1; i >= 0; i--){
        maxHeapify(PQ, i);
    }
}
```

Steps:
1. Insert at the end
2. Increase size
3. Restore heap property

Time Complexity: **O(n)**

---

## 7. Removal Operation (poll)

```c
int poll(Queue *PQ){
    int removed = PQ->elem[0];
    swap(&PQ->elem[0], &PQ->elem[PQ->size-1]);
    PQ->size--;
    for(int i = PQ->size / 2 - 1; i >= 0; i--){
        maxHeapify(PQ, i);
    }
    return removed;
}
```

- Removes highest priority element
- Restores heap

Time Complexity: **O(n)**

---

## 8. Heapify (Core Operation)

### Max Heapify

```c
void maxHeapify(Queue *PQ, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < PQ->size && PQ->elem[left] > PQ->elem[largest])
        largest = left;

    if(right < PQ->size && PQ->elem[right] > PQ->elem[largest])
        largest = right;

    if(largest != i){
        swap(&PQ->elem[i], &PQ->elem[largest]);
        maxHeapify(PQ, largest);
    }
}
```

Time Complexity: **O(log n)**

---

## 9. Building a Min Heap

```c
void buildMinHeap(Queue *PQ){
    for(int i = PQ->size / 2 - 1; i >= 0; i--){
        minHeapify(PQ, i);
    }
}
```

Converts existing heap into a min heap.

---

## 10. Display Function

```c
void display(Queue PQ){
    for(int i = 0; i < PQ.size; i++){
        printf("%d\n", PQ.elem[i]);
    }
}
```

Used for debugging and visualization.

---

## 11. Time Complexity Summary

| Operation | Complexity |
|---------|------------|
Insert | O(n) |
Remove | O(n) |
Heapify | O(log n) |
Peek | O(1) |

---

## 12. Key Points

- Priority queues use heaps
- Root always holds highest/lowest priority
- Common in scheduling and graph algorithms

## Max-Heap output of program

<img src='Capture.PNG' alt='maxHeap-output.png'>