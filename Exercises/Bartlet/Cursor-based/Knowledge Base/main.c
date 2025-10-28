// Cursor Based

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 20

typedef struct{
    int id;
    char title[64];
    char content[255];
}Article;

typedef struct{
    Article article;
    int next;
}Cell, HeapSpace[MAX];

typedef struct{
    HeapSpace H;
    int avail;
}VHeap;

void initialize(VHeap* VH);
int allocSpace(VHeap* VH);
void deallocSpace(VHeap* VH, int index);
bool insertFirst(VHeap* VH, int* L, Article article);
bool insertLast(VHeap* VH, int* L, Article article);
bool insertPos(VHeap* VH, int* L, Article article, int pos);
void searchArticle(VHeap VH, int L, int ArticleID);
bool deleteArticle(VHeap* VH, int *L, int id);
void display(VHeap VH, int L);

int main(){
    VHeap VH;
    int L = -1;
    initialize(&VH);
    
    Article set[] = {{0,"Homer Simpson", "Doh!"}, {1,"Marge Simpson", "Oh, Homie"}, {2,"Lisa Simpson", "Likes Sax"}, {3,"Bart Simpson", "Eat my shorts!"}};
    insertPos(&VH, &L, set[0], 0);
    insertPos(&VH, &L, set[1], 1);
    insertPos(&VH, &L, set[2], 1);
    insertPos(&VH, &L, set[3], 3);
    
    searchArticle(VH, L, 2);
    
    deleteArticle(&VH, &L, 1);
    
    display(VH, L);
}

void initialize(VHeap* VH){
    for(int i = 0; i < MAX; i++){
        VH->H[i].article.id = -1;
        strcpy(VH->H[i].article.title, "");
        strcpy(VH->H[i].article.content, "");
        VH->H[i].next = i+1;
    }
    VH->H[MAX-1].next = -1;
    VH->avail = 0;
}
int allocSpace(VHeap* VH){
    int ret = VH->avail;
    if(ret != -1){
        VH->avail = VH->H[ret].next;
    } else {
        printf("Unable to Allocate Space.\n");
    }
    return ret;
}
void deallocSpace(VHeap* VH, int index){
    VH->H[index].next = VH->avail;
    VH->avail = index;
}
bool insertFirst(VHeap* VH, int* L, Article article){
    int newCell = allocSpace(VH);
    if(newCell != -1){
        VH->H[newCell].article = article;
        VH->H[newCell].next = *L;
        *L = newCell;
        return true;
    } else {
        printf("Unable to insert first.\n");
        return false;
    }
    
}
bool insertLast(VHeap* VH, int* L, Article article){
    int newCell = allocSpace(VH);
    if(newCell != -1){
        VH->H[newCell].article = article;
        VH->H[newCell].next = -1;
        int *trav = L;
        while(*trav != -1){
            trav = &VH->H[*trav].next;
        }
        *trav = newCell;
    }
}
bool insertPos(VHeap* VH, int* L, Article article, int pos){
    if(pos == 0){
        insertFirst(VH,L,article);
    } else if(pos == MAX-1){
        insertLast(VH,L,article);
    } else {
        int newCell = allocSpace(VH);
        if(newCell != -1){
            VH->H[newCell].article = article;
            int *trav = L;
            for(int i = 0; *trav != -1 && i < pos; trav = &VH->H[i].next, i++){}
            VH->H[newCell].next = *trav;
            *trav = newCell;
        }
    }
}
void searchArticle(VHeap VH, int L, int ArticleID){
    for(int i = 0, trav = L; i < MAX && trav != -1; i++, trav = VH.H[trav].next){
        if(VH.H[trav].article.id == ArticleID){
            printf("%-5s | %-15s | %-20s\n", "ID", "Article title", "Article Content");
            printf("%-5d | %-15s | %-20s\n", VH.H[trav].article.id, VH.H[trav].article.title, VH.H[trav].article.content);
            return;
        }
    }
}
bool deleteArticle(VHeap* VH, int *L, int id){
    int *trav = L;
    for(int i = 0; i < MAX && *trav != -1; i++, trav = &VH->H[*trav].next){
        if(VH->H[*trav].article.id == id){
            int temp = *trav;
            VH->H[*trav].article.id = -1;
            strcpy(VH->H[*trav].article.title, "");
            strcpy(VH->H[*trav].article.content, "");
            *trav = VH->H[*trav].next;
            deallocSpace(VH, temp);
        }
    }
}
void display(VHeap VH, int L){
    printf("\n---Display---\n");
    printf("Avail = %d\n", VH.avail);
    printf("L = %d\n", L);
    printf("%5s | %5s | %-15s | %-5s\n", "Index", "id", "Article title", "Next Index");
    for(int i = 0, trav = L; i < MAX; i++, trav = VH.H[i].next){
        printf("%5d | %5d | %-15s | %-5d\n", i, VH.H[i].article.id, VH.H[i].article.title, VH.H[i].next);
    }
    printf("---End---\n");
    
}
