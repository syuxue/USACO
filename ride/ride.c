/*
ID: ymcagod1
LANG: C
PROG: ride
*/

#include<stdio.h>
#include<stdlib.h>
main () {
    FILE *fin = fopen("ride.in", "r");
    FILE *fout = fopen("ride.out", "w");
    char comet[7], group[7];
    fscanf (fin, "%s %s", comet, group);
    int i = 0, cometResult = 1, groupResult = 1;
    while(comet[i] != '\0'){
        cometResult *= (comet[i] - 'A' + 1);
        i++;
    }
    i = 0;
    while(group[i] != '\0'){
        groupResult *= (group[i] - 'A' + 1);
        i++;
    }
    if( (cometResult % 47) == (groupResult % 47) )
        fprintf(fout, "GO\n");
    else
        fprintf(fout, "STAY\n");
    exit (0);
}
