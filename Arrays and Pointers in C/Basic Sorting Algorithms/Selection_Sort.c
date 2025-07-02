#include <stdio.h>

int main(){

    int n, i, j;
    printf("Enter size of the array : ");
    scanf("%d", &n);

    int arr[n];

    printf("\nEnter array elements : ");
    for (i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    for (i = n - 1; i >= 0; i--){

        int max_idx = i;
        for (j = i - 1; j >= 0; j--){
            if (arr[j] > arr[max_idx]){
                max_idx = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[max_idx];
        arr[max_idx] = temp;
    }

    printf("\nSorted Array : ");
    for (i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}