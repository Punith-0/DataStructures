#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data ;
    struct node *addr ;
} *NODE;

NODE insertbegin(NODE start , int item) {
    NODE temp ;
    temp = (NODE)malloc(sizeof(NODE));
    temp -> data = item ;
    temp -> addr = start ;
    return temp ;
}

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

NODE deleteend(NODE start) {
    NODE cur , pre ;
    if (start == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    cur = start->addr ;
    while (cur->addr != NULL) {
        pre = cur ;
        cur = cur -> addr ;
    }
    pre -> addr = NULL ;
    printf("\nThe deleted item is %d" , cur->data);
    free(cur);
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
    printf("\n\n--- Singly Linked List Menu ---\n");
    while (1) {

        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item to insert at beginning: ");
                scanf("%d", &item);
                start = insertbegin(start, item);
                break;
            case 2:
                printf("Enter item to insert at end: ");
                scanf("%d", &item);
                start = insertend(start, item);
                break;
            case 3:
                start = deletebegin(start);
                break;
            case 4:
                start = deleteend(start);
                break;
            case 5:
                display(start);
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
