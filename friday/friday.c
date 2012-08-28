/*
ID: ymcagod1
LANG: C
PROG: friday
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int daysCalculate(year, month){
    if(month == 2){
        // leap years
        if( (year % 4 == 0) && ( (year % 100 != 0) || (year % 400 == 0) ) )
            return 29;
        else
            return 28;
    }
    else if(month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else
        return 31;
}

main () {
    FILE *fin = fopen("friday.in", "r");
    FILE *fout = fopen("friday.out", "w");
    int n, year, month, days, date;
    int day[7], *dayPtr;
    int i, count = 0;

    for(i = 0; i < 7; i++){
        day[i] = 0;
    }
    dayPtr = day;
    
    fscanf(fin, "%d", &n);
    for(year = 1900; year < 1900 + n; year++){
        for(month = 1; month <= 12; month++){
            days = daysCalculate(year, month);
            for(date = 1; date <= days; date++){
                dayPtr = day + (count % 7);
                if( date == 13 ){
                    (*dayPtr)++;
                }
                count++;
            }
        }
    }
    // Output starts from Sat.
    for(i = 5; i < 12; i++){
        if(i == 11)
            fprintf(fout, "%d\n", day[i % 7]);
        else
            fprintf(fout, "%d ", day[i % 7]);
    }
    exit (0);
}
