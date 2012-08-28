#include<stdio.h>

int main(){
    int day[7], *dayPtr;
    int i, n;
    for(i = 1; i < 8; i++){
        day[i - 1] = i;
    }
    dayPtr = day;
    printf("Please enter n: ");
    scanf("%d", &n);
    dayPtr = day + (n % 7);
    printf("Current location: %d\n", *dayPtr);
    return 0;
}
