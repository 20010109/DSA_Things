#include<stdio.h>
#include<string.h>
#include "cldi.h"

String genreTable[16] = {
    "Ballad", "Pop Rock", "Pop", "R&B", "Rock", "Country Pop", "J-Pop", "K-Pop",
    "Classical", "Theater", "EDM", "OPM", "Reggae","Dance", "Jazz",  "Indie"
};

//Write your functions here...

int allocSpace(VirtualHeap *VH){
    int ret = VH->avail;
    if(ret != -1){
        VH->avail = VH->H[ret].next;
    } else {
        printf("RET IS -1.\n");
    }
    return ret;
}

void deallocSpace(VirtualHeap *VH, int index){//USELESS FUNCTION
    //printf("INDEX IS %d.\n", index);
    VH->H[index].next = VH->avail;
    VH->avail = index;
}

void insert(VirtualHeap *VH,Song song){
    int key = hash(song.genre);
    if(strcmp(VH->H[key].elem.songName, "") == 0){
        VH->H[key].elem = song;
    } else {
        int newCell = allocSpace(VH);
        VH->H[newCell].elem = song;
        VH->H[newCell].next = -1;
        if(VH->H[key].next == -1){
            VH->H[key].next = newCell;
        } else {
            int *trav = &VH->H[key].next;
            while(*trav != -1){
                trav = &VH->H[*trav].next;
            }
            *trav = newCell;
        }
        
    }
}

void deleteMember(VirtualHeap *VH,Song song){
    int key = hash(song.genre);
    
    if(strcmp(song.songName, VH->H[key].elem.songName) == 0){
        strcpy(VH->H[key].elem.songName, "");
        strcpy(VH->H[key].elem.singer, "");
        strcpy(VH->H[key].elem.genre, "");
        int *trav = &VH->H[key].next;
        if(*trav != -1){
            VH->H[key].elem = VH->H[*trav].elem;
            VH->H[key].next = VH->H[*trav].next;
            deallocSpace(VH, *trav);
        }
    } else {
        int *trav = &VH->H[key].next;
        while(*trav != -1 && strcmp(song.songName, VH->H[*trav].elem.songName) != 0){
            trav = &VH->H[*trav].next;
        }
        if(*trav != -1){
            //printf("DELETE");
            int temp = *trav;
            strcpy(VH->H[temp].elem.songName, "");
            strcpy(VH->H[temp].elem.singer, "");
            strcpy(VH->H[temp].elem.genre, "");
            *trav = VH->H[temp].next;

            deallocSpace(VH, temp);
        }
    }
}

int search(VirtualHeap VH,Song song){
    int key = hash(song.genre);
    if(strcmp(song.songName, VH.H[key].elem.songName) == 0){
        return 1;
    } else {
        int trav = VH.H[key].next;
        while(trav != -1){
            if(strcmp(song.songName, VH.H[trav].elem.songName) == 0){
                return 1;
            }
            trav = VH.H[trav].next;
        }
    }
    return 0;
}

int hash(String genre){
    for(int i = 0; i < MAX/2; i++){
        if(strcmp(genre, genreTable[i]) == 0){
            return i;
        }
    }
}