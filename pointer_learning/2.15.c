#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void fill_zero(int *p,int n){
    while(n --> 0){
        *p = 0;
        p++;
    }
}

int main(){
    int i;
    int x[5] = {1,2,3,4,5};
    int x_size = sizeof(x) / sizeof(x[0]);

    fill_zero(x,x_size);

    for(int i = 0; i < x_size; i++) printf("x[%d] = %d\n",i,x[i]);

    return 0;

}
