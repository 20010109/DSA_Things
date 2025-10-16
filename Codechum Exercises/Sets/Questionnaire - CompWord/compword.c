#include <stdio.h>
#include <stdbool.h>
#include "compword.h"

// write your functions here...

void setAnswer(CompWord* profile, int index, int value){
    *profile |= (value << index);
    //printf("%d", *profile);
}
int getAnswer(CompWord profile, int index){
    return (profile >> index) & 1;
}
int countYesAnswers(CompWord profile){
    int yesCount = 0;
    for(int i = 0; i < 10; i++){
        if((profile >> i) & 1){
            yesCount++;
        }
    }
    return yesCount;
}
void printAnswers(CompWord profile){
    for(int i = 9; i >= 0; i--){
        printf("%d", (profile >> i) & 1);
    }
    printf("\n");
}
int compareProfiles(CompWord a, CompWord b){
    int matchingAnswers = 0;
    for(int i = 0; i < 10; i++){
        if(!((getAnswer(a, i) == 1) ^ (getAnswer(b, i) == 1))){
            matchingAnswers++;
        }
    }
    return matchingAnswers;
}

CompWord unionProfiles(CompWord a, CompWord b){
    return a | b;
}
CompWord intersectProfiles(CompWord a, CompWord b){
    return a & b;
}
CompWord differenceProfiles(CompWord a, CompWord b){
    return a & ~b;
}