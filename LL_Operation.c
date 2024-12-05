#include<stdio.h>
#include<stdlib.h>

typedef struct list {
    int data;
    struct list *next; 
} node;

node *iab(node *head) {
    int Num;
    node *obj = malloc(sizeof(node));
    printf("Enter the element to Insert: ");
    scanf("%d", &Num);
    obj->data = Num;
    obj->next = head;
    return obj;  // Update head to the new node
}

node *iae(node *head) {
    int Num;
    node *obj = malloc(sizeof(node));
    printf("Enter the Element to Insert: ");
    scanf("%d", &Num);
    obj->data = Num;
    obj->next = NULL;  // Set the next pointer to NULL for end insertion
    
    if (head == NULL) {
        return obj;  // If the list is empty, the new node becomes the head
    }

    node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = obj;  // Link the new node at the end
    return head;
}

node *iaap(node *head) {
    int Num,loc,j;
    node *obj=malloc(sizeof(node));
    
    
    node *temp, *i=head;
    if(loc==1){
        head=iab(head);
    }else{
        printf("Enter the Location where to Insert: ");
        scanf("%d",&loc);
        printf("Enter the Element to Insert: ");
        scanf("%d",&Num);
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
}

node *dab(node *head) {
    if (head == NULL) {
        printf("\nNow Linked List is EMPTY...!!!\n");
        return head;
    }

    node *temp = head;
    head = head->next;
    printf("\nDeleted %d at Beginning\n", temp->data);
    free(temp);
    return head;
}

node *dae(node *head) {
    if (head == NULL) {
        printf("\nNow Linked List is EMPTY...!!!\n");
        return head;
    }

    node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("\nDeleted element is %d.\n", temp->data);
    free(temp);
    return head;
}

node *daap(node *head) {
    int locx, l;
    printf("Enter the location where you delete an element: ");
    scanf("%d", &locx);
    
    if (locx == 1) {
        return dab(head);  // Special case for deleting from the beginning
    }

    node *temp = head;
    for (l = 1; l < locx - 1 && temp != NULL; l++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("\nLocation Not Found...\n");
        return head;
    }

    node *to_delete = temp->next;
    printf("\nDeleted Node's Data is %d.\n", to_delete->data);
    temp->next = to_delete->next;
    free(to_delete);
    return head;
}

node *insert(node *head) {
    int o;
    while (1) {
        printf("\n********Insert Operation.\n  1. Insert at Beginning\n  2. Insert at End\n  3. Insert at Any Position\n  4. Return..\n");
        scanf("%d", &o);
        switch (o) {
            case 1:
                head = iab(head);
                break;
            case 2:
                head = iae(head);
                break;
            case 3:
                head = iaap(head);
                break;
            case 4:
                return head;
            default:
                printf("Invalid Choice....!!!!!\n");
        }
    }
}

node *delete(node *head) {
    int o;
    while (1) {
        printf("\n********Delete Operation.\n  1. Delete at Beginning\n  2. Delete at End\n  3. Delete at Any Position\n  4. Return..\n");
        scanf("%d", &o);
        switch (o) {
            case 1:
                head = dab(head);
                break;
            case 2:
                head = dae(head);
                break;
            case 3:
                head = daap(head);
                break;
            case 4:
                return head;
            default:
                printf("Invalid Choice....!!!!!\n");
        }
    }
}

void display(node *head) {
    node *cur = head;
    if (head == NULL) {
        printf("\nNOW!! LinkedList is Empty..\n");
        return;
    }
    printf("NOW!! Nodes of Single LinkedList are: ");
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

int main() {
    int ch;
    node *head = NULL;  // Initialize head as NULL
    while (1) {
        printf("\n*********Main List*********\n 1. Insert\n 2. Delete\n 3. Display\n 4. Exit\n\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                head = insert(head);
                break;
            case 2:
                head = delete(head);
                break;
            case 3:
                display(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Choice..!!!!!\n");
        }
    }
}
