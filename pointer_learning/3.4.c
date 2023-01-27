#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void fill(int (*a)[3],int n,int v){
    int i,j;
    for(i = 0;i < n; i++){
        for(j = 0;j < 3; j++){
            a[i][j] = v;
        }
    }
}

int main(){
    int i,j,no;
    int x[2][3] = {0};
    int y[4][3] = {0};
    puts("全構成要素に代入する値:");
    scanf("%d",&no);

    fill(x,2,no);
    
    fill(y,4,no);

    puts("--- x ---");
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            printf("%3d",x[i][j]);
        }
        printf("\n");
    }

}
