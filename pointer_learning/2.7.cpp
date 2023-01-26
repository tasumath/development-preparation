#include<iostream>

void set123(int a[]){
    //void set123(int *a){
    //でも良い
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
}

int main(){
    int i;
    int x[5] = {0};

    set123(x);

    for(int i=0;i<5;i++) printf("x[%d] = %d\n",i,x[i]);

    return 0;
}