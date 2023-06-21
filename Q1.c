#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void converter(int n)
{
    int decimal[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1}; 
    char *roman[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};  
    int i = 0;
    while(n)
    { 
        while(n/decimal[i])
        {
            printf("%s",roman[i]);   
            n = n - decimal[i]; 
        }
        i++;   
    }
}

int main(){
    char name[10];
    printf("Enter your Name:");
    scanf("%s",&name);
    int a=0,b=0;
    for(int i=0;i<strlen(name);i++)
    {
        a=a+name[i];
    }
    printf("Enter Roll number:");
    scanf("%d",&b);
    a=a+b;
    printf("Roman format:\n");
    converter(a);
}