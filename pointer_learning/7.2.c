#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main(){
    int *p;

    p = malloc(sizeof(int));

   if(p == NULL){
        puts("記憶域の確保に失敗した");
    }
    else{
        //malloc関数では,毎回不定値を取る
        
        printf("*p + 1 = %d \n",*p + 1);
        printf("*p + 2 = %d \n",*p + 2);
        printf("*p + 3=  %d \n",*p + 3);
        printf("*p + 4=  %d \n",*p + 4);
        printf("sizeof(int)=  %d \n",sizeof(int));

    }
}
