// WAP to check whether the string is Palindrome or not using Pointer.

#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int n, i;
    printf("Enter size of the string : ");
    scanf("%d", &n);

    char *pStr = (char *) malloc (sizeof(char) * n);
    
    printf("\nEnter the String : ");
    scanf("%[^\n]s", pStr);

    for (i = 0; i < n - 1; i++){
        if (*(pStr + i) != *(pStr + n - 1 - i)){
            printf("\nString is NOT palindrome !");
        }
    }

    

    
}