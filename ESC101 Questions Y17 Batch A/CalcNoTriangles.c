#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    int **M = (int **)malloc(n * sizeof(int*));
    for(int i=0;i<n;i++)
    {
        *(M+i) = (int *)malloc(n * sizeof(int));
        for(int j=0;j<n;j++)
        {
            scanf("%d",&M[i][j]);
        }
    }
    int count=0;
    for(int i=0; i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(M[i][j]!=1)
                continue;
            if(j+1<n && M[i][j+1]==1)
            {
                if(i+1<n && M[i+1][j+1]==1)
                {
                    count++;
                }
            }
            if(i+1<n && M[i+1][j]==1)
            {
                if(j-1>i+1 && M[i+1][j-1]==1)
                {
                    count++;
                }
            }
            if(i-1>=0 && M[i-1][j]==1)
            {
                if(j+1<n && M[i-1][j+1]==1)
                {
                    count++;
                }
            }
            if(j-1>i && M[i][j-1]==1)
            {
                if(i-1>=0 && M[i-1][j-1]==1)
                {
                    count++;
                }
            }
        }
    }
    printf("%d",count);
    for(int i=0;i<n;i++)
    {
        free(*(M+i));
    }
    return 0;
}