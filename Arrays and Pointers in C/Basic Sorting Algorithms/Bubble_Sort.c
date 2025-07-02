#include <stdio.h>

int main()
{

    // The outer loop controls how many passes we make through the array.
    int n, i, j, temp, swapped;
    printf("Enter size of the array : ");
    scanf("%d", &n);

    int arr[n];

    printf("\nEnter array elements : ");
    for (i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n - 1; i++){
        swapped = 0;
        for (j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0){
            break;
        }
    }

    printf("\nSorted Array : ");
    for (i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}