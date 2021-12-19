#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "ex3.h"

int main(){

    char word[30];
    char txt[1024];

    scanf("%s %[^~]",word,txt);

    printf("Gematria Sequences: ");
    gemt(txt,word);
    printf("\nAtbash Sequences: ");
    att(txt,word);
    printf("\nAnagram Sequences: ");
    angram(txt,word);
    return 0;
}