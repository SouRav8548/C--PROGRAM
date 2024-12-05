#include<stdio.h>
int ch;
int input(char *str) {
    printf(str);
    scanf("%d",&ch);
    return ch;
}

int main() {
    ch=input("Enter a number: ");
//    printf(ch);		//without format specifer delay running(without output)
    printf("%d",ch);	//without format specifer regular run(with output)
    return 0;
}
