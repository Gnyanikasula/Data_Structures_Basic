#include <stdio.h>
#define max 10
void insert(int b[],int *size,int val)
{
    int s;
    s = *size;
    s = s+1;
    b[s]= val;
    int par,pos;
    pos = s;
    if(s == max)
    {
        printf("Inka enni pedathvu ra!!!");
    }
    else{
        while(pos>1)
        {
            par = pos/2;
            if(b[par]>b[pos])
            {
                break;
            }
            else
            {
                pos = par;
            }

        }
    }    
}
void delete(int b[],int s)
{
    int ptr=1,l=2,r=3,t;
    if(s == 0)
    {
        printf("Dobeyy!!!");
    }
    else{
        while(l<=s)
        {
            if(b[ptr]>=b[l] && b[ptr]>=b[r])
            {

            }
            else if (b[r]<=b[l])
            {
                t = b[ptr];
                b[ptr] = b[l];
                b[l] = t;
                ptr = l;
            }
            else{
                t = b[ptr];
                b[ptr] = b[r];
                b[r] = t;
                ptr = r;
            }
            l = 2*ptr;
            r = l + 1;

        }
    }    
}
void display(int b[],int s)
{
    for(int i = 1;i<=s;i++){
        printf("The array is:\n");
        printf("%d ",b[i]);
    }    
}
int main()
{
    int a[max];
    int i,m,option,key,last;
    printf("How many nodes do you want to enter?");
    scanf("%d",&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter\n1. Insert\n 2.delete\n3.display");
    printf("\nEnter your option:");
    scanf("%d",&option);
    do{
        switch(option)
        {
            case 1:
                printf("Enter the value to be inserted:");
                scanf("%d",&key);
                insert(a,&m,key);
                break;
            case 2:
                last = a[m];
                m--;
                a[i] = last;
                delete(a,m);  
                break;  
            case 3:
                display(a,m);
                break;    

        }
    }while(option!=4);    
}