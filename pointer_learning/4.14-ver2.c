#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

int str_length(const char *s){
    
    const char *p = s;

    //printf("%c",p[0]);
    
    while(*s){
        s++;
    }
    
    //printf("%d",s-p);
    
    return s - p;

}


int main(){

    char str1[128];
    
    char str2[21];

    printf("文字列を入力して:");
    scanf("%s",str1);

    printf("文字列を入力して:");
    scanf("%s",str2);

    printf("文字列\"%s\"の長さは%dです.\n",str1,str_length(str1));
    printf("文字列\"%s\"の長さは%dです.\n",str2,str_length(str2));

    return 0;

}
