#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Infinite loop function
void infiniteLoop(int c) {
    while (1) {
        printf("Running infinite loop number...%d.\n",c++);
        Sleep(1000); // Sleep for 1 second (to reduce CPU usage)
    }
}

// Recursive infinite function
void recursiveFunction(int count) {
    printf("Recursion depth: %d\n", count);
    Sleep(100);  // Sleep to slow down recursion
    recursiveFunction(count + 1);
}

int main() {
	int c=1;
    // Create an infinite loop
    printf("Starting infinite loop...\n");

    // Run infinite loop in a separate function
    infiniteLoop(c);

    // Start infinite recursion (this line will never be reached)
    recursiveFunction(1);

    return 0;
}

