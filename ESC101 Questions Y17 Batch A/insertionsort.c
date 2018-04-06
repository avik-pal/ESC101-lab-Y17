#include<stdio.h>
#include <stdlib.h>

int main()
{
    // Insert your code here.
    // each B[i][j] is either NULL or points to some element in A. 
    int M,n,p;
    scanf("%d %d %d",&M,&n,&p);
    int i;
    int *A = (int *)malloc(M*sizeof(int));
    int ***B = (int ***)malloc(n * sizeof(int **));
    for(i=0;i<n;i++)
    {
        *(B+i) = (int **)malloc(p * sizeof(int *));
        for(int j=0;j<p;j++)
        {
            *(*(B+i)+p) = (int *)malloc(sizeof(int));
            *(*(B+i)+p) = NULL;
        }
    }
    for(i=0;i<M;i++)
    {
        scanf("%d",A+i);
        int q = A[i]/p;
        int j,k;
        for(j=0;j<p;j++)
        {
            if(B[q][j]==NULL)
                break;
        }
        B[q][j] = &A[i];
        for(k=j;k>=1;k--)
        {
            if(*B[q][k]>*B[q][k-1])
            {
                break;
            }
            int *temp = B[q][k];
            B[q][k] = B[q][k-1];
            B[q][k-1] = temp;
        }
    }
    for(i=0;i<n;i++)
    {
        for(int j=0;j<p;j++)
        {
            if(B[i][j]==NULL)
                break;
            printf("%d ",*B[i][j]);
        }
        printf("\n");
    }
    return 0;
}