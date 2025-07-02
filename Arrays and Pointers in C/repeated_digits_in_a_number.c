// Write a program to check wherther any of the digits in a number is repeated or not.

#include <stdio.h>

void main() {
    int freq_arr[10] = {0};
    int num, i;

    printf("Enter a number : ");
    scanf("%d", &num);

    int temp = num;
    while (temp > 0){
        freq_arr[temp % 10]++;
        temp /= 10;
    }

    printf("repeated digits in number %d : \n", num);

    for (i = 0; i < 10; i++){
        if (freq_arr[i] > 1){
            printf("digit : %d, times repeated : %d\n", i, freq_arr[i] - 1);
        }
    }
}