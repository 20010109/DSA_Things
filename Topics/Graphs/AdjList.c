// adjacency list

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5
#define VISITED -1
#define UNVISITED 0

typedef struct node{
    int elem;
    struct node* link;
}*ptr, Node;

typedef struct Queue{
    int q[MAX];
    int front;
    int rear;
}Queue;

typedef ptr Graph[MAX];
typedef int vertex;

ptr createNode(int value);
void insertLast(ptr *N, int value);
void display(Graph G);

void dfs(Graph G, vertex V, int mark[]);
void bfs(Graph G, vertex V, int visited[], Queue *Q);
void initQ(Queue *Q);
void enqueue(Queue* Q, int value);
void dequeue(Queue* Q);

int main(){
    Graph G;
    int visited[MAX];
    
    insertLast(&G[0], 1);
    insertLast(&G[0], 2);
    insertLast(&G[1], 0);
    insertLast(&G[1], 2);
    insertLast(&G[2], 1);
    insertLast(&G[2], 0);
    insertLast(&G[2], 3);
    insertLast(&G[2], 4);
    insertLast(&G[3], 2);
    insertLast(&G[4], 2);
    
    //dfs(G, 2, visited);
    
    Queue Q;
    
    bfs(G, 0, visited, &Q);
    
    display(G);
    
    
    
    return 0;
}


void initQ(Queue *Q){
    Q->front = 0;
    Q->rear = 0;
}
void enqueue(Queue* Q, int value){
    Q->q[Q->rear++] = value;
}
void dequeue(Queue* Q){
    Q->front++;
}

// UNFINISHED
void bfs(Graph G, vertex V, int visited[], Queue *Q){
    if(visited[V] == VISITED){
        dequeue(Q);
    }
    
    visited[V] = VISITED;
    printf("%d ", V);
    
    enqueue(Q, V);
    
    ptr trav = G[]
    
    
    
    
}


void dfs(Graph G, vertex V, int mark[]){
    mark[V] = VISITED;
    printf("%d ", V);
    
    ptr trav = G[V];
    int newV;
    
    while(trav != NULL){
        newV = trav->elem;
        if(mark[newV] == UNVISITED){
            dfs(G, newV, mark);
        }
        trav = trav->link;
    }
}

ptr createNode(int value){
    ptr newNode = malloc(sizeof(Node));
    newNode->elem = value;
    newNode->link = NULL;
    
    return newNode;
}


void insertLast(ptr *N, int value){
    ptr newNode = createNode(value);
    
    if(*N == NULL){
        *N = newNode;
    } else {
        ptr *trav = N;
        
        while((*trav)->link != NULL){
            trav = &(*trav)->link;
        }
        
        (*trav)->link = newNode;
        
    }
}


void display(Graph G){
    ptr trav;
    printf("\n----DISPLAY----\n");
    for(int i = 0; i < MAX; i++){
        printf("VERTEX %d : ", i);
        for(trav = G[i]; trav != NULL; trav = trav->link){
            printf("%d -> ", trav->elem);
        }
        printf("NULL\n");
    }
    
}
