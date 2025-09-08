#include <stdio.h>

int linearSearch (int target, int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

int main () {
    int n;
    printf("Enter the size of the array : \n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements :\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search :\n");
    int target;
    scanf("%d", &target);
    int result = linearSearch(target, arr, n);
    result == -1 ? printf("element not found!\n") : printf("element found at index = %d\n", result);
    
    
    return 0;
}