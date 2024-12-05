#include<stdio.h>

int input(char *s){
    char i;
    printf("%s", s);
    scanf("%c", &i);
    return i;
}
int main(){
    char svowel[5]={'a','e','i','o','u'};
    char cvowel[5]={'A','E','I','O','U'};
    char i=input("Enter a letter: ");
    if (i == svowel[0] || i == cvowel[0] || i == svowel[1] || i == cvowel[1] || i == svowel[2] || i == cvowel[2] || i == svowel[3] || i == cvowel[3] || i == svowel[4] || i == cvowel[4]) {
        printf("The letter is a VOWEL !!!.\n");
    }else if(i >='a' && i<='z'){
        printf("The letter is a CONSONENT.\n");
    }else{
        printf("Invalid input.\n");
    }
    return 0;
}