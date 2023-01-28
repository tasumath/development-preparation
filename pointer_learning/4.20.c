#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

//constを付けたらエラー読み取り専用になってしまうため
void *swap(char **s,char **t){

    char **temp = s;
    *s = *t;
    t = temp;

}



int main(){

    char *s1 = "ABC";
    char *s2 = "ARC";

    printf("文字列strは%sです\n",s1);    
    printf("文字列strは%sです\n",s2);
    
    swap(&s1,&s2);

    puts("ポインタs1とs2を交換しました");

    printf("文字列s1は\"%s\"です\n",s1);
    
    printf("文字列s1は\"%s\"です\n",s2);

    return 0;
    
}
