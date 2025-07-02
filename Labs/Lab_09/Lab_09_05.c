#include <stdio.h>
#include <stdlib.h>

// WAP to sort the array elements using Pointer.

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *p = malloc(n * sizeof *p);
    if (!p) { return 1; }

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", p + i);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (*(p + j) > *(p + j + 1)) {
                swap(p + j, p + j + 1);
            }
        }
    }

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", *(p + i));
    printf("\n");

    free(p);
    return 0;
}

