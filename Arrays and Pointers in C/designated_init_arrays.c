#include <stdio.h>

// Designated initialization of arrays

int main()
{
    // Initialize an array with designated initializers
    int arr[5] = {[0] = 10, [2] = 20, [4] = 30};

    // Print the array elements
    for (int i = 0; i < 5; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    // If we don't mention the size of the array in a designated initialization,
    // then compiler will deduce the size automatically from the largest designator in the list.

    // Example of automatic size deduction

    printf("\nAutomatic size deduction example:\n");

    int arr2[] = {[0] = 1, [3] = 4, [5] = 6}; // Size is deduced to be 6
                                              // This is valid in C11 and later standards, where designated initializers are supported.
    for (int i = 0; i < 6; i++)
    {
        printf("arr2[%d] = %d\n", i, arr2[i]);
    }

    int arr3[] = {1, 7, 5, [2] = 3, [5] = 9, 4, 6}; // Size is deduced to be 8

    //note that 5 was ignored and 3 was assigned to index 2, because you later explicitly assigned a value to arr3[2] using [2] = 3. 
    //The positional 5 was initially set at index 2, but the designated initializer overrides that.
    printf("\narr3 with mixed initialization:\n");  
    for (int i = 0; i < 8; i++)
    {
        printf("arr3[%d] = %d\n", i, arr3[i]);
    }
    return 0;
}
