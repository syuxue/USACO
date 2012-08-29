/*
ID: ymcagod1
LANG: C
PROG: beads
*/

#include<stdio.h>
#include<stdlib.h>
#define MAXBEAD 800

int main () {
    FILE *fin = fopen("beads.in", "r");
    FILE *fout = fopen("beads.out", "w");
    int i, beadCount, maxCount = 0;
    char beads[MAXBEAD];

    fscanf(fin, "%d", &beadCount);
    fscanf(fin, "%s", beads);
    printf("%s\n", beads);

    for (i = 0; i < beadCount; i++) {
        char head = beads[i];
        int count = 0;
        int j;
        int isOriginalHead = 1;
        for (j = 0; j < beadCount; j++) {
            char nextChar = beads[ (i + j) % beadCount ];
            if (head == 'w') {
                head = nextChar;
                count++;
            }
            else if( head ==  nextChar || nextChar == 'w' || isOriginalHead ){
                if(head != nextChar){
                    head = nextChar;
                    isOriginalHead = 0;
                }
                count++;
            }
        }
        printf("@%d:\tcount:%d\thead:%c\n", i, count, head);

        if( count > maxCount)
            maxCount = count;
    }
    printf("%d\n", maxCount);
    exit (0);
}
