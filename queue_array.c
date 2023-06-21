#include <stdio.h>
#include <stdlib.h>
#define max 3
int q[max];
int front = -1;
int rear = -1;
void insert(int *valueref)
{
    if(rear == max-1)
        printf("OVERFLOW!!");
    else if(front == -1 && rear == -1)
    {
        front =0;
        rear =0;
        q[rear]=*valueref;
    }       
    else{
        rear++;
        q[rear]=*valueref;
    }

}
void delete()
{
    if(front ==-1 || front>rear)
        printf("Under flow!!!");
    else
    {
        printf("The value to be deleted:%d\n",q[front]);
        front++;
        if(front>rear)
            front = rear = -1;    
    }    
}
void peek()
{
    if(front == -1||front>rear)
        printf("Empty!!!");
    else{
        printf("Peek is : %d",q[front]);
    }    
}
void display()
{
    if(front == -1||front>rear)
        printf("Empty!!!");
    else{
        printf("THe elements are : \n");
        for(int i=front;i<=rear;i++)
        {
            printf("%d ",q[i]);
        }
    }    

}
int main()
{
    int value,option;
    do{
        printf("Enter\n1.push\n2.delete\n3.peek\n4.display");
        printf("\nEnter your option:");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                printf("ENter the value to be inserted:");
                scanf("%d",&value);
                insert(&value);
                break;
            case 2:
                delete();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
        }
    }while(option!=5);
}