#include <stdio.h>
#include <stdlib.h>

int GCD(int a , int b){
    if(a == 0)
        return b ;
    else
        return GCD(b%a , a);
}
int main(){
    int a , b ;
    printf("\nEnter the numbers :");
    scanf("%d%d", &a , &b);
    printf("\The GCD of %d and %d is %d \n" , a , b , GCD(a , b));
    return 0;
}

