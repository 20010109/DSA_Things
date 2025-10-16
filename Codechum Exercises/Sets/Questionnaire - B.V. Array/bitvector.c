#include <stdio.h>
#include <stdbool.h>
#include "bitvector.h"

// write your funcitons here...

void setAnswer(BitVect* profile, int index, int value){
    profile->answers[index] = value;
}
int getAnswer(BitVect profile, int index){
    return profile.answers[index];
}
int countYesAnswers(BitVect profile){
    int yesCount = 0;
    for(int i = 0; i < 10; i++){
        if(profile.answers[i] == 1){
            yesCount++;
        }
    }
    return yesCount;
}
void printAnswers(BitVect profile){
    for(int i = 9; i >= 0; i--){
        printf("%d", profile.answers[i]);
    }
    printf("\n");
}
int compareProfiles(BitVect a, BitVect b){
    int matchingAnswers = 0;
    for(int i = 0; i < 10; i++){
        if(a.answers[i] == b.answers[i]){
            matchingAnswers++;
        }
    }
    return matchingAnswers;
}

BitVect unionProfiles(BitVect a, BitVect b){
    BitVect c = {0};
    for(int i = 0; i < 10; i++){
        c.answers[i] = (a.answers[i] == 1 || b.answers[i] == 1) ? 1 : 0 ;
    }
    return c;
}
BitVect intersectProfiles(BitVect a, BitVect b){
    BitVect c = {0};
    for(int i = 0; i < 10; i++){
        c.answers[i] = (a.answers[i] == 1 && b.answers[i] == 1) ? 1 : 0 ;
    }
    return c;
}
BitVect differenceProfiles(BitVect a, BitVect b){
    BitVect c = {0};
    for(int i = 0; i < 10; i++){
        c.answers[i] = (a.answers[i] == 1 && b.answers[i] == 0) ? 1 : 0 ;
    }
    return c;
}