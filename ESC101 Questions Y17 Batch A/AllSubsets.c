#include<stdio.h>

void print_subsets(int A[], int n, int B[], int pos, int filled)
{
    int i = 0;
    if(B[0]==-1)
        printf("{}\n");
    else
    {
        printf("{");
        for(i=0;i<=filled;i++)
        {
            printf("%d ",B[i]);
        }
        printf("}\n");
    }
    if(pos==n || filled==n)
        return;
    else
    {
        for(i=pos+1;i<n;i++)
        {
            B[filled+1] = A[i];
            print_subsets(A,n,B,i,filled+1);
        }
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int A[n], B[n];
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
        B[i] = -1;
    }
    print_subsets(A, n, B, -1, -1);
    return 0;
}