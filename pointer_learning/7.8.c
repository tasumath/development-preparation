#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main(void){
    int n1;
    int *p;

    printf("確保する配列の要素数:");
    scanf("%d",&n1);

    p = calloc(n1,sizeof(int));

    if(p == NULL) puts("記憶域の確保に失敗しました");
    else{
        int i,n2;
        int no = n1;
        for(int i=0;i<n1;i++) p[i] = i;

        printf("要素数をいくつにしますか");
        scanf("%d",&n2);

        p = realloc(p,n2 * sizeof(int));

        if(p == NULL) puts("確保に失敗した");
        else{
            for(int i=n1;i<n2;i++) p[i] = i;
            no = n2;
        }
        for(int i=0;i<no;i++) printf("p[%d] = %d\n",i,p[i]);
        free(p);
    }
    return 0;

}
