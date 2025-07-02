#include <stdio.h>

int main() {

    int rows, i, j;
    printf("Enter the number of rows in pascal triangle : \n");
    scanf("%d", &rows);

    int pascal[rows][rows];

    for (i = 0; i < rows; i++){
        for (j = 0; j <= i; j++){
            if (j == 0 || j == i){
                pascal[i][j] = 1;
            }
            else {
                pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
            }
        }
    }

    printf("Pascal Triangle (%d rows) : \n", rows);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < rows - i - 1; j++) {
            printf("   ");
        }
        for (j = 0; j <= i; j++) {
            printf("%3d   ", pascal[i][j]);
        }
        printf("\n");
    }

    return 0;
}