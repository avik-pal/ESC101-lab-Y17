#include<stdio.h>

int GCD(int a, int b)
{
    // Everything divides 0 
    if (a == 0 || b == 0)
       return 1;
 
    // base case
    if (a == b)
        return a;
 
    // a is greater
    if (a > b)
        return GCD(a-b, b);
    return GCD(a, b-a);
}

int main()
{
    int count = 1;
    int n;
    scanf("%d",&n);
    int a,b;
    scanf("%d",&b);
    a = b;
    while(n>1)
    {
        scanf("%d",&b);
        if(GCD(a,b)==1)
            count++;
        else
            count = -1;
        a = b;
        n--;
    }
    printf("%d",count);
    return 0;
}