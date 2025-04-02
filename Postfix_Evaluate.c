#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAX 100

struct Stack {
    int top;
    double items[MAX];
};

void initStack(struct Stack* s) {
    s->top = -1;
}

int isEmpty(struct Stack* s) {
    return s->top == -1;
}

void push(struct Stack* s, double value) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow!\n");
        exit(1);
    }
    s->items[++(s->top)] = value;
}

double pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        exit(1);
    }
    return s->items[(s->top)--];
}

double evaluatePostfix(char* postfix) {
    struct Stack stack;
    initStack(&stack);
    int i = 0;

    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            double num = 0;
            while (isdigit(postfix[i])) {  
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            push(&stack, num);
        }
        else if (postfix[i] == '+' || postfix[i] == '-' || 
                 postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^') {
            double val2 = pop(&stack);
            double val1 = pop(&stack);
            switch (postfix[i]) {
                case '+': push(&stack, val1 + val2); break;
                case '-': push(&stack, val1 - val2); break;
                case '*': push(&stack, val1 * val2); break;
                case '/': 
                    if (val2 == 0) {
                        printf("Error: Division by zero!\n");
                        exit(1);
                    }
                    push(&stack, val1 / val2); 
                    break;
                case '^': push(&stack, pow(val1, val2)); break;
            }
        }
        i++;
    }
    return pop(&stack);
}

int main() {
    char postfix[MAX];

    printf("\nEnter a valid postfix expression (Operands separated by spaces): ");
    fgets(postfix, MAX, stdin);

    double result = evaluatePostfix(postfix);
    
    printf("\n Result of Postfix Evaluation: %.2f\n", result);

    return 0;
}
