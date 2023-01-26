#include<iostream>
#include<vector>
using namespace std;

//関数間での配列のやりとりでは,配列の先頭要素へのポインタとは別に,その要素数を渡さなければならない.
void func(int *p,int n){

    for(int i=0;i<n;i++) p[i] = 0;

}



int main(void){

    int a[5] = {1,2,3,4,5};
    int i;
    int a_size = sizeof(a) / sizeof(a[0]);

    func(a,a_size);

    for(int i = 0;i < a_size; i++) printf("a[%d] = %d\n",i,a[i]);

    return 0;
}