#include <stdio.h>

int main(){
    
    int size, i, j;
    printf("Enter the size of the array : ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter all the array elements : ");
    for (i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    int occurred = 0;

    printf("Duplicated elements : ");
    for (i = 0; i < size; i++){
        for (j = i + 1; j < size; j++){
            if (arr[i] == arr[j]){
                int alreadyPrinted = 0;

                for (int k = 0; k < i; k++) {
                    if (arr[k] == arr[i]) {
                        alreadyPrinted = 1;
                        break;
                    }
                }
                if (!alreadyPrinted) {
                    printf("%d ", arr[i]);
                }
            }
        }
    }
    return 0;
}