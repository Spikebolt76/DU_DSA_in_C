#include "Stack_using_array.h"

int main () {
    printf("Enter the length of the string : \n");
    int size = 0;
    scanf("%d", &size);
    printf("Enter a string : \n");

    char str[size];
    scanf("%s", str);
    printf("%s", str);
    int n = 0;
    for(int i = 0; i != '\n'; i++){
        n++;
    }
    printf("%d", &n);
}