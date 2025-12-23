# Binary Search Tree Implementation in C
## Overview
This C program implements a Binary Search Tree (BST) with various traversal methods and operations. The BST maintains the property that for every node, all values in its left subtree are smaller and all values in its right subtree are larger.

## Data Structures
1. Node Structure
```c
typedef struct Node{
    int elem;           // Element value
    struct Node *lc;    // Left child pointer
    struct Node *rc;    // Right child pointer
}Node, *BST;
```
2. Queue Structure (for BFS)
```c
typedef struct Queue {
    Node* data[100];    // Array to store node pointers
    int front, rear;    // Queue indices
} Queue;
```
## Core BST Operations
### 1. Insert Operation
**Function:** ``insert(BST *T, int value)``

* **Time Complexity:** O(h) where h is tree height

* **Space Complexity:** O(1)

* **Algorithm:**

    1. Traverse the tree to find the correct position

    2. Create a new node when reaching NULL

    3. Maintain BST property by comparing values

### 2. Delete Operation
**Function:** ``delete(BST *T, int value)``

* **Time Complexity:** O(h)

* **Space Complexity:** O(h) for recursion

* **Three Cases Handled:**

    * **Leaf Node:** Simply remove the node

    * **One Child:** Replace node with its child

    * **Two Children:** Find inorder successor, copy value, and delete successor

* **Helper Function:** ``findMin(BST T)`` - Finds minimum value in a subtree

## Tree Traversals
### Depth-First Search (DFS) Methods
### 1. Inorder Traversal
**Function:** ``inorder(BST B)``

* **Order:** Left → Root → Right

* **Result:** Elements in ascending order

* **Output for given example:** ``1 2 4 5``

### 2. Preorder Traversal
**Function:** ``preorder(BST B)``

* **Order:** Root → Left → Right

* **Use:** Creates copy of tree, prefix expression

* **Output for given example:** ``5 2 1 4``

### 3. Postorder Traversal
**Function:** ``postorder(BST B)``

* **Order:** Left → Right → Root

* **Use:** Delete tree, postfix expression

* **Output for given example:** ``1 4 2 5``

### Breadth-First Search (BFS)
**Function:** ``bfs(BST T)``

* Also known as Level Order Traversal

* **Algorithm:**

    1. Use queue to store nodes

    2. Process nodes level by level

    3. Enqueue children as parents are processed

* **Output for given example:** ``5 2 1 4``

* **Queue Operations:**

``initQueue()``: Initialize empty queue

``isEmpty()``: Check if queue is empty

``enqueue()``: Add node to queue

``dequeue()``: Remove node from queue

## Example Execution
### Initial Tree Construction
```c
insert(&T, 5);  // Root
insert(&T, 2);  // Left child of 5
insert(&T, 1);  // Left child of 2
insert(&T, 3);  // Right child of 2
insert(&T, 4);  // Right child of 3
```
### Tree Structure Before Deletion:
```plaintext
        5
       /
      2
     / \
    1   3
         \
          4
```
### After Deletion of Node 3:
```plaintext
        5
       /
      2
     / \
    1   4
```
## Memory Management
* Uses ``calloc()`` for node allocation

* ``free()`` used in delete operation

* No memory leaks as all dynamically allocated nodes are properly freed

## Key Features
1. **Recursive Implementation:** Most operations use recursion for simplicity

2. **Pointer to Pointer:** Insert and delete operations use double pointers for direct tree modification

3. **Queue-based BFS:** Efficient level-order traversal using circular queue

4. **Complete BST Operations:** Insert, delete, and all major traversal methods

## Performance Considerations
**Best Case:** Balanced tree (O(log n) operations)

**Worst Case:** Skewed tree (O(n) operations)

**Space:** O(n) for node storage, O(h) for recursion stack

## Usage Example
The main function demonstrates:

1. Building a BST with values 5, 2, 1, 3, 4

2. Deleting node 3

3. Displaying all traversal orders

4. Performing DFS (inorder)

5. Performing BFS (level order)