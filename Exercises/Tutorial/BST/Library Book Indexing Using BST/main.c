#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char String[32];

typedef struct {
    int book_id;
    String book_name;
} Book;

typedef struct node {
    Book book;
    struct node *left;
    struct node *right;
} *BST;

void printOrders(BST root);
void inorder(BST root);
void preorder(BST root);
void postorder(BST root);

//activity functions

void insertNode(BST *root, Book newBook);
void displayBook(BST root, int book_id);


int main(){
    
    BST T = NULL;
    Book books[] = {{3, "Crazy"},
                    {1, "Wow"},
                    {2, "Goldilocks"},
                    {5, "Alice in Wonderland"},
                    {4, "Harry Potter"}
                    };
                    
    
    for(int i = 0; i < 5; i++){
        insertNode(&T, books[i]);
    }
    
    printOrders(T);
    
    displayBook(T, 2);
    
    return 0;
}


void printOrders(BST root){
    printf("Inorder\n");
    inorder(root);
    printf("Preorder\n");
    preorder(root);
    printf("Postorder\n");
    postorder(root);
    printf("\n");
    
}

void inorder(BST root){
    if(root != NULL){
        inorder(root->left);
        printf("%d| \"%s\" \n", root->book.book_id, root->book.book_name);
        inorder(root->right);
    }
}
void preorder(BST root){
    if(root != NULL){
        printf("%d| \"%s\" \n", root->book.book_id, root->book.book_name);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(BST root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d| \"%s\" \n", root->book.book_id, root->book.book_name);
    }
}

void insertNode(BST *root, Book newBook){
    // TO DO...
    BST *trav;
    
    for(trav = root; *trav != NULL && (*trav)->book.book_id != newBook.book_id;){
        trav = ((*trav)->book.book_id > newBook.book_id) ? &(*trav)->left : &(*trav)->right;
    }
    
    if(*trav == NULL){
        *trav = (BST)calloc(1, sizeof(struct node));
        (*trav)->book = newBook;
        return;
    } else {
        printf("Error in inserting book into tree.\n");
    }
    return;
}

void displayBook(BST root, int book_id){
    // insert your code here
    printf("displayBook:\n");
    
    BST trav;
    
    for(trav = root; trav != NULL && trav->book.book_id != book_id;){
        trav = (trav->book.book_id > book_id) ? trav->left : trav->right;
    }
    
    if(trav != NULL){
        printf("Book found:\n");
        printf("%d| \"%s\" \n", trav->book.book_id, trav->book.book_name);
    } else {
        printf("Error. unable to find book_id: %d", book_id);
    }
    
}