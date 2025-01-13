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
}

void displayList(node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("Now List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

node *iab(node *head) {
    int Num;
    node *obj = malloc(sizeof(node));
    printf("\nEnter the element to Insert: ");
    scanf("%d", &Num);
    obj->data = Num;
    obj->next = head;
    printf("\n--------Successfully Entered element %d Insert at Begining.--------", obj->data);
    return obj; 
}

node *iae(node *head) {
    int Num;
    node *obj = malloc(sizeof(node));
    printf("Enter the Element to Insert: ");
    scanf("%d", &Num);
    obj->data = Num;
    obj->next = NULL;  
    if (head == NULL) {
        return obj;  
    }
    node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = obj;  
    printf("\n--------Successfully Entered element %d Insert at End.--------", obj->data);
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
            printf("\n----------------------------->>>>> Link Not Found !!!!!!!!");
        }else{
            obj->data=Num;
            obj->next=temp->next;
            temp->next=obj;
        }
        printf("\n--------Successfully Entered element %d Insert at Location %d.--------", obj->data,loc);
        return head;
    }
}

node *insert(node *head) {
    int ch;
    while (1) {
        printf("\n==============>>Insert Operation.\n  1. Insert at Beginning\t  2. Insert at End\t  3. Insert at Any Position\n 4. Display \t 5. Return..\n\nEnter Your Choice: ");
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
                displayList(head);
            case 5:
            	return head;
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
    node *temp = head;
    head = head->next;
    printf("\n---------Successfully Deleted %d at Beginning.--------\n", temp->data);
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
    printf("\n---------Successfully Deleted %d at End.--------\n", temp->data);
    free(temp);
    return head;
}

node *daap(node *head) {
    int locx, l;
    printf("Enter the location where you delete an element: ");
    scanf("%d", &locx);
    if (locx == 1) {
        return dab(head); 
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
    printf("\n---------Successfully Deleted %d at %d Position.--------\n", to_delete->data, locx);
    temp->next = to_delete->next;
    free(to_delete);
    return head;
}

node *delete(node *head) {
    int o;
    while (1) {
        printf("\n********Delete Operation.\n  1. Delete at Beginning\n  2. Delete at End\n  3. Delete at Any Position\n  4. Display \n 5. Return..\n\n Enter Your Choice: ");
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
            	displayList(head);
            case 5:
                return head;
            default:
                printf("Invalid Choice....!!!!!\n");
        }
    }
}

void searchNode(node* head, int key) {
    int position = 1;
    while (head != NULL) {
        if (head->data == key) {
            printf("\n--------Successfully Searching Element %d found at %d position.--------", key, position);
            return;
        }
        head = head->next;
        position++;
    }
    printf("Element %d not found!\n", key);
}

void sortList(node** head) {
    if (*head == NULL || (*head)->next == NULL) 
        return;
    node *i = *head;
    node *j;
    int temp;
    while (i != NULL) {
        j = i->next;
        while (j != NULL) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
            j = j->next;
        }
        i = i->next;
    }
    printf("\n---------Successfully Sorted Given List!!");
}

void reverseList(node** head) {
    node* prev = NULL;
    node* current = *head;
    node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
    printf("\n--------Successfully Reversed Given List.---------");
}



void concatenateLists(node** head1, node** head2) {
	if (*head1 == NULL && *head2 == NULL) {
        printf("----------------------Both lists are empty! Cannot concatenate.----------------------------\n");
        return;
    } else if (*head1 == NULL) {
        *head1 = *head2;
        return;
    }
    node* temp = *head1;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = *head2;
    *head2 = NULL;
    printf("\n-----Concatenation Successfully Done.-------");
}


int main() {
    int ch, data, click, case1, case2, case3, case4, case5, case6;
    while (1) {
        printf("\n*************CHOOSE YOUR OPERATION FROM THIS MENU*************\n\n");
		printf("1. Create a Node(by append).\t2. Insert a Node.\n3. Delete a Node.\t\t4. Searching a Node.\n5. Sorting the List.\t\t6. Reverse the List.\n7. Concatination two Lists. \n\n8. Display List(s).\t9. Exit From Program.");
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
            	printf("\nReverse List1 click 1 or List2 click 2: ");
                scanf("%d", &case6);
                if (case6 == 1) 
                    reverseList(&head1);
                else if (case6 == 2) 
                    reverseList(&head2);
                else
                    printf("List does not Exist....!!!");
                break;

            case 7:
                concatenateLists(&head1, &head2);
                break;

            case 8:
                printf("\nDisplay for List1 click 1 or List2 click 2: ");
                scanf("%d", &click);
                if (click == 1) 
                    displayList(head1);
                else if (click == 2) 
                    displayList(head2);
                else
                    printf("List does not Exist....!!!");
                
                break;

            case 9:
                printf("\n\n Bye Bye CODER..... \t .....THANK YOU.....");
                exit(0);

            default:
                printf("\nInvalid choice.....!!!\n");
        }
    }
    return 0;
}
