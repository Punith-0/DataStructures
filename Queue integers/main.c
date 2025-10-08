#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

struct queue{
	int r , f ;
	int data[SIZE];
};
typedef struct queue QUEUE ;

void enqueue(QUEUE *q , int item){
	if(q->r == SIZE -1)
		printf("\nQueue Empty");
	else{
		q->data[++(q->r)] = item ;
		if(q->f = -1)
			q->f = 0 ;
	}
}

void dequeue(QUEUE *q){
	if(q->f == -1)
		printf("\nQueue Full\n ");
	else{
		printf("\nElement deleted is %d ", q->data[q->f]);
		if(q->f == q->r){
			q->f = -1 ;
			q->r = -1 ;
		}
		else
			q->f+= 1;
	}
}

void display(QUEUE q){
	int i ;
	if(q.f == -1)
		printf("\nQueue Empty ");
	else{
		printf("\nThe queue elements are:\n");
		for(i = q.f ; i <= q.r ;i++)
			printf("\n%d\n" , q.data[i]);
	}
}

int main(){
	int ch , item ;
	QUEUE q ;
	q.r = -1 ;
	q.f = -1 ;
	for(;;){
		printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
		printf("\nEnter the choice :");
		scanf("%d", &ch);
		switch(ch){
			case 1:
				printf("\nEnter item to insert :");
				scanf("%d" ,&item);
				enqueue(&q , item);
				break ;
			case 2:
				dequeue(&q);
				break ;
			case 3:
				display(q) ;
				break ;
			default :
				printf("\nExiting\n");
				exit(10);
		}
	}
	return 0;
}

