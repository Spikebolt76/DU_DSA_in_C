#include <stdio.h>
#include <stdlib.h>

// WAP to calculate the sum of n numbers using Pointer.

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *p = malloc(n * sizeof *p);
    if (!p) {
        printf("Memory allocation error\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", p + i);
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += *(p + i);
    }

    printf("Sum = %d\n", sum);
    free(p);
    return 0;
}
