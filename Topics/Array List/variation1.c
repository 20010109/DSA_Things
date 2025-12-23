#include <stdio.h>
#include <stdlib.h>

#define size 10

typedef struct{
    int elem[size];
    int count;
}List;

List initialize ();
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate (List L, int data);
List insertSorted(List L, int data);
void display(List L);

int main(){
    List L = initialize();
    int num, position;

    // printf("Enter integer: ");
    // scanf("%d", &num);
    // printf("Enter position: ");
    // scanf("%d", &position);
    // L = insertPos(L, num, position);

    L = insertPos(L, 5, 0);
    L = insertPos(L, 10, 1);
    L = insertPos(L, 15, 2);
    L = insertPos(L, 30, 1);
    L = insertPos(L, 100, 9);
    display(L);

    printf("\nAfter Deletion\n");
    L = deletePos(L, 2);
    // L = deletePos(L, 1);
    // L = deletePos(L, 0);
    // L = deletePos(L, 0);
    display(L);

    printf("\nLocate number\n");
    int found = locate(L, 20);
    (found != -1)? printf("Data found on index %d\n", found): printf("Data not found!\n");
    
    display(L);

    printf("\nInsert Sorted\n");
    L = insertSorted(L, 30);
    L = insertSorted(L, 20);
    L = insertSorted(L, 1);
    L = insertSorted(L, 2);
    L = insertSorted(L, 3);
    L = insertSorted(L, 100);
    L = insertSorted(L, 5);
    L = insertSorted(L, 6);
    L = insertSorted(L, 7);
    // test for over count
    // L = insertSorted(L, 8);
    // L = insertSorted(L, 9);
    // L = insertSorted(L, 10);
    // L = insertSorted(L, 11);
    display(L);
    
    printf("\nDeleting!\n");
    
    L = deletePos(L, 2);
    display(L);
}

void display(List L){
    printf("List:\n");
    for(int i = 0; i < size; i++){
        printf("%d ", L.elem[i]);
    }
    printf("\nCount = %d", L.count);
}

List initialize (){
    List L;
    for(int i = 0; i < size; i++){
        L.elem[i] = -1;
    }
    L.count = 0;
    return L;
}

List insertPos(List L, int data, int position){
    int count = L.count;
    if(position <= count && count < size){
        if(L.elem[position] != -1){
            for(int i = size; i > position; i--){
                L.elem[i] = L.elem[i-1];
            }
        }
        L.elem[position] = data;
        L.count = count + 1;
    } else {
        printf("Cannot insert %d at position %d\n", data, position);
    }
    return L;
}

List deletePos(List L, int position){
    int temp, count = L.count;
    if(L.count != 0){
        L.elem[position] = -1;
        for(int i = position; i < size-1; i++){
            // if(L.elem[i] == -1){
            //     break;
            // }
            temp = L.elem[i+1];
            L.elem[i+1] = L.elem[i];
            L.elem[i] = temp;
        }
        L.count = count - 1;
    } else {
        printf("List is empty, cannot delete from position %d\n", position);
    }
    return L;
}

int locate (List L, int data){
    printf("Looking for %d: ", data);
    for(int i = 0; i < size; i++){
        if(L.elem[i] == data && data != -1){
            return i;
        }
    }
    return -1;
}

List insertSorted(List L, int data){
    int count = L.count;
    if(count < size){
        int i = L.count - 1;
        while(i >= 0 && L.elem[i] >= data){
          L.elem[i + 1] = L.elem[i];
          i--;
        }
        L.elem[i + 1] = data;
        L.count = count + 1;
    } else {
        printf("List is full, can not insert %d!\n", data);
    }
    return L;
}