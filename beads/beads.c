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

    // Scan each char
    for (i = 0; i < beadCount; i++) {
        char head = beads[i];
        int count = 0;
        int j;

        // This is an identifier for turning into another color. r -> b or b -> r
        int isOriginalHead = 1;

        // From a specific postion(beads[i]) to go down
        for (j = 0; j < beadCount; j++) {

            // Circling count. Because it is counted from 0, the first nextChar will be itself.
            // As a result, the logic( count++ ) will be correct. The (int)count is "like" starting from 1.
            char nextChar = beads[ (i + j) % beadCount ];
            if (head == 'w') {
                head = nextChar;
                count++;
            }
            // Make sure it only turns into another color once. (except white)
            else if( head ==  nextChar || nextChar == 'w' || isOriginalHead ){
                // If it came from the reason that isOriginalHead is true, then marking used.
                if( nextChar != 'w' && head != nextChar){
                    head = nextChar;
                    isOriginalHead = 0;
                }
                count++;
            }
            // Third condition is that meeting to the third times of changing color.
            // Then, it should break out of the loop.
            else{
                break;
            }
        }

        if( count > maxCount)
            maxCount = count;
    }
    fprintf(fout, "%d\n", maxCount);
    exit (0);
}
