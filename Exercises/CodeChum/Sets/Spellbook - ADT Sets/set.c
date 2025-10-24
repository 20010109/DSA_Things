#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "set.h"

// write your functions here...

// typedef char String[30];
// typedef struct Node {
//     String spell;
//     struct Node* next;
// } Node;

// typedef struct {
//     Node* head;
//     int size;
// }Set;

// Create a new empty set
Set* createSet(){
    Set *S = malloc(sizeof(Set));
    S->head = NULL;
    S->size = 0;
    //printf("Set initialized!\n");
    return S;
}

// Add a spell to the set (no duplicates)
bool addSpell(Set* set, String spell){
    if(containsSpell(set, spell)){
        return false;
    }
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->spell, spell);
    newNode->next = NULL;
    Node* trav = set->head;
    if(set->head == NULL){
        set->head = newNode;
    } else {
        while(trav->next != NULL){
            trav = trav->next;
        }
        trav->next = newNode;
    }
    set->size++;
    //printf("added %s\n", spell);
    return true;
}

// Remove a spell from the set
bool removeSpell(Set** set, String spell){
    Node** trav = &(*set)->head;
    Node* temp;
    if(*trav != NULL){
        while(*trav != NULL && strcmp((*trav)->spell, spell) != 0){
            trav = &(*trav)->next;
        }
        temp = *trav;
        *trav = (*trav)->next;
        free(temp);
        (*set)->size--;
        return true;
    } else {
        return false;
    }
}

// Check if a spell exists in the set
bool containsSpell(Set* set, String spell){
    //printf("in containsSpell function\n");
    Node* trav = set->head;
    while(trav != NULL){
        if(strcmp(trav->spell, spell) == 0){
                //printf("%s found!\n", spell);
                return true;
        }
        trav = trav->next;
    }
    
    return false;
}

// Print all spells in the set
void printSet(Set* set){
    Node* trav = set->head;
    for(int i = 1; trav != NULL; trav = trav->next, i++){
        printf("  %d. %s\n",i , trav->spell);
    }
}

// Free all memory associated with the set
void destroySet(Set* set){
    free(set);
}

Set* unionSets(Set* set1, Set* set2){
    //printf("UnionSets\n");
    Set* uSet = createSet();
    Node* trav;
    
    for (trav = set2->head; trav != NULL; trav = trav->next) {
        if (!containsSpell(set1, trav->spell)) {
            addSpell(uSet, trav->spell);
        }
    }

    // Add all spells from set1 (preserving its order)
    for (trav = set1->head; trav != NULL; trav = trav->next) {
        addSpell(uSet, trav->spell);
    }
    
    
    
    return uSet;
}
Set* intersectSets(Set* set1, Set* set2){
    //printf("IntersectSets\n");
    Set* iSet = createSet();
    Node* trav;
    for(trav = set1->head; trav != NULL; trav = trav->next){
        if(containsSpell(set2, trav->spell)){
            addSpell(iSet, trav->spell);
        }
    }
    return iSet;
}