#include<stdio.h>
#include <stdlib.h>

int get_max_col_sum(int **A, int N)
{
    // function to get maximum column sum
    int max=-1, max_col=-1;
    for(int i=0;i<N;i++)
    {
        int sum = 0;
        for(int j=0;j<N;j++)
        {
            sum += A[j][i];
        }
        if(sum>max)
        {
            max = sum;
            max_col = i;
        }
    }
    return max;
}

int main()
{
    //  Insert your code here.
    int n;
    scanf("%d",&n);
    int **A = (int **)malloc(n*sizeof(int *));
    for(int i=0;i<n;i++)
    {
        *(A+i)  =(int *)malloc(n*sizeof(int));
        for(int j=0;j<n;j++)
        {
            scanf("%d",*(A+i)+j);
        }
    }
    printf("%d",get_max_col_sum(A,n));
    return 0;
}