#include<stdio.h>
#include<stdlib.h>

//Write a function Range() which calculates the required range
//This function MUST have int * A as an argument

//Your function here
void Range(long long int *A, int n)
{
    long long int min=*A, max=*A;
    for(int i=1;i<n;i++)
    {
        if(*(A+i)>max)
            max = *(A+i);
        if(*(A+i)<min)
            min = *(A+i);
    }
    printf("%d",max-min);
}


int main()
{
    int n;//DO NOT MODIFY
    long long int* A;
    //Your code here
    scanf("%d",&n);
    A = (long long int *)malloc(n*sizeof(long long int));
    for(int i=0;i<n;i++)
    {
        scanf("%lld",A+i);
    }
    Range(A,n);
    free(A);
    return 0;
}