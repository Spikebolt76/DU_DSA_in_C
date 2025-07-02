#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 100

/*
Design anagram game using array.
• Allow user to enter N words and store it in an array.
• Generate a random number between 0 to N-1.
• Based on the random number generated display the word stored at that index of an array and allow user to enter its anagram.
• Check whether the word entered by the user is an anagram of displayed number or not and display an appropriate message.
• Given a word A and word B. B is said to be an anagram of A if and only if the characters present in B is same as characters present in A, irrespective of their sequence. For ex: “LISTEN” == “SILENT”
*/
int main(){
    int n, i;
    printf("Enter the number of words you want to store : \n");
    scanf("%d", &n);

    char words[n][LEN];

    printf("Enter those words : \n");
    for (i = 0; i < n; i++){
        scanf("%s", words[i]);
    }

    int rnd_num = rand() % n;
    // printf("%d", rnd_num);

    char rnd_word[100];
    strcpy(rnd_word, words[rnd_num]);
    printf("Word stored at the index that is randomly generated = %s\n", rnd_word);

    char anagram[100];
    printf("Enter its anagram : ");
    scanf("%s", &anagram);
    
    int freq_arr[26] = {0};

    if (strlen(rnd_word) != strlen(anagram)) {
        printf("The entered string is NOT ANAGRAM!");
        return 0;
    }

    for (i = 0; i < strlen(rnd_word); i++){
        freq_arr[rnd_word[i] - 'a']++;
        freq_arr[anagram[i] - 'a']--;
    }
    
    for (i = 0; i < 26; i++){
        if (freq_arr[i] != 0){
            printf("The entered string is NOT ANAGRAM!");
            return 0;
        }
    }
    printf("The entered string is ANAGRAM!\n");
    
}