#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node*next;
};
void createnode(struct node**headref,int newdata)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    if(*headref==NULL){
        newnode->data=newdata;
        newnode->next=NULL;
        *headref=newnode;
    }
    else
    {
        struct node *temp;
        temp=*headref;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        newnode->data=newdata;
        newnode->next=NULL;
        temp->next=newnode;
    }
}
void display(struct node *head)
{
    struct node*temp;
    if(head==NULL){
        printf("List is empty!!!");
    }
    else{
        temp=head;
        printf("The list is:");
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}




int main()
{
    int n,c,data;
    char z;
    struct node *head = (struct node*)malloc(sizeof(struct node));
    head=NULL;
    printf("Create a linked list:");
    printf("Enter the no.of elements to be entered:");
    scanf("%d",&n);
    printf("%d",n);
    printf("Enter Data:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&data);
        createnode(&head,data);
    }
    display(head);
    printf("Enter 1 for adding element at beginning\nenter 2 for end\nenter 3 for in between\n");
    printf("Your choice:");
    scanf("%d",&c);        
    switch(c)
    {
        case 2:
        {
            int newnum;
            z='y';

            while(z=='y')
            {
                printf("Enter the number:");
                scanf("%d",&newnum);
                createnode(&head,newnum);
                
                printf("Enter 'y' to enter the another number\n 'n' for stop :\n enter :");
                scanf("%s",&z);
                display(head);

            }    
            
        }
    }
}