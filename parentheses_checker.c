#include <stdio.h>
#include <conio.h>
#include <string.h>
#define max 10
int top= -1;
int stk[max];
void push(char);
char pop();
void main()
{
    char e[max],temp;
    int i,flag=1;
    
    printf("Enter the expression:");
    gets(e);
    for(i=0;i<strlen(e);i++)
    {
        if(e[i]=='('||e[i]=='{'||e[i]=='[')
            push(e[i]);
        if(e[i]==')'||e[i]=='}'||e[i]==']')
            if(top== -1)
                flag=0;
            else{
                temp = pop();
                if(e[i]==')' && (temp=='{'||temp=='['))
                    flag=0;
                if(e[i]=='}' && (temp=='('||temp=='['))
                    flag=0;
                if(e[i]==']' && (temp=='{'||temp=='(')) 
                    flag=0;       
            }        
    }
    if(top>=0)
        flag=0;
    if(flag==1)
        printf("\nValid expression");
    else
        printf("Invalid expression");        

}
void push(char c)
{
    if(top==(max-1))
        printf("Stack Overflow");
    else
    {
        top=top+1;
        stk[top]=c;
    }    
}
char pop()
{
    if(top == -1)
        printf("\nStack Underflow");
    else{
        return(stk[top--]);
    }    
}