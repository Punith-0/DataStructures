#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#define SIZE 10
struct stack{
    float top ;
    float data[SIZE]
};
typedef struct stack STACK ;

void push(STACK *s , float item){
    s->data[++(s->top)] = item ;
}

float pop(STACK *s){
    return s->data[(s->top)--];
}

float commute(float opr1 , char symbol , float opr2){
    switch(symbol){
    case '+': return opr1 + opr2 ;
    case '-': return opr1 - opr2 ;
    case '*': return opr1 * opr2 ;
    case '/': return opr1 / opr2 ;
    case '^': return pow(opr1 , opr2);
    }
}

float evaluatepostfix(STACK *s , char postfix[50]){
    int i ;
    float opr1 , opr2 , res ;
    char symbol ;
    for(i = 0 ; postfix[i]!= '\0' ; i++){
        symbol = postfix[i];
        if(isdigit(symbol))
            push(s , symbol-'0');
        else{
            opr2 = pop(s);
            opr1 = pop(s);
            res = commute(opr1 , symbol , opr2);
            push(s , res);
        }
    }
    return pop(s);
}

int main(){
    char postfix[20];
    float ans ;
    STACK s;
    s.top = -1 ;
    printf("\nRead postfix expression :\n");
    scanf("%s" ,postfix);
    ans = evaluatepostfix(&s ,postfix);
    printf("\nThe final result is %f" , ans);
    return 0 ;
}
