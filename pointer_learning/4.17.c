#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void put_str(const char *s){
    while(*s){
        putchar(*s);
        s++;
    }
}


int main(){

    char str[128];

    printf("文字列を入力して下さい:");
    scanf("%s",str);

    put_str(str);
    putchar('\n');
}
