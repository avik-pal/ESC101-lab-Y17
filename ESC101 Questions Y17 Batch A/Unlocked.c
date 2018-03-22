#include<stdio.h>

int count = 0;

void count_ways(int n, int k)
{
    if(k==1)
        count++;
    else
    {
        k = k-1;
        if(n==1)
        {
            count_ways(2,k);
            count_ways(4,k);
        }
        else if(n==4)
        {
            count_ways(1,k);
            count_ways(5,k);
            count_ways(7,k);
        }
        else if(n==6)
        {
            count_ways(3,k);
            count_ways(5,k);
            count_ways(9,k);
        }
        else if(n==7)
        {
            count_ways(8,k);
            count_ways(4,k);
        }
        else if(n==3)
        {
            count_ways(2,k);
            count_ways(6,k);
        }
        else if(n==9)
        {
            count_ways(6,k);
            count_ways(8,k);
        }
        else if(n==2)
        {
            count_ways(1,k);
            count_ways(5,k);
            count_ways(3,k);
        }
        else if(n==8)
        {
            count_ways(9,k);
            count_ways(5,k);
            count_ways(7,k);
            count_ways(0,k);
        }
        else if(n==5)
        {
            count_ways(2,k);
            count_ways(4,k);
            count_ways(8,k);
            count_ways(6,k);
        }
        else
            count_ways(8,k);
    }
}

int main()
{
    int N, K;
    scanf("%d %d",&N,&K);
    count_ways(N,K);
    printf("%d",count);
    return 0;
}