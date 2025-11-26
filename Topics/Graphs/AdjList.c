// adjacency list

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 9
#define VISITED -1
#define UNVISITED 10

typedef struct node{
    int elem;
    struct node* link;
}*ptr, Node;

typedef ptr Graph[MAX];
typedef int vertex;

ptr createNode(int value);
void insertLast(ptr *N, int value);
void display(Graph G);

int main(){
    Graph G;
    
    insertLast(&G[0], 1);
    insertLast(&G[0], 2);
    insertLast(&G[0], 3);
    insertLast(&G[1], 2);
    
    display(G);
    
    
    return 0;
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
