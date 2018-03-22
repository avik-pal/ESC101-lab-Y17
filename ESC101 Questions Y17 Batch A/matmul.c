#include<stdio.h>
#include <stdlib.h>
 
// YOUR CODE MUST USE THESE FUNCTIONS

void mul_mat(int m, int n, int *A, int *B, int *C)
{
   //DO NOT CHANGE THIS FUNCTION TEMPLATE
   int j = 0, k = 0, pro = 0;
   for(int i=0;i<m*n;i++)
   {
        pro += *(A+i) * *(B+j);
        j++;
        if((i+1)%n==0)
        {
            *(C+k) = pro;
            pro = 0;
            k++;
            j = 0;
        }
   }
}

void read_mat(int m, int n, int *A)
{
   //DO NOT CHANGE THIS FUNCTION TEMPLATE
   for(int i=0;i<m*n;i++)
        scanf("%d",A+i);
}

void print_mat(int m, int n, int *A)
{
   //DO NOT CHANGE THIS FUNCTION TEMPLATE
   for(int i=0;i<m*n;i++)
   {
       printf("%d ",*(A+i));
       if((i+1)%m==0)
            printf("\n");
   }
}

int main()
{
    int m, n;
    int *A, *B, *C;
    scanf("%d %d",&m,&n);
    A = (int *)malloc(m*n*sizeof(int));
    B = (int *)malloc(n*sizeof(int));
    C = (int *)malloc(m*sizeof(int));
    read_mat(m,n,A);
    read_mat(n,1,B);
    mul_mat(m,n,A,B,C);
    print_mat(m,1,C);
    return 0;
}