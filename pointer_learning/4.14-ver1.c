#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

int str_length(const char s[]){
    
    int len = 0;

    while(s[len] != '\0'){
        len++;
    }

    return len;

}


int main(){

    char str[128];

    printf("文字列を入力して:");
    scanf("%s",str);

    printf("文字列\"%s\"の長さは%dです.\n",str,str_length(str));

    return 0;

}
