#include <stdio.h>
#include <stdlib.h>

// Define a node in the circular linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a circular linked list with n nodes
Node* createCircularList(int n) {
    Node *head = NULL, *temp = NULL;
    for (int i = 1; i <= n; i++) {
        Node* newNode = createNode(i);
        if (!head) {
            head = newNode;
            newNode->next = head;
        } else {
            temp->next = newNode;
            newNode->next = head;
        }
        temp = newNode;
    }
    return head;
}

// Function to solve the Josephus problem
int josephus(Node* head, int k) {
    Node* prev = NULL;
    Node* current = head;

    // Loop until only one node is left
    while (current->next != current) {
        // Traverse k-1 nodes
        for (int i = 1; i < k; i++) {
            prev = current;
            current = current->next;
        }
        // Remove the k-th node
        prev->next = current->next;
        printf("Eliminated: %d\n", current->data);
        free(current);
        current = prev->next;
    }

    // Return the data of the last remaining node
    int survivor = current->data;
    free(current); // Free the last node
    return survivor;
}

// Main function
int main() {
    int n, k;
    printf("Enter the number of people (n): ");
    scanf("%d", &n);
    printf("Enter the step size (k): ");
    scanf("%d", &k);

    // Create the circular linked list
    Node* head = createCircularList(n);

    // Solve the Josephus problem
    int survivor = josephus(head, k);
    printf("The survivor is at position: %d\n", survivor);

    return 0;
}
