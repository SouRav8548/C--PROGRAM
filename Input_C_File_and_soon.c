#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void count_lines(const char *filename, int *total_lines, int *blank_lines, int *single_digit_lines) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);-
    }

    char line[1024];
    *total_lines = 0;
    *blank_lines = 0;
    *single_digit_lines = 0;

    while (fgets(line, sizeof(line), file)) {
        (*total_lines)++;
        
        // Remove leading spaces to check for blank lines or single character lines
        int i = 0;
        while (line[i] != '\0' && isspace(line[i])) {
            i++;
        }

        // Check for blank lines
        if (line[i] == '\0' || line[i] == '\n') {
            (*blank_lines)++;
        } 
        // Check for single character lines
        else if (line[i] != '\0' && line[i+1] == '\n') {
            (*single_digit_lines)++;
        }
    }

    fclose(file);
}

int main() {
    char filename[256];
    int total_lines, blank_lines, single_digit_lines;

    printf("Enter the filename: ");
    scanf("%255s", filename);

    count_lines(filename, &total_lines, &blank_lines, &single_digit_lines);

    printf("Total lines: %d\n", total_lines);
    printf("Blank lines: %d\n", blank_lines);
    printf("Single-character lines: %d\n", single_digit_lines);

    return 0;
}