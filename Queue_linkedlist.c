#include<stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;
void createQ(struct node**rearref,struct node**frontref,int newvalue)
{
    struct node*r=*rearref;  
    struct node*f = *frontref;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = newvalue;
    if(r == NULL&&f==NULL)
    {
        r=f=newnode;
        r->next = f->next = NULL;
    }
    else{
        r->next = newnode;
        r= newnode;
        r->next = NULL;
    }
    *rearref = r;
    *frontref = f;
}
void delete(struct node**frontref)
{
    struct node*f = *frontref;
    struct node *temp;
    if(f==NULL)
        printf("UNDER FLOW!!!");
    else{
        printf("The value to be deletedis %d",f->data);
        temp = f;
        f= temp->next;
        free(temp);
    } 
    *frontref=f;   
}
void peek(struct node*front)
{
    if(front==NULL)
        printf("EMPTY!!!!");
    else{
        printf("The value is %d\n",front->data);
    }    
}
void display(struct node *front)
{
    struct node*temp = front;
    if(temp==NULL)
        printf("EMPTY!!!!");
    else{
        printf("The values are: ");
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp= temp->next;
        }
    }
}
int main()
{
    int value,option;
    do{
        printf("Enter\n 1.push\n2.delete\n3.peek\n4.display");
        printf("\nEnter your choice:");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                printf("Enter the value:");
                scanf("%d",&value);
                createQ(&rear,&front,value);
                break;
            case 2:
                delete(&front);
                break;
            case 3:
                peek(front);
                break;
            case 4:
                display(front);
                break;
        }

    }while(option!=5);
    return 0;
}