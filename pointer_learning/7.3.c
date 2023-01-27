#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main(){
    int no;
    int *p;
    printf("確保する配列の要素数:");
    scanf("%d",&no);

    p = calloc(no,sizeof(int));

    if(p == NULL){
        puts("確保に失敗する");
    }
    else{
        for(int i=0;i<no;i++) p[i] = i;
        for(int i=0;i<no;i++) printf("p[%d] = %d\n",i,p[i]);

        free(p);
    }

    return 0;

}
