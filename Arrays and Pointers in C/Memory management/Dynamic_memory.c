// Array is just representation of a data-structure that has contiguous blocks of memory
// under the hood, array is like this : 
// int main(){
//     int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

//     printf("%d", *(arr + 2));  --> same as arr[2]
// }

// Dynamic memory allocation is necessarry when we'd like to extend the size of our block of memory/ array/ data structure, 
// which is not possible in static memory allocation that is done by the compiler, also the stack has a limit

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int n = 5;

    // Allocate memory for an array of 5 integers
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Initialize the array
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    // Print the array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Free the allocated memory
    free(arr);
    arr = NULL; // Avoid dangling pointer
    return 0;
}