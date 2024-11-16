#include <stdio.h>
#include <string.h>

void findsubstring(char str[], char sub[]);
int main(){
    char str[100], sub[] = "ab";
    printf("Enter Your String: ");
    scanf("%s", &str);
    findsubstring(str, sub);
    return 0;
}

void findsubstring(char str[], char sub[]){
    char *position = strstr(str, sub);
    int size = strlen(str);
    if(size>4){
        if (position != NULL){
            printf("The Substring %s is found at position: %ld", sub, position-str+1);
        }else{
            printf("The substring %s is not found.", sub);
        }
    }else{
        printf("The string required minimum 5 characters !!!");
    }
}