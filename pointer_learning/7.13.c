#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<string.h>

int main(){
    char s[128];
    char *p;

    printf("文字列sを入力してください:");
    scanf("%s",s);

    p = malloc(strlen(s) + 1);

    if(p){
        strcpy(p,s);
        printf("その文字列のクーロンpを作りました\n");
        printf("%s\n",s);
        printf("%s\n",p);
        free(p);
    }

    return 0;
}

