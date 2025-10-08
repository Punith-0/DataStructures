#include <stdio.h>
#include <stdlib.h>
#define SIZE 25
int data[SIZE] ;
int top = -1;

void push(int item){
    if (top == SIZE-1)
        printf("\nSTACK OVERFLOW");
    else{
        top += 1 ;
        data[top] = item ;
    }
}

void pop(){
    if (top == -1)
        printf("\nSTACK UNDERFLOW");
    else{
        printf("\nElement popped is %d\n ", data[top]);
        top -= 1 ;
    }
}
void display(){
    int i ;
    if (top == -1)
        printf("\nEmpty Stack");
    else{
        printf("\nThe stack contents are :");
        for(i = top ; i >= 0 ; i --)
            printf("\n%d\n", data[i]);
    }
}
int main()
{
    int ch , item ;
    for(;;){
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("\nEnter choice :");
        scanf("%d", &ch);
        switch(ch){
        case 1 :
            printf("\nRead Elements to push :");
            scanf("%d", &item);
            push(item);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break ;
        default :
            exit(0);
        }
    }
    return 0 ;
}
