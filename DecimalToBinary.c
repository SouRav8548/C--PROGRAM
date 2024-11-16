#include<stdio.h>
#include<string.h>

void reverse(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}
int main() {
    int decimal, index=0;
    char res[32] = "";
    printf("Enter a Decimal Number, which you want to convert into Binary: ");
    scanf("%d", &decimal);
    if (decimal == 0) {
        printf("Binary Number is: 0\n");
        return 0;
    }

    // Convert decimal to binary
    while (decimal != 0) {
        if (decimal % 2 == 1)
            res[index++] = '1';
        else
            res[index++] = '0';
        decimal = decimal / 2;
    }

    res[index] = '\0'; // Null-terminate the string

    // Reverse the binary representation
    reverse(res);

    printf("Binary Number is: %s\n", res);

    return 0;
}
