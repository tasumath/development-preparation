#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

//constを付けたらエラー読み取り専用になってしまうため
char *str_cpy(char *s,const char *t){

    char *p = s;
    
    while((*s = *t) != '\0'){
        *s++;
        *t++;
    }
    //printf("%s",s);
    return p;

}



int main(){

    char str[128] = "ABC";
    char tmp[128];
    char cpycpy[128];

    printf("文字列strは%sです\n",str);
    printf("コピーしたい文字列は");
    scanf("%s",cpycpy);

    str_cpy(str,str_cpy(tmp,cpycpy));

    printf("文字列strは\"%s\"です.\n",str);
    
}
