#include<stdio.h>
#include<stdlib.h>

int *copy(int A[], int n)
{
    int *B;
    B = (int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        B[i] = A[i];
    return B;
}

void all_possible(int n, int A[], int len, int order)
{
    if(n==0)
    {
        for(int i=0;i<len;i++)
        {
            printf("%d",A[i]);
        }
        printf("\n");
    }
    else
    {
        if(order==1)
        {
            all_possible(n-1,copy(A,len),len,1);
            A[len-n] = 1;
            all_possible(n-1,copy(A, len),len,2);
        }
        else
        {
            A[len-n] = 1;
            all_possible(n-1,copy(A, len),len,1);
            A[len-n] = 0;
            all_possible(n-1,copy(A,len),len,2);
        }
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int A[n];
    for(int i=0;i<n;i++)
        A[i] = 0;
    all_possible(n, copy(A, n), n, 1);
    return 0;
}