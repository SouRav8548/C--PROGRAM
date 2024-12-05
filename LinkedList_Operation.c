#include<stdio.h>
#include<stdlib.h>


typedef struct list{
    int data;
    struct list *next; 
}node;

node *iab(node *head){
    int Num;
    node *obj=malloc(sizeof(node));
    printf("Enter the element to Insert: ");
    scanf("%d",&Num);
    obj->data=Num;
    obj->next=head;
    return head;
}
node *iae(node *head){
    int Num;
    node *obj=malloc(sizeof(node));
    printf("Enter the Element to Insert: ");
    scanf("%d",&Num);
    if(head->next==NULL){
        printf("\nNow Linked List is EMPTY...!!!");
    }else{
        obj->data;
        head->next=obj;
    }
    return head;
}
node *iaap(node *head){
    int Num,loc,j;
    node *obj=malloc(sizeof(node));
    printf("Enter the Element to Insert: ");
    scanf("%d",&Num);
    printf("Enter the Location where to Insert: ");
    scanf("%d",&loc);
    node *temp, *i=head;
    for(j=1;j!=loc && i!=NULL ;j++, i=i->next){
        temp=i;
    }
    if(j!=loc && i==NULL){
        printf("\nLink Not Found");
    }else{
        obj->data=Num;
        obj->next=temp->next;
        temp->next=obj;
        }
    return head;
}
node *dab(node *head){
    if(head==NULL){
        printf("\nNow Linked List is EMPTY...!!!");
    }else{
        node *temp=head;
        head=head->next;
        printf("\nDelete %d at Begining",(temp->data));
        free(temp);
    }
    return head;
}
node *dae(node *head){
    node *i=head, *temp;
    while(head->next!=NULL){
        node *temp=head;
        head=head->next;
    }
    printf("\nDeleted element is %d.",&(temp->data));
    temp->next=NULL;
}
node *daap(node *head){
    node *i=head, *temp;
    int locx,l;
    printf("Enter the location where you delete a element: ");
    scanf("%d",&locx);
    for(l=1;l!=locx && i!=NULL;l++){
        temp=i;
        i=i->next;
    }
    if(i==NULL){
        printf("\nLocation Not Found...");
    }else{
        printf("\nDeleted Node's Data is %d.",(i->data));
        temp->next=i->next;
        free(i);
    }
}
node *insert(node *head){
    int o;
    while(1){
        printf("\n********Insert Operation.\n   1. Insert at Begining\n 2. Insert at end\n  3. Insert at any Position\n 4. Return..\n");
        scanf("%d",&o);
        switch(o){
            case 1:
                iab(head);
                break;
            case 2:
                iae(head);
                break;
            case 3:
                iaap(head);
                break;
            case 4:
                return head;
            default:
                printf("Invalid Choice....!!!!!");
        }
    }
}

node *delete(node *head){
    int o;
    while(1){
        printf("\n********Delete Operation.\n   1. Delete at Begining\n 2. Delete at end\n  3. Delete at any Position\n 4. Return..\n");
        scanf("%d",&o);
        switch(o){
            case 1:
                head=dab(head);
                break;
            case 2:
                head=dae(head);
                break;
            case 3:
                head=daap(head);
                break;
            case 4:
                return head;
            default:
                printf("Invalid Choice....!!!!!");
        }
    }
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

int main(){
    int ch;
    node *head;
    while(1){
        printf("\n*********Main List*********\n 1. Insert\n 2. Delete\n 3. Display\n 4. Exit\n\n Enter your choich: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                head=insert(head);
                break;
            case 2:
                head=delete(head);
                break;
            case 3:
                display(head);
                break;
            case 4: 
                exit(1);
            default:
                printf("Invalid Choich..!!!!!");
        }
    }
}