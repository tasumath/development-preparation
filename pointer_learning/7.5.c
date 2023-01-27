#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void func(int *p){
    //void func(int p[])だとエラーになる.C/C++

    printf("sizeof(p) = %u\n",(unsigned)sizeof(p));

    for(int i = 0; i < 5; i++){
        printf("(p+%d) = %d\n",i,*(p+i));
    }

}


int main(){

    int a[5];

    printf("sizeof(a) = %uです.\n",(unsigned)sizeof(a));

    func(a);
    
    return 0;

}
