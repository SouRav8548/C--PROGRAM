#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int num;
	struct node *next;
}node;
node* create_object(int num){
	node *obj=(node*)malloc(sizeof(int)*40);
	node *obj2=(node*)malloc(sizeof(int)*40);
	obj->num = num;
	obj->next= NULL;
//	obj.next = obj2;
	return obj;
}
int main(){
	node* ptr=create_object(20);
	printf(ptr);
	return 0;
}
