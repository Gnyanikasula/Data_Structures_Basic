#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
void push(struct node**,int);
void pop(struct node**);
void peek(struct node**);
void display(struct node**);

int main()
{
    int choice,value;
    struct node *top = (struct node*)malloc(sizeof(struct node));
    top = NULL;
    do
    {
        printf("1. push\n");
        printf("2. pop\n");
        printf("3. peek\n");
        printf("4. display");
        printf("5. EXIT");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the value:");
                scanf("%d",&value);
                push(&top,value);
                break;
            case 2:
                pop(&top);
                break;
            case 3:
                peek(&top);
                break;
            case 4:
                display(&top);
                break;                   
        }
    }while(choice!=5);
    return 0;
}
void push(struct node**topref,int newdata)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = newdata;
    if(*topref==NULL)
    {
        newnode->next = NULL;
        *topref = newnode;
    }
    else{
        newnode->next = *topref;
        *topref = newnode;
    }
}
void pop(struct node**topref)
{
    if(*topref == NULL)
        printf("UnderFlow");
    else
    {
        struct node *temp = *topref;
        temp = temp->next;
        *topref = temp;
        free(temp);
    }    
}
void peek(struct node **topref)
{
    if(*topref == NULL)
        printf("Stack is empty");
    else 
    {
        struct node*temp = *topref;
        printf("TOP element is %d\n",temp->data);
    }   
}
void display(struct node**topref)
{
    if(*topref==NULL)
        printf("Stack is empty!!!");
    else{
        struct node*temp = *topref;
        printf("The elements of stack are\n");
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }    

}


