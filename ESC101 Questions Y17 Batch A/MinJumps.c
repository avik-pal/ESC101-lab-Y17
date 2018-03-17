#include<stdio.h>
#include<limits.h>

int min_steps = 1000;

void recur(int A[], int n, int steps, int pos)
{
    if(pos==n-1)
    {
        if(min_steps>steps)
            min_steps = steps;
    }
    else
    {
        for(int i=1;i<=A[pos];i++)
        {
            if(pos+i>=n)
                break;
            recur(A, n, steps+1, pos+i);
        }
    }
}

int main()
{
    int n=20, A[n];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&(A[i]));
    recur(A,n,0,0);
    printf("%d",min_steps);
    return 0;
}