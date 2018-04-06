#include<stdio.h>

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int a[k];
    int M[k][n];
    int i,j;
    for(i=0;i<k;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<k;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&M[i][j]);
        }
    }
    int B[n][n];
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            B[i][j] = 0;
    for(i=0;i<k;i++)
    {
        for(j=0;j<n;j++)
        {
            for(int p=0;p<n;p++)
            {
                B[j][p] += a[i]*M[i][j]*M[i][p];
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            printf("%d ",B[i][j]);
        }
        printf("%d\n",B[i][n-1]);
    }
    return 0;
}