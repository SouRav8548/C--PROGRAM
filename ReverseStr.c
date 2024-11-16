#include<stdio.h>
#include<string.h>
int main(){
    // int n=3;
    // // scanf("%d", &n);
    // printf("%d is %s", n, !(n%2)?"even":"odd");
    char s[]="sourav";
    int i, temp;
    for(i=0; i<(strlen(s)/2); i++)
    {
        temp=s[i];
        s[i]=s[strlen(s)-1-i];
        s[strlen(s)-1-i]=temp;
    }
}