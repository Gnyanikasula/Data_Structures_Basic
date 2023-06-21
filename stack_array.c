#include <stdio.h>
#include <stdlib.h>

#define max 3

int st[max], top = -1;
void push (int st[],int val);
int pop(int st[]);
int peek(int st[]);
void display(int st[]);

int main()
{
    int val,option;

    do
    {
        printf("\n1. push\n");
        printf("2. pop\n");
        printf("3. peek\n");
        printf("4. display\n");
        printf("5. Exit\n");
        printf("Enter your choice:");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                printf("Enter the value to be pushed:");
                scanf("%d",&val);
                push(st,val);
                break;
             case 2:
                val = pop(st);
                if(val != -1)
                    printf("The value deteled from the stack :%d",val);
                break;
            case 3:
                val = peek(st);
                if(val != -1)
                    printf("The top value is %d ",val);
                break;
            case 4:
                display(st);
                break;
           

        }
    } while (option != 5);
}
void push(int st[],int val)
{
    if(top == max-1)
        printf("Stack is full");
    else 
    {
        top++;
        st[top]=val;

    }        
}
int pop(int st[])
{
    int val;
    if(top == -1)
    {
        printf("Stack is empty ");
        return -1;
    }
    else
    {
        val = st[top];
        top --;
        return val;    
    }
}
int peek(int st[])
{
    if(top ==-1)
    {
        printf("stack is empty ");
        return -1;
    }
    else 
        return st[top];
}
void display(int st[])
{
    if(top == -1)
    {
        printf("Stack is empty!!!!");
    }
    else
    {
        printf("The elements of the stacks are:\n");
        for(int i=top;i>=0;i--)
        {
            
            printf("%d ",st[i]);
        }

    }
}
