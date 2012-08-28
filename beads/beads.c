/*
ID: ymcagod1
LANG: C
PROG: beads
*/

#include<stdio.h>
#include<stdlib.h>
#define MAXBEAD 800

main () {
    FILE *fin = fopen("beads.in", "r");
    FILE *fout = fopen("beads.out", "w");
    int i, beadCount;
    char beads[MAXBEAD];

    fscanf(fin, "%d", &beadCount);
    fscanf(fin, "%s", beads);
    printf("Count: %d\n", beadCount);
    printf("%s\n", beads);

    // Extend it with same beads twice
    for (i = 0; i < beadCount; i++) {
        beads[beadCount + i] = beads[i];
    }

    for (i = 0; i < beadCount; i++) {
        int c = 1;
    }

    exit (0);
}
