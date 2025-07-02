// Read two 2x2 matrices and perform addition of matrices into third matrix and print it.

#include <stdio.h>

int main() {
    int matrix1[2][2];
    int matrix2[2][2];
    int i, j;

    printf("Enter the elements of matrix-1 : \n");
    for(i = 0; i < 2; i++){
        for(j = 0; j < 2; j++){
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter the elements of matrix-2 : \n");
    for(i = 0; i < 2; i++){
        for(j = 0; j < 2; j++){
            scanf("%d", &matrix2[i][j]);
        }
    }

    int matrix3[2][2];
    for(i = 0; i < 2; i++){
        for(j = 0; j < 2; j++){
            matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    printf("Addition of matrix-1 and matrix-2 :- \n");
    for(i = 0; i < 2; i++){
        for(j = 0; j < 2; j++){
            printf("%d ", matrix3[i][j]);
        }
        printf("\n");
    }
}