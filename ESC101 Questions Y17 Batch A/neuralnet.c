#include<stdio.h>
#include<stdlib.h>
int * cal_output(float ** Weight , float * input , int row , int col); // You have to use this function
int main()
{
    //  Insert your code here.
    // Use main for scaning and printing only.
    // Cannot change signature of funciton
    int n,m;
    scanf("%d",&n);
    float *N = (float *)malloc(n*sizeof(float));
    for(int i=0;i<n;i++)
        scanf("%f",N+i);
    scanf("%d",&m);
    float **M = (float **)malloc(n*sizeof(float*));
    for(int i=0;i<n;i++)
    {
        *(M+i) = (float *)malloc(m*sizeof(float)); 
        for(int j=0;j<m;j++)
        {
            scanf("%f",*(M+i)+j);
        }
    }
    int *O = (int *)malloc(m*sizeof(int));
    O = cal_output(M,N,n,m);
    for(int i=0;i<m;i++)
        printf("%d ",O[i]);
    return 0;
}

int * cal_output(float **Weight, float * input, int row, int col)
{
    int i,j;
    int *O = (int *)malloc(col * sizeof(int));
    for(i=0;i<col;i++)
    {
        float a = 0.0;
        for(j=0;j<row;j++)
        {
            a += input[j]*Weight[j][i];
        }
        if(a<0.3)
            O[i] = 0;
        else
            O[i] = 1;
    }
    return O;
}