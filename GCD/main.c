#include <stdio.h>
#include <stdlib.h>

int GCD(int a ,int b){
    if (a == 0 ) return b ;
    return GCD(b%a , a);
}

int main(){
    int a , b ;
    printf("\nEnter the number a and b :");
    scanf("%d%d" , &a , &b);
    printf("\nThe GCD of %d and %d is %d" , a , b  ,GCD(a ,b));
    return 0 ;
}