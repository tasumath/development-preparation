#include<iostream>

int main(){
    int x[5] = {1,4,5,3,2};
    int *p1 = x;//x[0]
    int *p2 = &x[2];

    printf("p1 == x :%d\n",p1 == x);
    printf("p2 == &x[1] :%d\n",p2 == &x[1]);
    printf("&x[2] != &x[3] :%d\n",&x[2] != &x[3]);
    printf("p1 == x :%d\n",&x[1] < &x[2]);
    printf("p1 == x :%d\n",&x[2] <= &x[1]);


    printf("x - &x[1] :%d\n",(int)(x - &x[1]));
    printf("&x[2] - &x[0] :%d\n",(int)(&x[2] - &x[0]));
    printf("&x[4] - p2 :%d\n",(int)(&x[4] - p2));
    printf("x[4] - *p2 :%d\n",(int)(x[4] - *p2));
}