#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node;

node *createNode(int n){
    node *temp=NULL, *head=NULL, *newNode=NULL;
    for(int i=1;i<=n;i++){
        node *newNode = (node*)malloc(sizeof(node));
        printf("Enter the Data of %dth Node: ",i);
        scanf("%d",&newNode->data);
        newNode->next = NULL;
        if(head == NULL){
            head=newNode;
        }else{
            temp->next=newNode;
        }
        temp =newNode;
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
    }
}

node *josephus(node *head, int k){
    node *temp = head, *prev = NULL, *curr = NULL;
    int count = 0;
    if(k==1){
        return head;
    }else{
        while(temp->next != head){
            for (int i = 1; i < k; i++) {
                prev = curr;
                curr = curr->next;
            }
            prev->next = curr->next;
            printf("Eliminated: %d\n", curr->data);
            free(curr);
            curr = prev->next;
        }
        int survivor = curr->data;
        free(curr);
        return survivor;
    }
}
int main(){
    int n,k;node *head;
    printf("How many node you want to create in circular linked list: ");
    scanf("%d",&n);
    head = createNode(n);
    printf("Original Circular Linked List is: ");
    display(head);
    printf("What is the k-th number for select a WINNER node from the Circular Linked List: ");
    scanf("%d",&k);
    head = josephusProblem(head, k);
    display(head);
}