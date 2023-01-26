#include<iostream>
#include<vector>
using namespace std;


void func(int *p){
//void func(int p[]) ではエラーを吐いた.文法的には同じはずだが、、

    printf("sizeof(p) = %u\n",(unsigned)sizeof(p));

}



int main(void){
    int a[5];

    printf("sizeof(a) = %u\n",(unsigned)sizeof(a));

    func(a);

    return 0;
}