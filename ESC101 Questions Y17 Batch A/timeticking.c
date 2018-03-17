#include<stdio.h>

int counter(int n, int m)
{
    if(n==0 && m!=0)
        return 1;
    else if(n==0 && m==0)
        return 1;
    else if(n!=0 && m==0)
        return 0;
    else
    {
        return counter(n-1,m)+2*counter(n,m-1)+counter(n-1,m-1);
    }
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int count = counter(n,m);
    printf("%d",count);
    return 0;
}