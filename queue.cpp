#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX], front = 0, rear = -1;
void enqueue() {
    if (rear + 1 == MAX) {
        printf("\nQueue Overflow! Cannot enqueue.\n");
    } else {
        int value;
        printf("\nEnter the element to enqueue: ");
        scanf("%d", &value);
        queue[++rear] = value;
        printf("%d enqueued successfully.\n", value);
    }
}
void dequeue() {
    if (front > rear) {
        printf("\nQueue Underflow! No elements to dequeue.\n");
        front = 0;
        rear = -1;
    } else {
        printf("\nDequeued element: %d\n", queue[front++]);
    }
}
void display() {
    if (front > rear)
        printf("\nQueue is empty.\n");
    else {
        printf("\nQueue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
int main() {
    while (1) {
        int choice;
        printf("\nChoose an operation: 1.ENQUEUE  2.DEQUEUE  3.DISPLAY  4.EXIT: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("---------------Before Exit This Queue's Elements are ---------------- ");
                display();
				printf("\nExiting the program. Goodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
}

