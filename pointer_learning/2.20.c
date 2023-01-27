#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

void print(const int **a,int no){
    //constとするとエラーになる.←解決した.呼び出す側のint *pをconst int *pに変更するべきだった.
    for(int i=0;i<no;i++) printf("p[%d] = %p *p[%d]=%d\n",i,a[i],i,*a[i]);
}


int main(){
    int a=5,b=3,c=7;
    const int *p[3];

    p[0]=&a;
    p[1]=&b;
    p[2]=&c;

    printf("&a=%p a=%d\n",&a,a);
    
    printf("&b=%p b=%d\n",&b,b);
    
    printf("&c=%p c=%d\n",&c,c);

    print(p,3);

    return 0;

}
