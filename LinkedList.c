#include<stdio.h>
#include<stdlib.h>

typedef struct list{
    int data;
    struct list* next;
}node;

node *head, *tail=NULL;
void addnode(int d){
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data =d;
    newnode->next =NULL;
    if(head == NULL){
        head=newnode;
        tail=newnode;
    }else{
        tail->next=newnode;
        tail=newnode;
    }
}
void display(){
    node *cur=head;
    if(head==NULL){
        printf("\nNOW!! LinkedList is Empty..");
        return;
    }else{
        printf("NOW!! Nodes of Single LinkedList are: ");
        while(cur!=NULL){
            printf("%d ",cur->data);
            cur= cur->next;
        }
    }
    printf("\n");
}

int main(){
    int ch;
    while(1){
        printf("\n*************Choose Your Operation *************\n1. Create a Node.\n2. Display Node(s).\n3. Exit From Program.");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                int val;
                printf("\nEnter Your Insert Node's Value:");
                scanf("%d",&val);
                addnode(val);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Good Bye CODER !!!");
                exit(0);
        }
    }

    // addnode(20);
    // addnode(200);
    // display();
    return 0;
}