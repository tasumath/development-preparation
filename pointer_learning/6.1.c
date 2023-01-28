#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main(){
    typedef struct {
        int x;
        long y;
        double z;
    } xyz;

    xyz number;

    number.x = 4536;
    number.y = 45369911;
    number.z = 1.222;

    printf("%p\n",&number.x);
    
    printf("%p\n",&number.y);
    
    printf("%p\n",&number.z);

}
