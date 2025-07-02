#include <stdio.h>

int main (){

    int n = 10, i, j;
    int pascal[n][n];

    for(i = 0; i < n; i++){
        for (j = 0; j <= i; j++){
            if(j == 0 || i == j){
                pascal[i][j] = 1;
            }
            else{
                pascal[i][j] = pascal[i - 1][j] + pascal[i - 1][j - 1];
            }
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            printf("   ");
        }
        for (j = 0; j <= i; j++) {
            printf("%3d   ", pascal[i][j]);
        }
        printf("\n");
    }

}