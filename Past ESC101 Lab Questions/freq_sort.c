#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int A[n];
    for(int i=0;i<n;i++)
        scanf("%d",&A[i]);
    int B[2][n];
    for(int i=0;i<n;i++)
    {
        B[0][i] = -1;
        B[1][i] = 0;
    }
    int dist = 0;
    for(int i=0;i<n;i++)
    {
        int elem = A[i];
        int prev_occur = 0;
        for(int j=0;j<dist;j++)
        {
            if(elem==B[0][j])
            {
                prev_occur = 1;
                B[1][j]++;
                break;
            }
        }
        if(!prev_occur)
        {
            B[0][dist] = elem;
            B[1][dist] = 1;
            dist++;
        }
    }
    for(int i=0;i<dist;i++)
    {
        printf("%d %d\n",B[0][i],B[1][i]);
    }
    for(int i=0;i<dist;i++)
    {
        for(int j=0;j<dist-i-1;j++)
        {
            if(B[1][j+1]<B[1][j])
            {
                int temp = B[1][j];
                B[1][j] = B[1][j+1];
                B[1][j+1] = temp;
                temp = B[0][j];
                B[0][j] = B[0][j+1];
                B[0][j+1] = temp;
            }
        }
    }
    for(int i=0;i<dist;i++)
    {
        printf("%d ",B[0][i]);
    }
    return 0;
}