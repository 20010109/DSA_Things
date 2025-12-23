#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct node{
    int elem;
    struct node* left;
    struct node* right;
}*NodePtr, Node, *BST;

void initBST(BST *T);
void insert(BST *T, int elem);
BST delete(BST *T, int elem);
BST search(BST T, int elem);
BST findMin(BST T);

//display
void display(BST T);
void inorder(BST T);
void preorder(BST T);
void postorder(BST T);



int main(){
    
    BST T;
    
    initBST(&T);
    
    insert(&T, 5);
    insert(&T, 1);
    insert(&T, 3);
    insert(&T, 4);
    insert(&T, 2);
    // insert(&T, 6);
    // insert(&T, 9);
    // insert(&T, 7);
    // insert(&T, 10);
    // insert(&T, 8);
    
    delete(&T, 7);
    
    display(T);
    
    printf("Search: ");
    
    BST s = search(T, 7);
    
    (s != NULL) ? printf("%d found!.\n", s->elem) : printf("Non found.\n");
    

    
    return 0;
}


void initBST(BST *T){
    *T = NULL;
}
void insert(BST *T, int elem){
    BST *trav;
    
    for(trav = T; *trav != NULL && (*trav)->elem != elem; ){
        trav = (*trav)->elem > elem ? &(*trav)->left : &(*trav)->right;
    }
    
    if(*trav == NULL){
        *trav = (BST)calloc(1, sizeof(Node));
        (*trav)->elem = elem;
    }
    
}
BST delete(BST *T, int elem){
    if(*T == NULL) return NULL;
    
    if((*T)->elem > elem){
        delete(&(*T)->left, elem);
    } else if((*T)->elem < elem){
        delete(&(*T)->right, elem);
    } else {
        if((*T)->left == NULL && (*T)->right == NULL){
            free(*T);
            *T = NULL;
            return NULL;
        }
        if((*T)->left == NULL || (*T)->right == NULL){
            BST temp;
            if((*T)->left == NULL){
                temp = (*T)->right;
            } else {
                temp = (*T)->left;
            }
            free(*T);
            *T = temp;
            return temp;
        } else {
            BST temp = findMin(*T);
            (*T)->elem = temp->elem;
            delete(&(*T)->right, temp->elem);
        }
    }
    return *T;
}
BST findMin(BST T){
    if(T == NULL) return NULL;
    
    if(T->left != NULL){
        return findMin(T->left);
    }
    return T;
}
BST search(BST T, int elem){
    BST trav;
    for(trav = T; trav != NULL && trav->elem != elem;){
        trav = (trav->elem > elem)? trav->left : trav->right;
    }
    
    if(trav == NULL) return NULL;
    
    if(trav->elem == elem){
        return trav;
    }
}


//display
void display(BST T){
    printf("\n----DISPLAY----\n");
    printf("\nINORDER:\n");
    inorder(T);
    printf("\nPREORDER:\n");
    preorder(T);
    printf("\nPOSTORDER:\n");
    postorder(T);
    printf("\n----END OF DISPLAY----\n");
}

void inorder(BST T){
    if(T == NULL) return;
    
    inorder(T->left);
    printf("%d ", T->elem);
    inorder(T->right);
}
void preorder(BST T){
    if(T == NULL) return;
    
    printf("%d ", T->elem);
    preorder(T->left);
    preorder(T->right);
}
void postorder(BST T){
    if(T == NULL) return;
    
    printf("%d ", T->elem);
    postorder(T->left);
    postorder(T->right);
}









