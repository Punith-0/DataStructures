#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int row , col , data;
    struct node *next , *prev;
} *NODE;

NODE insertend(NODE start , int row , int col , int item ) {
    NODE temp , cur;
    temp = (NODE)malloc(sizeof(struct node));
    temp -> col = col ;
    temp -> row = row ;
    temp -> next = NULL ;
    temp -> prev = NULL ;
    temp ->data = item ;
    if (start ==  NULL)
        return temp ;
    cur = start ;
    while (cur->next != NULL)
        cur = cur->next ;
    cur->next = temp;
    temp ->prev = cur ;
    return start ;
}

void display(NODE start) {
    NODE temp ;
    if (start == NULL)
        printf("\nList Empty");
    else {
        temp = start ;
        printf("ROW\tCOLUMN\tDATA\n");
        while (temp != NULL) {
            printf("%d\t%d\t%d\n " , temp -> row , temp -> col , temp -> data);
            temp = temp -> next;
        }
    }
}

void displaymatrix(NODE start , int m , int n) {
    NODE temp = start ;
    int i , j ;
    for (i = 1 ; i <=m ; i++) {
        for (j = 1 ; j <= n ; j++) {
            if (temp !=  NULL  && temp->row == i && temp->col == j) {
                printf("%d\t" , temp->data);
                temp = temp ->next ;
            }
            else
                printf("0\t");
        }
        printf("\n");
    }
}

int main(void) {
    int i , j , m , n , item ;
    NODE start = NULL ;
    printf("\nRead order of the matrix :");
    scanf("%d%d" , &m , &n);
    printf("\nRead elements :\n");
    for (i =1 ; i<=m ; i++) {
        for (j = 1 ; j <= n ; j++) {
            scanf("%d" , &item);
            if (item != 0)
                start = insertend(start , i , j , item);
        }
    }
    display(start);
    printf("\nSparsed matrix is \n");
    displaymatrix(start , m , n );
}