#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<string.h>

//char str_lenでは駄目.
char *str_len(const char *s){
    char *p; 
    p= malloc(strlen(s) + 1);
    return (p == NULL) ? NULL : strcpy(p,s);
} 


int main(){
    char x[128];
    char *a;

    printf("文字列sを入力してください:");
    scanf("%s",x);

    a = str_len(x);

    printf("%s",a);

    free(a);

    return 0;
}

