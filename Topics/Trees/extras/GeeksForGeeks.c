// Coded based on GeeksForGeeks

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}Node, *NodePtr, *BST;

BST search(BST T, int target);
NodePtr createNode(int value);
BST insert(BST T, int x);
BST findMin(BST T);
BST delete(BST T, int x);
void display(BST T);
void inorder(BST T);
void preorder(BST T);
void postorder(BST T);

int main(){
    BST T = NULL;
    
    T = insert(T, 10);
    insert(T, 9);
    insert(T, 6);
    insert(T, 7);
    insert(T, 14);
    insert(T, 13);
    insert(T, 17);
    
    display(T);
    
    BST temp = delete(T, 7);
    
    (temp != NULL) ? printf("After delete.\n"): printf("Failed to delete.\n");
    
    
    display(T);
    
    return 0;
}

BST search(BST T, int target){
    if(T == NULL || T->data == target){
        return T;
    }

    if(T->data > target){
        return search(T->left, target);
    }
    return search(T->right, target);
}
NodePtr createNode(int value){
    NodePtr newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
BST insert(BST T, int x){
    if(T == NULL){
        return createNode(x);
    }
    if(x < T->data){
        T->left = insert(T->left, x);
    } else if(x > T->data){
        T->right = insert(T->right, x);
    }
    return T;
}
BST findMin(BST T){
    if(T == NULL) return NULL;
    
    if(T->left != NULL){
        return findMin(T->left);
    }
    return T;
}
BST delete(BST T, int x){
    if(T == NULL) return NULL;
    
    if(x < T->data){
        T->left = delete(T->left, x);
    } else 
    if(x > T->data){
        T->right = delete(T->right, x);
    } else {
        if(T->left == NULL && T->right == NULL){
            free(T);
            return NULL;
        }
        else if(T->left == NULL || T->right == NULL){
            BST temp;
            if(T->left == NULL){
                temp = T->right;
            } else {
                temp = T->left;
            }
            free(T);
            return temp;
        }
        else {
            BST temp = findMin(T->right);
            T->data = temp->data;
            T->right = delete(T->right, x);
        }
    }
    return T;
}
void display(BST T){
    printf("\n----MAIN DISPLAY----\n");
    printf("\nInorder:\n");
    inorder(T);
    printf("\nPreorder:\n");
    preorder(T);
    printf("\nPostorder:\n");
    postorder(T);
    printf("\n----END OF DISPLAY ----\n");
}
void inorder(BST T){
    if(T != NULL){
        inorder(T->left);
        printf("%d ", T->data);
        inorder(T->right);
    }
}
void preorder(BST T){
    if(T != NULL){
        printf("%d ", T->data);
        preorder(T->left);
        preorder(T->right);
    }
}
void postorder(BST T){
    if(T != NULL){
        postorder(T->left);
        postorder(T->right);
        printf("%d ", T->data);
    }
}