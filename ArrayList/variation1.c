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
    display(L);

    printf("\nAfter Deletion\n");
    L = deletePos(L, 1);
    display(L);

    printf("\nLocate number\n");
    int found = locate(L, 20);
    if(found != -1){
        printf("Data found on index %d\n", found);
    } else {
        printf("Data not found!\n");
    }
    display(L);

    printf("\nInsert Sorted\n");
    L = insertSorted(L, 30);
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
    if(L.count < size){
        if(L.elem[position] == -1){
            L.count++;
        }
        L.elem[position] = data;
    }
    return L;
}

List deletePos(List L, int position){
    L.elem[position] = -1;
    L.count--;
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
    int temp = 0, max;
    for(int i = 0; i < size; i++){
        if(L.elem[i] > data){
            temp = L.elem[i];
            L.elem[i] = data;
            for(int j = i; j < size-1; j++){
                
            }
        }
        
    }
    return L;
}