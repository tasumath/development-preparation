#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


//calloc関数は,記憶域の全ビットを0で埋める
int main(){

    int *p;

    p = calloc(1,sizeof(int));

    if(p == NULL){
        puts("記憶域の確保に失敗した");
    }
    else{
    
        printf("*p + 1 = %d \n",*p);
        printf("*p + 2 = %d \n",*p);
        printf("*p + 3=  %d \n",*p + 3);
        printf("*p + 4=  %d \n",*p + 4);
        printf("sizeof(int)=  %d \n",sizeof(int));

    }

    return 0;

}
