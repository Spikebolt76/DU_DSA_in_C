#include <stdio.h>

int binarySearch(int arr[], int n, int x) {
    int low = 0;
    int high = n-1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] < x)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    printf("Enter element to search : \n");
    int x = 10;
    int result = binarySearch(arr, n, x);
    if(result == -1) printf("Element is not present in array");
    else printf("Element is present at index %d",result);

    return 0;
}