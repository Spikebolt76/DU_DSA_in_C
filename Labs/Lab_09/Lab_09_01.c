#include <stdio.h>
#include <stdlib.h>

// Program to allocate and de-allocate memory for int, char, and float arrays at runtime.

int main(){

    int *pInt;
    char *pChar;
    float *pFloat;
    int n;
    printf("Enter the size of your memory chunk (number of ints, floats, chars in array):\n");
    scanf("%d", &n);

    pInt = (int *) malloc (sizeof(int) * n);
    pChar = (char *) malloc (sizeof(char) * n);
    pFloat = (float *) malloc (sizeof(float) * n);

    if (!pInt || !pChar || !pFloat){
        printf("Memory allocation failed!\n");
        
        return 1;
    }
    
    printf("Enter %d integers:\n", n);
    for(int i = 0; i < n; i++){
        scanf("%d", (pInt + i));
    }
    printf("You entered integers: ");
    for(int i = 0; i < n; i++){
        printf("%d ", *(pInt + i));
    }
    printf("\n");

    printf("Enter %d characters:\n", n);
    // Consume leftover newline
    getchar();
    for(int i = 0; i < n; i++){
        scanf(" %c", (pChar + i));
    }
    printf("You entered characters: ");
    for(int i = 0; i < n; i++){
        printf("%c ", *(pChar + i));
    }
    printf("\n");

    printf("Enter %d floats:\n", n);
    for(int i = 0; i < n; i++){
        scanf("%f", (pFloat + i));
    }
    printf("You entered floats: ");
    for(int i = 0; i < n; i++){
        printf("%f ", *(pFloat + i));
    }
    printf("\n");

    // Free allocated memory
    free(pInt);
    free(pChar);
    free(pFloat);

    return 0;
}