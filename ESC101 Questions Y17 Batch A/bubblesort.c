#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    int *A = (int *)malloc(n*sizeof(int));
    int **B = (int **)malloc(n*sizeof(int *));
    for(int i=0;i<n;i++)
    {
        scanf("%d",(A+i));
        *(B+i) = (int *)malloc(sizeof(int));
        B[i] = A+i;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(B[j][0]>B[j+1][0])
            {
                int* temp = *(B+j);
                *(B+j) = *(B+j+1);
                *(B+j+1) = temp;
            }
        }
        for(int i=0;i<n;i++)
        {
            printf("%d ",B[i][0]);
        }
        printf("\n");
    }
    return 0;
}