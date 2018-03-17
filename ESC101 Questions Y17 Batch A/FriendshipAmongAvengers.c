#include<stdio.h>

int im(int n)
{
    if(n==0)
        return 1;
    return n - ca(n-1);
}

int ca(int n)
{
    if(n==0)
        return 1;
    return n - 2*im(n-1);
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",im(n));
    return 0;
}