#include <stdio.h>

int main(){
    char arr[] = ")((())(()";
    int i = 0;
    int count = 0,hm=0;
    while (arr[i] != '\0'){
        if (arr[i] == '(' && arr[i+1] == ')'){
            count++;
        }else if (arr[i] == ')'){
            count--;
            hm++;
        }
        i++;
    }
    if (count == 0){
        printf("Valid");
    }
    else{
        printf("Invalid");
    }
    printf("Valid Parenthesis is: %d",hm);
    return 0;
}