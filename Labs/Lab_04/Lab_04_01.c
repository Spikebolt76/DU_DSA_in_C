#include <stdio.h>

int main() {
    int n, i;
    printf("Enter the size of the array : ");
    scanf("%d", &n);

    int arr[100]; 

    printf("\nEnter all the elements : ");
    for (i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int elm, index;
    printf("\nEnter the number you want to insert and the index : ");
    scanf("%d %d", &elm, &index);

    if(index < 0 || index > n){
        printf("Invalid index!\n");
        return 1;
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