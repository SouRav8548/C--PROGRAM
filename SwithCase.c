#include <stdio.h>
int main()
{
    int a, b;
    char ch;
    printf("Enter your value :");
    scanf("%d %d", &a, &b);
    printf("Enter the number :");
    scanf("%c", &ch);
    switch (ch)
    {
    case '+':
        printf("Addition :%d", a + b);
        break;
    case '-':
        printf("Subtruction :%d", a - b);
        break;
    case '*':
        printf("Multiplication :%d", a * b);
        break;
    case '/':
        printf("division :%d", a / b);
        break;
    default:
        printf("Wrong operation!!!");
    }
    return 0;
}