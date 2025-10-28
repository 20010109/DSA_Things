#include <stdio.h>
#include <stdlib.h>

#define MAX 31

/*********************************/
/*    USER-DEFINED DATA TYPES    */
/*********************************/
typedef struct node {
    int key;           // index in array
    int val;           // element value
    struct node* link;
} *LIST;

typedef LIST Dictionary[MAX];

/*********************************/
/*       HELPER FUNCTIONS        */
/*********************************/
void initDict(Dictionary D);

/*********************************/
/*          YOUR TASKS           */
/*********************************/
void insert(Dictionary D, int data, int index);
int* twoSum(int* nums, int numsSize, int target, int* returnSize);
int hash(int elem);
LIST createNode(int data, int index);

int main(void) {
    int n, target;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int* nums = (int*)malloc(n * sizeof(int));
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    printf("Enter target: ");
    scanf("%d", &target);

    int returnSize;
    int* result = twoSum(nums, n, target, &returnSize);

    if (result != NULL) {
        printf("Indices: [%d, %d]\n", result[0], result[1]);
        free(result);
    } else {
        printf("No solution found.\n");
    }

    free(nums);
    return 0;
}

/*********************************/
/*       HELPER FUNCTIONS        */
/*********************************/
void initDict(Dictionary D) {
    for (int i = 0; i < MAX; i++) {
        D[i] = NULL;
    }
}

/*********************************/
/*          YOUR TASKS           */
/*********************************/
void insert(Dictionary D, int data, int index) {
    // TODO: Implementation here
    LIST newNode = createNode(data, index);
    int hashKey = hash(data);
    if(D[hashKey] == NULL){
        D[hashKey] = newNode;
        //printf("Inserted first %d\n", data);
    } else {
        LIST trav = D[hashKey];
        while (trav->link != NULL) {
            trav = trav->link;
        }
        trav->link = newNode;

        //printf("Inserted last %d\n", data);
    }
}

LIST createNode(int data, int index){
    LIST newNode = malloc(sizeof(struct node));
    newNode->key = index;
    newNode->val = data;
    newNode->link = NULL;
    
    //printf("NODE CREATED");

    return newNode;
}

void display(Dictionary D, int numsSize){
    for(int i = 0; i < MAX; i++){
        if(D[i] != NULL){
            printf("%d | %d ", D[i]->key, D[i]->val);
            if(D[i]->link != NULL){
                LIST *trav = &D[i];
                for(; *trav != NULL; trav = &(*trav)->link){
                    printf("-> %d ", (*trav)->val);
                }
            }
            printf("\n");
        }
    }
}

int findNum(Dictionary D, int elem){
    //printf("IN FINDNUM\n");
    int hashKey = hash(elem);
    if(D[hashKey] != NULL){
        LIST *trav = &D[hashKey];
        while(*trav != NULL){
            if((*trav)->val == elem){
                //printf("found = %d\n", (*trav)->val);
                return (*trav)->key;
            }
            trav = &(*trav)->link;
        }
    }
    return -1;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // TODO: Implementation here
    if(numsSize > 0){
        Dictionary D;
        initDict(D);
        int* result = (int*)malloc(sizeof(int) * 2);
        *returnSize = 2;
        
        for(int i = 0; i < numsSize; i++){
            //printf(" in %d iteration\n", i);
            int complement = target - nums[i];
            int find = findNum(D, complement);
            //printf("root = %d find = %d\n", i, find);
                
            if (find != -1 && find != i) {
                result[0] = find;
                result[1] = i;
                return result;
            }       
            insert(D, nums[i], i);
        }
            
  
        //display(D, numsSize);
    }
  
    return NULL;
}

int hash(int elem) {
    // TODO: Implementation here
    // if(elem >= 0){
    //     //printf("hash = %d\n", elem % MAX);
    //     return elem % MAX;
    // } else {
    //     //printf("hash = %d\n", (elem * -1) % MAX);
    //     return (elem * -1) % MAX;
    // }
    return abs(elem) % MAX;
}
