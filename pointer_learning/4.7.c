#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main(){

    char str[15];

    printf("文字列を入力:");
    scanf("%s",&str);

    printf("あなたは\"%s\"と入力しましたね\n",&str);

    return 0;

}
