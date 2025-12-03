#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

/**
 * @brief Deletes a node with the given key from the BST.
 * @param root The current root of the BST.
 * @param key_data The string key to delete.
 * @return BST The new root of the BST after deletion.
 */
BST findMin(BST root){
    BST *trav = &root;
    
    while((*trav)->LC != NULL){
        trav = &(*trav)->LC;
    }
    
    return *trav;
}
 
BST deleteNode(BST root, const char *key_data) {
    // TODO...
    BST *trav;
    
    for(trav = &root; *trav != NULL && strcmp((*trav)->key, key_data) != 0;){
        trav = (strcmp((*trav)->key, key_data) > 0) ? &(*trav)->LC : &(*trav)->RC;
    }
    
    if(*trav == NULL){
        printf("Key \"%s\" not found for deletion.\n", key_data);
        return root;    
    }
    
    BST temp;
    
    if((*trav)->LC == NULL && (*trav)->RC == NULL){
        *trav = NULL;
        return root;
    } else if((*trav)->LC == NULL || (*trav)->RC == NULL){
        if((*trav)->LC == NULL){
            temp = (*trav)->RC;
        } else {
            temp = (*trav)->LC;
        }
        free(*trav);
        *trav = temp;
        return root;
    } else {
        BST temp = findMin((*trav)->RC);
        strcpy((*trav)->key, temp->key);
        deleteNode((*trav)->RC, temp->key);
    }
    
    return root;
}

int main() {
    // 1. Create and initialize the tree
    BST myTree = NULL;

    printf("--- Building BST for Deletion Test ---\n");
    // Keys: Apple, Banana, Grape, Kiwi, Mango(ROOT), Orange, Pineapple
    insert(&myTree, "Mango");      // Root
    insert(&myTree, "Apple");      // Left of Mango
    insert(&myTree, "Pineapple");  // Right of Mango
    insert(&myTree, "Banana");     // Right of Apple
    insert(&myTree, "Grape");      // Left of Pineapple
    insert(&myTree, "Orange");     // Right of Grape
    insert(&myTree, "Kiwi");       // Left of Orange

    printf("\nInitial In-Order Traversal:\n   ");
    inorderTraversal(myTree);
    printf("\n");

    // --- Deletion Tests ---

    printf("\n--- Test 1: Delete Leaf Node (Kiwi) ---\n");
    // Kiwi is a leaf node (0 children)
    myTree = deleteNode(myTree, "Kiwi");
    printf("Resulting Traversal: ");
    inorderTraversal(myTree);
    printf("\n");

    printf("\n--- Test 2: Delete Node with 1 Child (Apple) ---\n");
    // Apple has 1 child (Banana)
    myTree = deleteNode(myTree, "Apple");
    printf("Resulting Traversal: ");
    inorderTraversal(myTree);
    printf("\n");

    printf("\n--- Test 3: Delete Node with 2 Children (Mango - the Root) ---\n");
    // Mango is replaced by its successor (Orange)
    myTree = deleteNode(myTree, "Mango");
    printf("Resulting Traversal: ");
    inorderTraversal(myTree);
    printf("\n");

    printf("\n--- Test 4: Delete Non-Existent Key (Zebra) ---\n");
    myTree = deleteNode(myTree, "Zebra");
    printf("No change expected: ");
    inorderTraversal(myTree);
    printf("\n");

    // 2. Clean up memory
    destroyTree(myTree);
    printf("\nTree destroyed and memory freed.\n");

    return 0;
}