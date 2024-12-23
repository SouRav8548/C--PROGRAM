#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}node;
 
node *create_node(int n){
    node *head=NULL, *temp=NULL, *newNode=NULL;
    for(int i=1; i<=n; i++){
        newNode = (node*)malloc(sizeof(node));
        newNode->data = i;
        newNode->next = NULL;
        if(head == NULL){
            head=newNode;
        }else{
            temp->next=newNode;
        }
        temp=newNode;
    }
    if(temp != NULL){
        temp->next=head;
    }
    return head;
}
node *display(node *head){
    if(head==NULL){
        printf("\n-----------> NOW! Circular Linked List is empty <----------\n");
    }else{
        node *temp = head;
        printf("\n Created circular linked list data is: ");
        do{
            printf("%d ",temp->data);
            temp = temp->next;
        }while(temp!=head);
        printf("\n                ||THANK YOU||                \n");
    }
}
int main(){
    int n;node *head;
    printf("\n How many node you want to create?\n Answer= ");
    scanf("%d",&n);
    if(n<1){
        printf("\n\n Number of Nodes must be greater than 0");
    }else{
        head=create_node(n);
        // head->next = head;
        display(head);
    }
    return 0;
}