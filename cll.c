#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int d;
    struct  Node *next;
    
}node;

node *create(node *head, int i)
{
    node *n;
    n=(node *)malloc(sizeof(node));
    n->d=i;
    n->next=head;
    return n;
}

void main()
{
    int i, n, m=5;
    printf("Enter a number...");
    scanf("%d", &n);
    node *head=create(head, 1);
    head->next=head;
    node *temp, *t;
    temp=head;
    for(i=2; i<=n; i++)
    {
        temp->next=create(head, i);
        temp=temp->next;
    }
    temp=head->next;
    i=2;
    while(head->next!=head)
    {
        if(head->next==head)
        {
            printf("The winner is %d", head->d);
            break;
        }
        if(i==m)
        {
            t=temp->next;
            printf("Deleted %d\n", temp->d);
            free(temp);
            temp=t;
            i=0;
        }
        i++;
        t=temp;
        temp=temp->next;
    }
}