#include<stdio.h>
#include<stdlib.h>
#define max 5

int stack[max], top=-1;

void push(){
	if(top+1 == max)
		printf("\nStack Overflow.....");
	else{
		printf("\nEnter your element to be push: ");
		scanf("%d", &stack[++top]);
	}
}
void pop(){
	if(top==-1){
		printf("\nUnderflow....");
	}else{
		printf("\nYour pop element is: %d",stack[top--]);
	}
}
void display(){
	printf("\n-----> Stack Elements are: ");
	for(int i=0;i<=top;i++)
		printf("%d ",stack[i]);
}
int main(){
	while(1){
		int choice;
		printf("\nEnter your choich for operation-- 1.PUSH  2.POP  3.DISPLAY  4.EXIT :: ");
		scanf("%d",&choice);
		switch(choice){
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
				printf("\nExit from program.............");
				return 0;
			default:
				printf("\nEnter Your Valid Option...!!");
		}
	}
}
