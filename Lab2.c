#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int i,j;
    long double a = 0; 
    float f[5] = {3,4,5};
    float v[5] = {1,1.5,2};
    long double t[3] = {1000000,1000001,1000002};
    long double e[3][3];
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            e[i][j] = t[i]/f[j];
        }
    }
    for(j=0;j<3;j++)
    {
        for(i=0;i<3;i++)
        {
            a = a + e[i][j]*v[i]*v[i]*f[i];
        }
    }
    printf("Total is:%ld",a);


}