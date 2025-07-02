#include <stdio.h>

int main()
{
    int n, i;
    printf("Enter the size of the array : ");
    scanf("%d", &n);

    int arr[100];

    printf("\nEnter all the elements : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int index;
    printf("\nEnter the index you want to delete that number : ");
    scanf("%d", &index);

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