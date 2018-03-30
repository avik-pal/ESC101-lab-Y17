#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    int **M = (int **)malloc(n*sizeof(int *));
    for(int i=0;i<n;i++)
    {
        *(M+i) = (int *)malloc(n*sizeof(int));
        for(int j=0;j<n;j++)
        {
            scanf("%d",&M[i][j]);
        }
    }
    int count = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(M[i][j]==1)
            {
                for(int k=0;k<n;k++)
                {
                    if(k==j)
                    {
                        continue;
                    }
                    if(M[j][k]==1)
                    {
                        if(M[k][i]==1)
                            count++;
                    }
                }
            }
        }
    }
    printf("%d",count/3);
    for(int i=0;i<n;i++)
        free(*(M+i));
    free(M);
    return 0;
}