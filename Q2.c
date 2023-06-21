#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
void insert(struct node**headref,int newdata)
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
    struct node *temp;
    temp = head;
    while(temp != 0)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct node* rotate(struct node* head,int x)
{
    
    for(int i=1;i<=x;i++)
    {
        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        struct node* t=head->next;
        struct node* p=head;
        while(t->next!=NULL){
            t=t->next;
            p=p->next;
        }
        p->next=NULL;
        newnode->data=t->data;
        newnode->next=head;
        head=newnode;
        free(t);
        display(head);   
    }
    return head;
}




int main()
{
    int a,y;
    int val,i;
    struct node *head = (struct node*)malloc(sizeof(struct node));
    head = NULL;
    insert(&head,1);
    insert(&head,2);
    insert(&head,3);
    insert(&head,4);
    insert(&head,5);
    printf("Enter Roll.no:");
    scanf("%d",&a);
    y = a%10;
    
    display(head);
    printf("\nThe no.of times to be rotated:%d\n",y);
    printf("The rotations are:\n");
    head = rotate(head,y);

}