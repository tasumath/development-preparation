#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main(){
    int height;
    int (*p)[3];

    printf("行数:");
    scanf("%d",&height);

    p = calloc(height,sizeof(int[3]));

    if(p == NULL) puts("記憶域の確保に失敗しました");
    else{
        int i,j;

        for(int i=0;i<height;i++){
            for(int j=0;j<3;j++){
                p[i][j] = 0;
            }
        }
        for(int i=0;i<height;i++){
            for(int j=0;j<3;j++){
                printf("p[%d][%d] = %d\n",i,j,p[i][j]);
            }
        }
        free(p);
    }

    return 0;
}
