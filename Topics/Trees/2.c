#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node* LC;
    struct Node* RC;
}Node, *NodePtr, *BST;

void insert(BST* T, int elem);
BST findMin(BST T);
BST delete(BST* T, int elem);
BST search(BST T, int elem);

//display

void inorder(BST T);
void preorder(BST T);
void postorder(BST T);

int main(){
    
    BST T = NULL;
    
    insert(&T, 4);
    insert(&T, 2);
    insert(&T, 1);
    insert(&T, 3);
    insert(&T, 5);
    
    delete(&T, 5);
    
    printf("\nInorder:\n");
    inorder(T);
    
    printf("\nPreorder:\n");
    preorder(T);
    
    printf("\nPostorder:\n");
    postorder(T);
    
    printf("\n\n");
    
    BST s = search(T, 4);
    
    (s != NULL) ? printf("%d has been found!\n", s->data) : printf("search failed.\n");
    
    return 0;
}

    // Insert Bartlet version, using linked list traversal
// void insert(BST* T, int elem){
//     BST *trav;
    
//     for(trav = T; *trav != NULL && (*trav)->data != elem; ){
//         trav = (*trav)->data > elem ? &(*trav)->LC : &(*trav)->RC;
//     }
    
//     if(*trav == NULL){
//         *trav = (BST)calloc(1, sizeof(Node));
//         (*trav)->data = elem;
//     }
// }

    // Insert Programmiz, using recursive
void insert(BST* T, int elem){
    if(*T == NULL){
        *T = (BST)calloc(1, sizeof(Node));
        (*T)->data = elem;
        return;
    }
    if(elem > (*T)->data){
        insert(&(*T)->RC, elem);
    } else 
    if (elem < (*T)->data){
        insert(&(*T)->LC, elem);
    }
}


// needed for delete() function
BST findMin(BST T){
    BST trav = T;
    
    if(trav && trav->LC != NULL){
        trav = trav->LC;
    }
    
    return trav;
}

    // to delete a node in the tree, Bartlet version
// BST delete(BST* T, int elem){
    
//     if (*T == NULL) return NULL;
    
//     if((*T)->data > elem){
//         delete(&(*T)->LC, elem);
//     }
//     else
//     if((*T)->data < elem){
//         delete(&(*T)->RC, elem);
//     } 
//     else {
//         // 1. if node is a leaf
//         if((*T)->LC == NULL && (*T)->RC == NULL){
//             free(*T);
//             *T = NULL;
//             return NULL;
//         }
        
//         // 2. if node is a child
//         if((*T)->LC == NULL || (*T)->RC == NULL){
//             BST temp;
//             if((*T)->LC == NULL){
//                 temp = (*T)->RC;
//             } else {
//                 temp = (*T)->LC;
//             }
//             free(*T);
//             *T = temp;
//             return temp;
//         }
        
//         BST temp = findMin((*T)->RC);
//         (*T)->data = temp->data;
//         delete(&(*T)->RC, temp->data);
        
//     }
//     return *T;
// }


    // to delete a node in the tree, Programmiz version
BST delete(BST* T, int elem){
    
    if (*T == NULL) return NULL;
    
    if((*T)->data > elem){
        delete(&(*T)->LC, elem);
    }
    else
    if((*T)->data < elem){
        delete(&(*T)->RC, elem);
    } 
    else {
        // 2. if node is a child
        if((*T)->LC == NULL || (*T)->RC == NULL){
            BST temp;
            if((*T)->LC == NULL){
                temp = (*T)->RC;
            } else {
                temp = (*T)->LC;
            }
            free(*T);
            *T = temp;
            return temp;
        }
        
        BST temp = findMin((*T)->RC);
        (*T)->data = temp->data;
        delete(&(*T)->RC, temp->data);
        
    }
    return *T;
}

BST search(BST T, int elem){
    if(T == NULL) return NULL;
    
    if(T->data == elem) return T;
    
    if(T->data > elem) search(T->LC, elem);
     
    if(T->data < elem) search(T->RC, elem);
}


// DISPLAY

void inorder(BST T){
    if(T != NULL){
        inorder(T->LC);
        printf("%d ", T->data);
        inorder(T->RC);
    }
}
void preorder(BST T){
    if(T != NULL){
        printf("%d ", T->data);
        preorder(T->LC);
        preorder(T->RC);
    }
}
void postorder(BST T){
        if(T != NULL){
        postorder(T->LC);
        postorder(T->RC);
        printf("%d ", T->data);
    }
}
