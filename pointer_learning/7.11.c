#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main(){
    int height,width;
    int **p;

    printf("行数:");
    scanf("%d",&height);
    printf("列数:");
    scanf("%d",&width);
    
    //int型へのポインタ型を要素型とする要素数heightの配列を確保する.先頭要素のポインタをpに代入する.
    p = calloc(height,sizeof(int *));

    if(p == NULL) puts("記憶域の確保に失敗しました");
    else{
        int i,j;
        for(int i=0;i<height;i++){
            p[i] = calloc(width,sizeof(int));
            if(p[i] == NULL){
                puts("記憶域の確保に失敗しました");
                goto Free;
            }
        }
    
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                p[i][j] = 0;
            }
        }
        
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                printf("p[%d][%d] = %d\n",i,j,p[i][j]);
            }
        }
Free:
        for(int i=0;i<height;i++) free(p[i]);
        free(p);
    }
    return 0;

}

