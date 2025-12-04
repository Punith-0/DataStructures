#include <stdio.h>
#include <stdlib.h>

void heapify(int a[], int n) {
    int i, j, k, v , flag  = 0;

    for (i = n / 2; i >= 1; i--) {
        k = i;
        v = a[k];

        while (!flag && 2 * k <= n) {
            j = 2 * k;

            if (j < n ) {
                if( a[j] < a[j + 1])
                    j++;
            }
            if (v >= a[j])
                flag = 1 ;
            else{
                a[k] = a[j];
                k = j;
            }
        }
        a[k] = v;
        flag = 0 ;
    }
}

int main() {
    int a[100];
    int n = 0, i, ch;

    while (1) {
        printf("\n1. Create Heap\n2. Extract\n3. Exit\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            printf("Enter number of elements: ");
            scanf("%d", &n);

            printf("Enter elements:\n");
            for (i = 1; i <= n; i++) {
                printf("Element %d: ", i);
                scanf("%d", &a[i]);
            }

            heapify(a, n);

            printf("Elements after constructing heap: ");
            for (i = 1; i <= n; i++)
                printf("%d ", a[i]);
            printf("\n");
            break;

        case 2:
            if (n >= 1) {
                printf("Element deleted: %d\n", a[1]);
                a[1] = a[n];
                n--;

                heapify(a, n);

                printf("Heap after extraction: ");
                for (i = 1; i <= n; i++)
                    printf("%d ", a[i]);
                printf("\n");
            } 
            else {
                printf("Heap is empty\n");
            }
            break;

        case 3:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }
}
