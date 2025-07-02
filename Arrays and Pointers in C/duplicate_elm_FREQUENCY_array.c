#include <stdio.h>

// CAN'T INCLUDE NEGATIVE INTEGERS !!

int main(){

    int size, i;
    printf("Enter the size of array : ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter %d elements -\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int maxVal = arr[0];
    for (i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    int freq[maxVal + 1];
    for (i = 0; i <= maxVal; i++) {
        freq[i] = 0;
    }

    for (i = 0; i < size; i++) {
        freq[arr[i]]++;
    }

    printf("Duplicate elements in the array are: ");
    for (i = 0; i <= maxVal; i++) {
        if (freq[i] > 1) {
            printf("%d ", i);
        }
    }

    return 0;
}