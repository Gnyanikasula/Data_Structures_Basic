#include <stdio.h>
#include <stdlib.h>

#define max 3

int st[max], top = -1;

int pop(int st[]);
int peek(int st[]);
void display(int st[]);

int main()
{
    int val,option,i;
    printf("Enter the expression:");
    for(i=0;i<max;i++)
    {
        scanf("%d",&st[i]);
    }
    display(st);

}
