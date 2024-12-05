#include <stdio.h>

int n;
int input(char *str) {
    printf(str);
    scanf("%d",&n);
    return n;
}
int main() {
    n=input("which number first you want: ");
    for (int i = 0; i <= n; i++) {
        // Print leading spaces
        for (int j = 0; j < i; j++) {
            printf(" ");
        }
        for (int j = n - i; j >= 0; j--) {  // Print descending numbers
            printf("%d", j);
        }
        for (int j = 1; j <= n - i; j++) {  // Print ascending numbers
            printf("%d", j);
        }
        printf("\n");
    }

    return 0;
}
