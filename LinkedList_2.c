#include<stdio.h>
#include<stdlib.h>

typedef struct list{
    int data;
    struct list* next;
}node;

// node *head, *tail=NULL;
node *getnode(){
    node *head=(node*)malloc(sizeof(node));
    return head;
}
node *createList(){
    node *head=NULL, *p, *q;
    int ch=1;
    while(ch==1){
        p=getnode();
        printf("Enter Data: ");
        scanf("%d",&p->data);
        p->next=NULL;

        if(head==NULL){
            head=p;
            q=p;
        }else{
            q->next=p;
            q=p;
        }
        printf("Press 1 to Continue, any value to exit.....");
        scanf("%d",&ch);
    }
    return head;

//     newnode->data =d;
//     newnode->next =NULL;
//     if(head == NULL){
//         head=newnode;
//         tail=newnode;
//     }else{
//         tail->next=newnode;
//         tail=newnode;
//     }
}
void display(node *head){
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
int input(char *s){
    int i;
    printf("%s",s);
    scanf("%d", &i);
    return i;
}
int main(){
    node *head;
    int ch;
    while(1){
        printf("\n*************Choose Your Operation*************\n1. Create a Node.\n2. Display Node(s).\n3. Exit From Program.\n");
        ch=input("Enter Your Choice: ");

        switch(ch){
            case 1:
                // int val;
                // printf("\nEnter Your Insert Node's Value:");
                // scanf("%d",&val);
                // addnode(val);
                head=createList();
                break;
            case 2:
                display(head);
                break;
            case 3:
                printf("Good Bye CODER !!!\n\n\n");
                exit(0);
        }
    }

    // addnode(20);
    // addnode(200);
    // display();
    return 0;
}