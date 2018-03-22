#include<stdio.h>
#include<stdlib.h>

int findAverage(int** A, int rows)
{
// Complete the code here. DO NOT modify the function header
    int avg = 0, count_vals=0;
    for(int i=0;i<rows;i++)
    {
        count_vals += *(*(A+i));
        for(int j=1;j<**(A+i)+1;j++)
        {
            avg += *(*(A+i)+j);
        }
    }
    return avg/count_vals;
}

int main()
{
// Allocate memory dynamically for each row of the matrix seperately.
// You will be penalized if you are using more than the optimal memory needed by input.
    int **A, n, m, m_prev;
    scanf("%d",&n); 
    A = (int **)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&m);
        *(A+i) = (int *)malloc((m+1)*sizeof(int));
        *(*(A+i)) = m;
        for(int j=1;j<m+1;j++)
            scanf("%d",(*(A+i)+j));
        //printf("INPUT\n");
    }
    printf("%d",findAverage(A, n));
    return 0;
};