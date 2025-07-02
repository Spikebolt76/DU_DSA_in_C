// Write a program to merge two unsorted arrays.

#include <stdio.h>

void mergeArrays(int arr1[], int size1, int arr2[], int size2, int merged[]) {
    
    for (int i = 0; i < size1; i++) {
        merged[i] = arr1[i];
    }

    for (int i = 0; i < size2; i++) {
        merged[size1 + i] = arr2[i];
    }
}

int main() {
    int size1, size2;
    printf("Enter the sizes of arr1 and arr2 : ");
    scanf("%d %d", &size1, &size2);

    printf("\nEnter the arrays : ");
    printf("\nFor array1 : ");
    int i;
    int arr1[size1], arr2[size2];
    for (i = 0; i < size1; i++){
        scanf("%d", arr1[i]);
    }

    printf("\nFor array2 : ");
    for (i = 0; i < size2; i++){
        scanf("%d", arr2[i]);
    }

    int merged[size1 + size2];

    mergeArrays(arr1, size1, arr2, size2, merged);

    printf("Merged array: ");
    for (int i = 0; i < size1 + size2; i++) {
        printf("%d ", merged[i]);
    }

    return 0;
}
