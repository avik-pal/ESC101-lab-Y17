#include<stdio.h>

int min_remove = 1000;

void find_min(int A[], int n, int k, int start, int end)
{
    if(n - end + start > min_remove)
        return;
    if(start==end)
        return;
    if(A[end-1]-A[start]<=k)
    {
        min_remove = n - end + start;
        return;
    }
    find_min(A, n, k, start+1, end);
    find_min(A, n, k, start, end-1);
}

int main()
{
    int n,k;
    scanf("%d",&n);
    int A[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    scanf("%d",&k);
    find_min(A, n, k, 0, n);
    printf("%d",min_remove);
    return 0;
}