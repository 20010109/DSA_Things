# Graph Implementation Using Adjacency List in C
## Overview
This C program implements a graph data structure using an adjacency list representation. The graph supports both Depth-First Search (DFS) and Breadth-First Search (BFS) traversal algorithms.

## Data Structures
### 1. Node Structure
```c
typedef struct node{
    int elem;           // Vertex number
    struct node* link;  // Pointer to next adjacent vertex
}*ptr, Node;
```
### 2. Graph Structure
```c
typedef ptr Graph[MAX];  // Array of pointers to adjacency lists
typedef int vertex;      // Vertex identifier (0 to MAX-1)
```
### 3. Queue Structure (for BFS)
```c
typedef struct Queue{
    int q[MAX];         // Array to store vertices
    int front;          // Front index
    int rear;           // Rear index
}Queue;
```
### Constants
```c
#define MAX 5           // Maximum number of vertices
#define VISITED -1      // Marker for visited vertices
#define UNVISITED 0     // Marker for unvisited vertices
```
## Graph Construction
### Graph Creation
**Function:** ``createNode(int value)``

* Creates a new node for the adjacency list

* Time Complexity: O(1)

*Space Complexity: O(1)

**Function:** ``insertLast(ptr *N, int value)``

* Inserts a vertex at the end of an adjacency list

* **Time Complexity:** O(n) where n is length of adjacency list

* **Space Complexity:** O(1)

### Example Graph Structure
The program creates an undirected graph with 5 vertices (0-4):

```plaintext
        0
       / \
      1---2
         / \
        3   4
```
#### Adjacency Lists:

* Vertex 0: 1 → 2 → NULL

* Vertex 1: 0 → 2 → NULL

* Vertex 2: 1 → 0 → 3 → 4 → NULL

* Vertex 3: 2 → NULL

* Vertex 4: 2 → NULL

## Graph Traversal Algorithms
### Depth-First Search (DFS)
**Function:** ``dfs(Graph G, vertex V, int mark[])``

* **Algorithm**: Recursive depth-first traversal

* **Time Complexity:** O(V + E) where V=vertices, E=edges

* **Space Complexity:** O(V) for recursion stack

* **Process:**

    1. Mark current vertex as visited

    2. Print vertex

    3. Recursively visit all unvisited adjacent vertices

#### Example DFS from vertex 2:

```plaintext
2 → 1 → 0 → 3 → 4
```
### Breadth-First Search (BFS)
**Function:** ``bfs(Graph G, vertex V, int visited[], Queue *Q)``

* **Note:** Currently unfinished implementation

* **Intended Algorithm:**

1. Initialize queue and visited array

2. Enqueue starting vertex

3. While queue not empty:

    * Dequeue vertex

    * Mark as visited

    * Enqueue all unvisited adjacent vertices

#### Queue Operations:

``initQ(Queue *Q)``: Initialize empty queue

``enqueue(Queue* Q, int value)``: Add vertex to queue

``dequeue(Queue* Q)``: Remove vertex from queue

## Display Function
**Function:** ``display(Graph G)``

* Prints the complete adjacency list representation

* **Output Format:**

```plaintext
VERTEX 0 : 1 -> 2 -> NULL
VERTEX 1 : 0 -> 2 -> NULL
...
```
## Key Features
1. Memory Efficiency
* Only allocates memory for existing edges (not MAX×MAX)

* Dynamic adjacency lists grow as needed

2. Flexibility
* Can represent both directed and undirected graphs

* Supports weighted graphs (with modification)

3. Graph Properties
* **Undirected Graph:** Each edge appears twice in adjacency lists

* **Connected Graph:** All vertices are reachable from any vertex

* **Simple Graph:** No self-loops or multiple edges

## Performance Analysis
### Space Complexity
* **Adjacency List:** O(V + E)

* **Visited Array:** O(V)

* **Queue:** O(V)

### Time Complexity
* **Insertion:** O(degree(vertex))

* **DFS/BFS:** O(V + E)

* **Display:** O(V + E)

## Comparison with Adjacency Matrix
|Aspect |	Adjacency List |	Adjacency Matrix |
| :---- | :---- | :---- |
| Space |	O(V+E) |	O(V²) |
| Add Edge |	O(1) |	O(1) |
| Remove Edge |	O(degree) |	O(1) |
| Check Adjacency |	O(degree) |	O(1) |
| Memory Efficiency |	Better for sparse graphs |	Better for dense graphs |