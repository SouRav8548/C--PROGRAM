#include <stdio.h>

int main() {
    char character = 'A'; // Declare a character variable and assign 'a'
    int ascii_value = (int)character; // Cast the character to an integer to get its ASCII value

    printf("The ASCII value of '%c' is: %d\n", character, ascii_value);

    return 0;
}

