#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *addr;
} *NODE;

NODE insertbegin(NODE start , int item) {
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->data = item ;
    temp->addr = start ;
    return temp ;
}

NODE deletebegin(NODE start) {
    if (start == NULL) {
        printf("\nStack is empty") ;
        return NULL ;
    }
    NODE temp = start;
    start = start->addr ;
    printf("\nThe deleted item is %d" , temp->data);
    free(temp);
    return start ;
}


void display(NODE start) {
    NODE cur ;
    if (start == NULL) {
        printf("\nStack is empty") ;
        return ;
    }
    else {
        printf("\nThe elements are :\n");
        cur = start ;
        while (cur != NULL) {
            printf("\n%d ", cur->data);
            cur = cur->addr;
        }
    }
}
int main() {
    NODE start = NULL;
    int choice, item;

    while (1) {
        printf("\n\n--- Stack Menu ---");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item to push: ");
                scanf("%d", &item);
                start = insertbegin(start, item);
                break;
            case 2:
                start = deletebegin(start);
                break;
            case 3:
                display(start);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.");
        }
    }

    return 0;
}