#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

struct Stack {
    int top;
    char items[MAX];
};

void initStack(struct Stack* s) {
    s->top = -1;
}

int isEmpty(struct Stack* s) {
    return s->top == -1;
}

void push(struct Stack* s, char ch) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow!\n");
        exit(1);
    }
    s->items[++(s->top)] = ch;
}

char pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        exit(1);
    }
    return s->items[(s->top)--];
}

char peek(struct Stack* s) {
    return s->items[s->top];
}

int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

int isLeftAssociative(char op) {
    return (op != '^');
}

void infixToPostfix(char* infix, char* postfix) {
    struct Stack stack;
    initStack(&stack);
    int i = 0, j = 0;
    while (infix[i] != '\0') {
        char ch = infix[i];
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        else if (ch == '(') {
            push(&stack, ch);
        }
        else if (ch == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            if (!isEmpty(&stack) && peek(&stack) == '(') {
                pop(&stack);
            }
        }
        else {
            while (!isEmpty(&stack) && precedence(peek(&stack)) > precedence(ch) ||
                   (!isEmpty(&stack) && precedence(peek(&stack)) == precedence(ch) && isLeftAssociative(ch))) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, ch);
        }
        i++;
    }
    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }
    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}

