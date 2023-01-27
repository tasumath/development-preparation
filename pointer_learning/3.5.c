#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void fill(int *a,int n1,int n2,int v){
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            a[i * n2 + j] = v;
        }
    }
}


int main(){
    int i,j,no;
    int x[3][2];
    int y[4][3];

    printf("全構成要素に代入する値:");
    scanf("%d",&no);

    fill(&x[0][0],3,2,no);
    fill(&y[0][0],4,3,no);

    puts("--- x ---");

    for(int i=0;i<3;i++){
        for(int j=0;j<2;j++){
            printf("%3d",x[i][j]);
        }
        printf("\n");
    }

    return 0;
}
