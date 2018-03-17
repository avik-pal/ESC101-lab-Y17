#include<stdio.h>

int N,D;

int count_splits(int n)
{
    //printf("%d\n",n);
    if(n==1)
        return 0;
    if(n*N/D==0 || n*N/D==n)
        return 0;
    return n + count_splits(n*N/D) + count_splits(n-n*N/D);
}

int main()
{
    int n;
    scanf("%d %d %d",&n,&N,&D);
    printf("%d\n",count_splits(n));
    return 0;
}