#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int elem;
    struct Node *lc;
    struct Node *rc;
}Node, *BST;

typedef struct Queue {
    Node* data[100];
    int front, rear;
} Queue;

void insert(BST *T, int value);
void inorder(BST B);
void preorder(BST B);
void postorder(BST B);
Node* delete(BST* T, int value);
Node* findMin(BST T);

// for DFS

void dfs(BST T);

// for BFS

void initQueue(Queue* q);
int isEmpty(Queue* q);
void enqueue(Queue* q, Node* n);
Node* dequeue(Queue* q);
void bfs(BST T);


int main(){
    
    BST T = NULL;
    
    insert(&T, 5);
    insert(&T, 2);
    insert(&T, 1);
    insert(&T, 3);
    insert(&T, 4);
    
    delete(&T, 3);
    
    printf("Inorder.\n");
    inorder(T);
    printf("\nPreorder.\n");
    preorder(T);
    printf("\nPostorder.\n");
    postorder(T);

    dfs(T);

    printf("\nBFS (Level Order).\n");
    bfs(T);

    
    return 0;
}



void insert(BST *T, int value){
    BST *trav;
    
    for(trav = T; *trav != NULL && (*trav)->elem != value; ){
        trav = ((*trav)->elem > value) ? &(*trav)->lc : &(*trav)->rc;
    }
    
    if(*trav == NULL){
        *trav = (BST)calloc(1, sizeof(Node));
        (*trav)->elem = value;
    }
}

Node* findMin(BST T){
    if(T == NULL){
        return NULL;
    }
    if(T->lc != NULL){
        return findMin(T->lc);
    }
    return T;
}

Node* delete(BST *T, int value){
    
    if(*T == NULL) return NULL;
    
    if((*T)->elem > value){
        delete(&(*T)->lc, value);
    } 
    else if ((*T)->elem < value){
        delete(&(*T)->rc, value);
    } 
    else {
        // 1. delete leaf node
        if((*T)->lc == NULL && (*T)->rc == NULL){ 
            free(*T);
            *T = NULL;
            return NULL;
        } 
        
        // 2. one child
        if ((*T)->lc == NULL || (*T)->rc == NULL){
            Node* temp;
            if((*T)->lc == NULL){
                temp = (*T)->rc;
            } else {
                temp = (*T)->lc;
            }
            free(*T);
            *T = temp;
            return temp;
        }
        
        // 3. two children
        Node* temp = findMin((*T)->rc);
        (*T)->elem = temp->elem;
        delete(&(*T)->rc, temp->elem);

    }
    return *T;
}



// DISPLAY

void inorder(BST B){
    if(B != NULL){
        inorder(B->lc);
        printf("%d ", B->elem);
        inorder(B->rc);
    }
}

void preorder(BST B){
    if(B != NULL){
        printf("%d ", B->elem);
        preorder(B->lc);
        preorder(B->rc);
    }
}

void postorder(BST B){
    if(B != NULL){
        postorder(B->lc);
        postorder(B->rc);
        printf("%d ", B->elem);
    }
}

// for DFS

void dfs(BST T){
    printf("\nDFS (Inorder): \n");
    inorder(T);
}

// for BFS

void initQueue(Queue* q){
    q->front = q->rear = 0;
}

int isEmpty(Queue* q){
    return q->front == q->rear;
}

void enqueue(Queue* q, Node* n){
    q->data[q->rear++] = n;
}

Node* dequeue(Queue* q){
    return q->data[q->front++];
}

void bfs(BST T){
    if(T == NULL) return;

    Queue q;
    initQueue(&q);

    enqueue(&q, T);

    while(!isEmpty(&q)){
        Node* curr = dequeue(&q);
        printf("%d ", curr->elem);

        if(curr->lc != NULL)
            enqueue(&q, curr->lc);

        if(curr->rc != NULL)
            enqueue(&q, curr->rc);
    }
}










