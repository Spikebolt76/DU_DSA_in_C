#include <stdio.h>
#include <stdlib.h>

// WAP to get and print the array elements using Pointer.

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *pArr = (int *) malloc (n * sizeof(int));       

    // Input
    for (int i = 0; i < n; i++) {
        printf("pArr[%d] = ", i);
        scanf("%d", pArr + i);
    }

    // Output
    printf("Array elements are: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(pArr + i));
    }
    printf("\n");

    free(pArr);

    return 0;
}
