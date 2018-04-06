#include<stdio.h>

int main()
{
    int n,m,i,j;
    scanf("%d",&n);
    int **A = (int **)malloc(n * sizeof(int *));
    for(i=0;i<n;i++)
    {
        *(A+i) = (int *)malloc(2 * sizeof(int));
        scanf("%dx^%d",*(A+i)+0,*(A+i)+1);
    }
    scanf("%d",&m);
    int **B = (int **)malloc(m * sizeof(int *));
    for(i=0;i<m;i++)
    {
        *(B+i) = (int *)malloc(2 * sizeof(int));
        scanf("%dx^%d",*(B+i)+0,*(B+i)+1);
    }
    int **C = (int **)malloc(n * m * sizeof(int *));
    int pos = 0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            *(C+pos) = (int *)malloc(2 * sizeof(int));
            C[pos][0] = A[i][0] * B[j][0];
            C[pos][1] = A[i][1] + B[j][1];
            pos++;
        }
    }
    free(A);
    free(B);
    for(i=0;i<n*m;i++)
    {
        if(C[i][1]==-111)
            continue;
        for(j=i+1;j<n*m;j++)
        {
            if(C[i][1]==C[j][1])
            {
                C[i][0] += C[j][0];
                C[j][1] = -111;
                C[j][0] = 0;
            }
        }
    }
    for(i=0;i<n*m;i++)
    {
        for(j=0;j<n*m-i-1;j++)
        {
            if(C[j][1]<C[j+1][1])
            {
                int temp1 = C[j][1];
                int temp2 = C[j][0];
                C[j][1] = C[j+1][1];
                C[j+1][1] = temp1;
                C[j][0] = C[j+1][0];
                C[j+1][0] = temp2;
            }
        }
    }
    for(i=0;i<n*m;i++)
    {
        if(C[i][0]!=0)
        {
            if(C[i][0]>=0 && i!=0)
                printf("+");
            printf("%dx^%d",C[i][0],C[i][1]);
        }
    }
    // printf("\n");
    // printf("\n");
    // for(i=0;i<n;i++)
    // {
    //     printf("%d %d\n",A[i][0],A[i][1]);
    // }
    // printf("\n");
    // for(i=0;i<m;i++)
    // {
    //     printf("%d %d\n",B[i][0],B[i][1]);
    // }
}