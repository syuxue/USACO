#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char ans[100] = "David";
    char keyword[100];
    printf("Please enter your word:");
    scanf("%s", keyword);
    printf("Result: %d\n", strcmp(keyword, ans));
    return 0;
}
