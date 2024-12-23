#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;

node *createnode(int d, node *top){
    node *ptr = malloc(sizeof(node)), *head;
    // node *top=NULL;
    ptr->data = d;
    ptr->next = top;
    top = ptr;
    return ptr;
}
node *push(int no, node *top){
    node *ptr = createnode(no, top);
}
node *pop(node *top){
    node *ptr = top;
    if(top==NULL){
        printf("Stack is empty");
    }else{
        top = top->next;
        printf("\n %d element is pop from stack.",ptr->data);
        free(ptr);
    }
    return top;
}

void display(node *top){
    node *ptr = top;
    while(ptr!=NULL){
        printf("[%d| ]-->",ptr->data);
        ptr=ptr->next;
    }
    printf("(NULL)");
}
int main(){
    node *top = NULL;
    int x, ch;

    do{
        printf("\n*****************MENU*****************\n 1.Insert\t2.Delete\t3.Display\t0.Exit\n\n Enter your Choice: ");
        scanf("%d", &ch);
        switch (ch){
        case 1:
            printf("\n Enter the element to be inserted: ");
            scanf("%d", &x);
            top = push(x, top);
            break;
        case 2:
            top=pop(top);
            break;
        case 3:
            display(top);
            break;

        default:
            break;
        }
    } while (ch != 0);
    return 0;
}