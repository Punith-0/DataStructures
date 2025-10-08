#include <stdio.h>
#include <stdlib.h>
#define SIZE 25
struct stack{
	int top ;
	char data[SIZE];
};
typedef struct stack STACK;

void push(STACK* s, char item){
    if (s->top == SIZE-1)
			printf("\nSTACK OVERFLOW");
	else {
		s->data[++(s->top)] = item;
	}
}

char pop(STACK* s){
    if (s->top == -1)
        printf("\nSTACK UNDERFLOW");
	else
		return s->data[(s->top)--] ;
}

//void display(STACK s) {
//    if (s.top == -1) {
//        printf("Stack is empty\n");
 //   } else {
//        printf("Stack contents (top to bottom):\n");
 //       for (int i = s.top; i >= 0; i--) {
  //          printf("%c\n", s.data[i]);
  //      }
 //   }
//}



int main(){
	STACK s1 , s2 , s3 ;
	s1.top = -1	;
	s2.top = -1 ;
	s3.top = -1 ;
	char item[SIZE] , ch;
	int i , pal ;

	printf("\nEnter the string :");
	scanf("%s" , item) ;
	for(i = 0 ; item[i] != '\0' ; i++){
		ch = item[i];
		push(&s1 , ch);
	}
	s2 = s1 ;

	for(i = 0 ; item[i] != '\0' ; i++){
		ch = pop(&s2) ;
		push(&s3 , ch );
	}
	for(i = 0 ; i <= s1.top ; i++){
		 if(s1.data[i] == s3.data[i])
			pal = 1;
		 else
			pal = 0;
	}
	if(pal==1)
		printf("\nPalindrome sequence");
	else
		printf("\nNot an Palindrome sequence");
}

