// This tower of henoi problem solver will tell u the exact steps to move the //
//discs from source to destination with a temporary pole it works on //
//the concept similar to a temp variable to swap numbers //


#include <stdio.h>
#include <stdlib.h>
void TOH(int n , char s , char d , char t){
	if(n==1)
		printf("\nMove disc %d from %c to %c" , n , s , d);
	else {
		TOH(n-1 , s , t , d);
		printf("\nMove disc %d from %c to %c" , n , s , d );
		TOH(n-1 , t , d , s);
	}
}

int main(){
	int n ;
	printf("\nEnter the number of discs :");
	scanf("%d" ,&n);
	TOH( n , 'S' , 'D' , 'T');
	return 0;
}
