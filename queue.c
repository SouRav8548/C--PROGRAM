#include <stdio.h>
#include <stdlib.h>
#define max 5

int stack[max], rear= -1, front=0;

void push(){
    if (rear+1==max){
        printf("Queue Overflow..\n");
    }else{
        printf("Enter your element for push: ");
        scanf("%d", &stack[++rear]);
    }
}
void pop(){
    if (front>rear){
        printf("Queue Underflow...");
        rear=-1;front=0;
    }else
        printf("Your pop element is %d \n",stack[front++]);
}
void display(){
    for(int i=front;i<=rear;i++)
        printf("%d ",stack[i]);
    
}

int main(){
    int n;
    while (1){
        printf("\nEnter Your Operation-- 1.Insert, 2.Delete, 3.Display, 4.Exit\n");
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