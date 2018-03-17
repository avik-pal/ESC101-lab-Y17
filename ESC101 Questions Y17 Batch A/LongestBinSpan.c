#include<stdio.h>

int max_len = 0;

int sum(int A[], int n)
{
    int s = 0;
    for(int i=0;i<n;i++)
        s += A[i];
    return s;
}

void find_lengths(int A[], int B[], int sum1, int sum2, int start, int end)
{
    //printf("%d %d\n",sum1,sum2);
    if(max_len>end-start)
        return;
    else if(sum1==sum2)
    {
        if(max_len<end-start)
        {
            //printf("Yo %d %d\n",start,end);
            max_len = end - start;
        }
        return;
    }
    else if(start==end)
        return;
    else
    {
        find_lengths(A,B,sum1-A[start],sum2-B[start],start+1,end);
        find_lengths(A,B,sum1-A[end-1],sum2-B[end-1],start,end-1);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int A[n], B[n];
    for(int i=0;i<n;i++)
        scanf("%d",&A[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&B[i]);
    find_lengths(A,B,sum(A,n),sum(B,n),0,n);
    printf("%d",max_len);
    return 0;
}