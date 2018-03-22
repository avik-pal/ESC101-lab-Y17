#include<stdio.h>

void rank(int *A, int n, int num)
{
    int i, rank = 0;
    for(i=0;i<n;i++)
    {
        if(*(A+i)<num)
            rank++;
    }
    printf("%d",rank);
}

int main()
{
    int n,num, *A;
    scanf("%d",&n);
    A = (int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        scanf("%d",A+i);
    scanf("%d",&num);
    rank(A,n,num);
    return 0;
}