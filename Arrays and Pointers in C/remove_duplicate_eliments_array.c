#include <stdio.h>

int main() {

    int size, i;
    printf("Enter the size of the array : ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter all the array elements : ");
    for (i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    sortArray(arr);

}

void sortArray(arr){

}