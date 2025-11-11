#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef unsigned int CompWord;

void setAnswer(CompWord *profile, int index, int answer);
int getAnswer(CompWord profile, int index);
void printProfile(CompWord profile, int numQuestions);
int countYes(CompWord profile, int numQuestions);
CompWord combineProfiles(CompWord p1, CompWord p2);
CompWord intersectProfiles(CompWord p1, CompWord p2);
CompWord differenceProfiles(CompWord p1, CompWord p2);

int main() {
    CompWord A = 0, B = 0;

    // Set answers for Person A
    setAnswer(&A, 0, 1);
    setAnswer(&A, 1, 0);
    setAnswer(&A, 2, 1);
    setAnswer(&A, 3, 1);
    setAnswer(&A, 4, 0);
    setAnswer(&A, 5, 0);
    setAnswer(&A, 6, 0);
    setAnswer(&A, 7, 0);

    // Set answers for Person B
    setAnswer(&B, 0, 0);
    setAnswer(&B, 1, 1);
    setAnswer(&B, 2, 1);
    setAnswer(&B, 3, 0);
    setAnswer(&B, 4, 1);
    setAnswer(&B, 5, 0);
    setAnswer(&B, 6, 1);
    setAnswer(&B, 7, 0);

    printf("Profile A: ");
    printProfile(A, 8);

    printf("Profile B: ");
    printProfile(B, 8);

    printf("\nA Yes count: %d\n", countYes(A, 8));
    printf("B Yes count: %d\n", countYes(B, 8));

    CompWord C = differenceProfiles(A, B);
    printf("\nCombined Profile: ");
    printProfile(C, 8);

    return 0;
}

void setAnswer(CompWord *profile, int index, int answer){
    if(index < 8){
        unsigned int mask = answer << index;
        *profile = *profile | mask;
        //printf("Answer inserted.\n");
    } else {
        //printf("Answer failed to insert.\n");
    }

}
int getAnswer(CompWord profile, int index){
    return (profile >> index) & 1 ? 1 : 0; 
}
void printProfile(CompWord profile, int numQuestions){
    printf("Displaying profile:\n");
    for(int i = numQuestions-1; i >= 0; i--){
        printf("%d", getAnswer(profile, i));
    }
    printf("\n");
}
int countYes(CompWord profile, int numQuestions){
    int yesCount = 0;
    for(int i = 0; i < numQuestions; i++){
        if((profile >> i) & 1){
            yesCount++;
        }
    }
    return yesCount;
}
CompWord combineProfiles(CompWord p1, CompWord p2){
    return p1 | p2;
}

CompWord intersectProfiles(CompWord p1, CompWord p2){
    return p1 & p2;
}

CompWord differenceProfiles(CompWord p1, CompWord p2){
    return p1 & ~p2;
}

