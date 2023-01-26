#include<iostream>
#include<vector>
using namespace std;

/*/
void func(int p[]){

    printf("sizeof(p) = %u\n",(unsigned)sizeof(p));

}
/*/


int main(void){
    int a[5];

    printf("要素数は %u\n",(unsigned)sizeof(a)/sizeof(a[0]));

    //func(a);

    return 0;
}