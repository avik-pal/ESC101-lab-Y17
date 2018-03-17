#include<stdio.h>

int n, x, count=0;

void counter(int num, int sum)
{
    if(sum==x)
    {
        count++;
        return;
    }
    if(num<n && sum<x)
    {
        for(int i=0;i<=n;i++)
        {
            counter(num+1,sum+i);
        }
    }
}

int main()
{
    scanf("%d %d", &n, &x);
    counter(0,0);
    printf("%d",count);
    return 0;
}