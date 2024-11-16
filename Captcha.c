#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define CAPTCHA_LENGTH 6

// Function to generate a random CAPTCHA
void generateCaptcha(char *captcha) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int charset_size = sizeof(charset) - 1;

    for (int i = 0; i < CAPTCHA_LENGTH; i++) {
        int index = rand() % charset_size;
        captcha[i] = charset[index];
    }
    captcha[CAPTCHA_LENGTH] = '\0'; // Null-terminate the string
}

int main() {
    char generatedCaptcha[CAPTCHA_LENGTH + 1];
    char userInput[CAPTCHA_LENGTH + 1];

    // Initialize random number generator
    srand(time(0));

    // Generate CAPTCHA
    generateCaptcha(generatedCaptcha);

    // Display CAPTCHA
    printf("Generated CAPTCHA: %s\n", generatedCaptcha);

    // Prompt user to enter CAPTCHA
    printf("Enter the CAPTCHA: ");
    scanf("%s", userInput);

    // Check if the input matches the CAPTCHA
    if (strcmp(generatedCaptcha, userInput) == 0) {
        printf("CAPTCHA verified successfully!\n");
    } else {
        printf("CAPTCHA verification failed. Please try again.\n");
    }

    return 0;
}
