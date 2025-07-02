#include <stdio.h>

int main(){

    int n, i, j, key;
    printf("Enter size of the array : ");
    scanf("%d", &n);

    int arr[n];

    printf("\nEnter array elements : ");
    for (i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    for (i = 1; i < n; i++){

        key = arr[i];
        j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    

    printf("\nSorted Array : ");
    for (i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}