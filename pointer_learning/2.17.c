#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int search(int *a,int n,int key){
    
    for(int i=0;i<n;i++){
        if(*a++ == key) return i;
    }
    return -1;
}

int main(){
    
    int key,idx;
    int x[7];
    int x_size = sizeof(x) / sizeof(x[0]);

    for(int i=0;i<7;i++){
        printf("x[%d]:",i);
        scanf("%d",&x[i]);
    }
    printf("探す値は:");
    scanf("%d",&key);

    if((idx = search(x,x_size,key)) == -1) puts("見つかりませんでした");
    else printf("その値をもつ要素はx[%d]です\n",idx);

    return 0;

}
