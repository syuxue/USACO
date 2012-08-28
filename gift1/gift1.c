/*
ID: ymcagod1
LANG: C
PROG: gift1
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int search(char keyword[], char friends[][100], int np){
    int i = 0;
    for(i; i < np; i++){
        if(strcmp(keyword, friends[i]) == 0){
            return i;
        }
    }
    // To distinglish from position 0
    return -1;
}
main () {
    int np = 0;
    FILE *fin = fopen("gift1.in", "r");
    FILE *fout = fopen("gift1.out", "w");
    fscanf(fin, "%d", &np);
    char friends[np][100];
    int amounts[np];
    int i = 0;
    // initialize amounts and friends
    for(i = 0; i < np; i++){
        fscanf(fin, "%s", friends[i]);
        amounts[i] = 0;
    }
    for(i = 0; i < np; i++){
        char payer[100], reciever[100];
        int payment, people, j;
        int position;
        fscanf(fin, "%s", payer);
        fscanf(fin, "%d %d", &payment, &people);

        //FIXME:
        position = search(payer, friends, np);
        amounts[position] -= payment;

        for(j = 0; j < people; j++){
            fscanf(fin, "%s", reciever);
            position = search(reciever, friends, np);
            amounts[position] += (payment / people);
            position = search(payer, friends, np);
            amounts[position] -= (payment / people);
        }
    }
    for(i = 0; i < np; i++){
        fprintf(fout, "%s %d\n", friends[i], amounts[i]);
    }
    exit (0);
}
