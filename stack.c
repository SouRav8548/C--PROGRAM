#include <stdio.h>
#include <stdlib.h>
#define max 5

int stack[max], top = -1;

void push(){
    int num;
    if (top == max-1){
        printf("Stack Overflow..\n");
    }else{
        printf("Enter your element for push: ");
        scanf("%d", &num);
        stack[++top] = num;
    }
}
void pop(){
    if (top == -1){
        printf("Stack Underflow...");
    }else
        printf("Your pop element is %d \n", stack[top--]);
}
void display(){
    if (top == -1){
        printf("Stack is Empty...\n");
    }else{
        printf("Your Elements are: ");
        for(int i = 0; i <= top; i++)
            printf("%d ", stack[i]);
    }
}

int main(){
    int n;
    while (1){
        printf("\nEnter Your Operation-- 1.Push, 2.Pop, 3.Display, 4.Exit\n");
        scanf("%d", &n);
        switch (n){
        case 1:
             push();
            break;
        case 2:
             pop();
            break;
        case 3:
             display();
            break;
        case 4:
            exit(1);
        default:
            printf("\nEnter a valid option.!!!");
        }
    }
    return 0;
}