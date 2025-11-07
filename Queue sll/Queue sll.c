#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data ;
    struct node *addr ;
} *NODE;


NODE insertend(NODE start , int item) {
    NODE temp ;
    temp = (NODE)malloc(sizeof(NODE));
    temp -> data = item ;
    temp -> addr = NULL ;
    if (start == NULL) {
        return temp ;
    }
    else {
        NODE cur = start ;
        while (cur -> addr != NULL) {
            cur = cur->addr ;
        }
        cur-> addr = temp ;
    }
    return start ;
}

NODE deletebegin(NODE start) {
    NODE temp ;
    if (start == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    temp = start ;
    start = start->addr ;
    printf("\nNode Deleted is %d " , temp->data);
    free(temp);
    return start ;
}


void display(NODE start) {
    NODE cur ;
    if (start == NULL) {
        printf("List is empty\n");
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
        printf("\n\n--- Queue Menu ---");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item to enqueue: ");
                scanf("%d", &item);
                start = insertend(start, item);
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
