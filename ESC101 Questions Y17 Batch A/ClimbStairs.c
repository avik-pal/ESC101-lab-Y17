#include<stdio.h>

int count = 0;

void count_ways(int n)
{
    if(n==0)
    {
        count++;
        return;
    }
    if(n<0)
    {
        return;
    }
    count_ways(n-1);
    count_ways(n-2);
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int n;
        scanf("%d",&n);
        count_ways(n);
        printf("%d\n",count);
        count = 0;
    }
    return 0;
}