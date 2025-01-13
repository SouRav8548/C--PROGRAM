#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}node;

node* head = NULL; node* head2 = NULL; node* head1 = NULL;

node *getnode(){
    node *head=(node*)malloc(sizeof(node));
    return head;
}


node *createList(){
    node *head= NULL;
    node *p, *q;
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
        p->next=head;
        printf("Press 1 to Continue, any value to exit.....");
        scanf("%d",&ch);
    }
    return p;
}

void displayList(node *head){
    node *cur=head->next;
    if(head==NULL){
        printf("\nNOW!! LinkedList is Empty..");
    }else{
        printf("NOW!! Nodes of Circular LinkedList are: ");
        while(cur!=head){
            printf("%d ",cur->data);
            cur= cur->next;
        }
        printf("%d %d",cur->data,cur->next->data);
    }
    printf("\n");
}

node * Nnode(int Num){
    node *nn;
    nn=getnode();
    nn->data=Num;
    nn->next=NULL;
    return nn;
}

node *iab(node *head) {
    int Num;
    printf("\nEnter the element to Insert: ");
    scanf("%d", &Num);
    node *Newnode= Nnode(Num);
    if(head == NULL){
        head=Newnode;
        head->next=head;
    }else{
        Newnode->next=head->next;
        head->next=Newnode;
    }
    printf("\n--------Successfully Entered element %d Insert at Begining.--------", Newnode->data);
    return head; 
}

node *iae(node *head) {
    int Num;
    printf("Enter the Element to Insert: ");
    scanf("%d", &Num);
    node *Newnode= Nnode(Num);
    if (head == NULL) {
        head=Newnode;
        head->next=head;
    }else{
        Newnode->next=head->next;
        head->next=Newnode;
    }
    head=Newnode;  
    printf("\n--------Successfully Entered element %d Insert at End.--------", Newnode->data);
    return head;
}

node *iaap(node *head) {
    int Num,loc,j;
    node *temp, *i=head->next;

    printf("Enter the Location where to Insert: ");
    scanf("%d",&loc);
    printf("Enter the Element to Insert: ");
    scanf("%d",&Num);
    node *Newnode= Nnode(Num);
    if(loc==1){
        Newnode->next=head->next;
        head->next=Newnode;
    }else{
        for(j=1;j<loc && i!=head;j++, i=i->next){
            temp=i;
        }
        if(i!=head){
            Newnode->next=i;
            temp->next=Newnode;
        }else if(j==loc){
            Newnode->next=head;
            temp->next=Newnode;
        }else if(j!=loc && i==head){
            Newnode->next=head->next;
            head->next=Newnode;
            head=Newnode;
        }else{
            printf("\nLink Not Found");
        }
        printf("\n--------Successfully Entered element %d Insert at Location %d.--------", Newnode->data,loc);
        return head;
    }
}

node *insert(node *head) {
    int ch;
    while (1) {
        printf("\n==============>>Insert Operation.\n  1. Insert at Beginning\t  2. Insert at End\t  3. Insert at Any Position\n 4. Return..\n 5. Display\n\nEnter Your Choice: ");
        scanf("%d", &ch);
        switch (ch) {
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
            case 5:
            	displayList(head);
            default:
                printf("Invalid Choice....!!!!!\n");
        }
    }
}

node *dab(node *head) {
    if (head == NULL) {
        printf("\nNow Linked List is EMPTY...!!!\n");
        return head;
    }
    node *temp = head->next;
    head->next = temp->next;
    printf("\n---------Successfully Deleted %d at Beginning.--------\n", temp->data);
    free(temp);    
    return head;
}

node *dae(node *head) {
    if (head == NULL) {
        printf("\nNow Linked List is EMPTY...!!!\n");
        return head;
    }
    node *temp = head->next;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next=head->next;
    printf("\n---------Successfully Deleted %d at End.--------\n", head->data);
    free(head);
    return temp;
}

node *daap(node *head) {
    int locx, l;
    printf("Enter the location where you delete an element: ");
    scanf("%d", &locx);
    if (locx == 1) {
        node *temp = head->next;
        head->next = temp->next;
        printf("\n---------Successfully Deleted %d at Beginning.--------\n", temp->data);
        free(temp);    
        return head; 
    }
    node *temp = head->next, *i;
    for (l = 1; l < locx && temp != head; l++) {
        i=temp;
        temp = temp->next;
    }
    if (temp == head && l==locx) {
        i->next=temp->next;
        printf("\n---------Successfully Deleted %d at %d Location.--------\n", temp->data, locx);
        free(head);
        return i;
    }else if(temp!=head){
        i->next=temp->next;
        printf("\n---------Successfully Deleted %d at %d location.--------\n", temp->data, locx);
        free(temp);
        return head;
    }else{
        printf("\nLocation Not Found...\n");
        return head;
    }
}

node *delete(node *head) {
    int o;
    while (1) {
        printf("\n********Delete Operation.\n  1. Delete at Beginning\n  2. Delete at End\n  3. Delete at Any Position\n  4. Return..\n 5. Display\n\nEnter your Choice: ");
        scanf("%d", &o);
        switch (o) {
            case 1:
                head = dab(head);   //Delete at Begining
                break;
            case 2:
                head = dae(head);
                break;
            case 3:
                head = daap(head);
                break;
            case 4:
                return head;
            case 5:
            	displayList(head);
            default:
                printf("Invalid Choice....!!!!!\n");
        }
    }
}

void searchNode(node *head, int key) {
    int position = 1;
    if (head == NULL) {
        printf("\n==========>> The Linked List is EMPTY!!!\n");
        return;
    }else{
    	node *current = head->next;
    	do {
        	if (current->data == key) {
            	printf("\n-------- Successfully found element %d at position %d. --------\n", key, position);
            	return; 
        	}
        	position++;
        	current = current->next;
    	} while (current != head);
	    printf("\n---------- Element %d not found in the list. ----------\n", key);
	}
}

void sortList(node **head) {
    if ((*head) == NULL || (*head)->next == (*head)) {
    	printf("\n=========>> Linked List is Now EMPTY <<=========\n\n");
        return;
    }
    node* current, *index;
    int temp;

    
    for (current = (*head)->next; current->next != (*head)->next; current = current->next) {
        for (index = current->next; index != (*head)->next; index = index->next) {
            if (current->data > index->data) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
        }
    }
    printf("\n=========>> Linked List Now Already SORTED <<=========\n\n");
}

void concatenateLists(node** head1, node** head2) {
	char ch;
    if (head == NULL && head2 == NULL) {
        printf("----------------------Both lists are empty! Cannot concatenate.----------------------------\n");
        return;
    }
    if (*head1 == NULL) {
        *head1 = *head2;
        return;
    }
    node* temp = (*head1)->next;
    (*head1)->next = (*head2)->next;
    (*head2)->next=temp;

    printf("\n-----Concatenation Successfully Done.-------");
    displayList(*head2);
}

int main() {
    int ch, data, click, case1, case2, case3, case4, case5, case6;
    while (1) {
        printf("\n*************CHOOSE YOUR OPERATION FROM THIS MENU*************\n\n");
		printf("1. Create a Node(by append).\t2. Insert a Node.\n3. Delete a Node.\t\t4. Searching a Node.\n5. Sorting the List.\t\t6. Concatination two Lists. \n\n7. Display List(s).\t8. Exit From Program.");
        printf("\n\nEnter Your Choice: ");
		scanf("%d",&ch);
        
        switch (ch) {
            case 1:
            	printf("\nCreate List1 click 1 or List2 click 2: ");
                scanf("%d", &case1);
                if (case1 == 1) 
                    head1 = createList();
                else if (case1 == 2) 
                    head2 = createList();
                else
                    printf("List does not Exist....!!!");
                break;

            case 2:
            	printf("\nInsert into List1 click 1 or List2 click 2: ");
                scanf("%d", &case2);
                if (case2 == 1) 
                    head1 = insert(head1);
                else if (case2 == 2) 
                    head2 = insert(head2);
                else
                    printf("List does not Exist....!!!");
                break;

            case 3:
            	printf("\nDelete from List1 click 1 or List2 click 2: ");
                scanf("%d", &case3);
                if (case3 == 1) 
                    head1 = delete(head1);
                else if (case3 == 2) 
                    head2 = delete(head2);
                else
                    printf("List does not Exist....!!!");
                break;
                

             case 4:
             	printf("\nSearching on List1 click 1 or List2 click 2: ");
             	scanf("%d", &case4);
                printf("\nEnter key to search: ");
                scanf("%d", &data);
                if(case4 == 1){
                 	searchNode(head1, data);
			 	}else if(case4 == 2){
			 		searchNode(head2, data);
			 	}else{
			 		printf("List does not Exist....!!!");
			 	}
                 break;

             case 5:
             	printf("\nSorting for List1 click 1 or List2 click 2: ");
                scanf("%d", &case5);
                if (case5 == 1) 
                    sortList(&head1);
                else if (case5 == 2) 
                    sortList(&head2);
                else
                    printf("List does not Exist....!!!");
                break;

            case 6:
                concatenateLists(&head1, &head2);
                break;

            case 7:
                printf("\nDisplay for List1 click 1 or List2 click 2: ");
                scanf("%d", &click);
                if (click == 1) 
                    displayList(head1);

                else if (click == 2) 
                    displayList(head2);
                else
                    printf("List does not Exist....!!!");
                
                break;

            case 8:
                printf("\n\n Bye Bye CODER..... \t .....THANK YOU.....");
                exit(0);

            default:
                printf("\nInvalid choice.....!!!\n");
        }
    }
    return 0;
}
