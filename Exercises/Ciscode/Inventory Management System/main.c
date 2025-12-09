#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_AISLES 10

typedef struct Product {
    char name[30];
    int quantity;
    struct Product *next;
} Product;

typedef struct {
    Product *aisles[NUM_AISLES];
} Inventory;

void init_inventory(Inventory *inv) {
    for (int i = 0; i < NUM_AISLES; i++) {
        inv->aisles[i] = NULL;
    }
}

int aisle_assignment(const char *name) {
    unsigned int sum = 0;
    for (int i = 0; name[i] != '\0'; i++) {
        sum += name[i];
    }
    return sum % NUM_AISLES;
}


void restock_product(Inventory *inv, char *name, int count) {
   // Implementation here...
    int aisle_key = aisle_assignment(name);

    Product** trav = &inv->aisles[aisle_key];
    Product** head = &inv->aisles[aisle_key];
    if((*head) == NULL){
        Product *newNode = malloc(sizeof(Product));
        strcpy(newNode->name, name);
        newNode->quantity = count;
        *head = newNode;
        return;
    }
    

    while((*trav)->next != NULL && strcmp(name, (*trav)->name) != 0){
        trav = &(*trav)->next;
    }
 
    if(strcmp(name, (*trav)->name) == 0) {
        (*trav)->quantity += count;
        return;
    } else {
        Product *newNode = malloc(sizeof(Product));
        strcpy(newNode->name, name);
        newNode->quantity = count;
        newNode->next = *head;
        *head = newNode;
    }
    return;
}

void discontinue_product(Inventory *inv, char *name) {
    // Implementation here...

    int aisle_key = aisle_assignment(name);

    Product** trav = &inv->aisles[aisle_key];

    while(*trav != NULL && strcmp(name, (*trav)->name) != 0){
        trav = &(*trav)->next;
    }

    if((*trav)->next == NULL){
        Product *temp = *trav;
        *trav = NULL;
        free(temp);
    } else {
        Product *temp = *trav;
        *trav = (*trav)->next;
        free(temp);
    }
  
}

void print_inventory(Inventory *inv) {
    printf("\n--- Current Inventory Levels ---\n");
    for (int i = 0; i < NUM_AISLES; i++) {
        printf("Aisle [%d]: ", i);
        Product *curr = inv->aisles[i];
        if (!curr) {
            printf("(Empty)\n");
            continue;
        }
        while (curr) {
            printf("[%s: %d units] -> ", curr->name, curr->quantity);
            curr = curr->next;
        }
        printf("NULL\n");
    }
}

int main() {
    Inventory supermarket;
    init_inventory(&supermarket);

    printf("1. Receiving Delivery Truck...\n");

    restock_product(&supermarket, "Milk", 50);
    restock_product(&supermarket, "Bread", 20);
    restock_product(&supermarket, "Eggs", 100);
    restock_product(&supermarket, "Apples", 30);
    restock_product(&supermarket, "Biscuits", 150);
  restock_product(&supermarket, "Sugar", 40);
  restock_product(&supermarket, "Salt", 25);
    restock_product(&supermarket, "Meats", 30);
  restock_product(&supermarket, "Ketchup", 40);
  
    print_inventory(&supermarket);

    printf("\n2. Receiving Late Delivery Trucks...\n");

     restock_product(&supermarket, "Milk", 25);
    restock_product(&supermarket, "Eggs", 250);
    restock_product(&supermarket, "Meats", 90);
    restock_product(&supermarket, "Biscuits", 30);
    restock_product(&supermarket, "Salt", 90);
    restock_product(&supermarket, "Sandwich Spread", 40);

    print_inventory(&supermarket);

    printf("\n3. Discontinuing Products...\n");
    discontinue_product(&supermarket, "Bread");
    discontinue_product(&supermarket, "Salt");

    print_inventory(&supermarket);

    return 0;
}
