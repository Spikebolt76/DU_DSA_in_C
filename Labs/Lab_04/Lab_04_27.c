// Write a program to delete a number from an array that is already sorted in an ascending order.
#include <stdio.h>

int main()
{
    int arr[100] = {-5, 12, 21, 33, 39, 99, 107};
    int n = 7;
    int i, elm, index;

    printf("\n Original Array : ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Enter the number you want to delete : ");
    scanf("%d", &elm);

    // to find the index where to delete the numebr 
    int found = 0;
    for (i = 0; i < n; i++){
        if (elm == arr[i]){
            index = i;
            found = 1;
            break;
        }
    }
    if (found = 0){
        printf("\nThe number does not exist in the given array!");
        return 0;
    } 

    for (i = index; i < n - 1; i++){
        arr[i] = arr[i + 1];
    }

    printf("Array after deletion: ");
    for(i = 0; i < n - 1; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}