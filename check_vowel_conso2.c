#include <stdio.h>
#include <ctype.h>

void checkVowelOrConsonant(char c) {
    // Convert to lowercase to handle both cases
    c = tolower(c);

    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        printf("'%c' is a vowel.\n", c);
    } else if ((c >= 'a' && c <= 'z')) {
        printf("'%c' is a consonant.\n", c);
    } else {
        printf("'%c' is not a valid alphabet character.\n", c);
    }
}

int main() {
    char c;

    printf("Enter a character: ");
    scanf("%c", &c);

    checkVowelOrConsonant(c);

    return 0;
}
