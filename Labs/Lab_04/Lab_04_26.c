// Write a program to insert a number in an array that is already sorted in an ascending order.

#include <stdio.h>

int main() {
    int arr[100] = {-5, 12, 21, 33, 39, 99, 107};
    int n = 7;
    int i, elm, index;

    printf("\n Original Array : ");
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Enter the element you want to insert : ");
    scanf("%d", &elm);

    // to find the index where the number can be inserted in sorted array :
    for (i = 0; i < n; i++){
        if (elm <= arr[i]){
            index = i;
            break;
        }
    }

    for(i = n; i > index; i--){
        arr[i] = arr[i-1];
    }
    arr[index] = elm;
    n++;

    printf("Array after insertion: ");
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}