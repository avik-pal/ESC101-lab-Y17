#include<stdio.h>
#include<stdlib.h>

void sum(long long int *A,long long int n){//MUST have return type void
    long long int s = 0;
    for(long long int i = 0;i<n;i++)
    {
        s += *(A+i);
    }
    printf("%lld",s);
}

int main()
{
    long long int *A, n;
    
    scanf("%lld",&n);
    //printf("%lld\n",n);
    A = (long long int *)malloc(n * sizeof(long long int));
    for(long long int i=0;i<n;i++)
        scanf("%lld",A+i);
    sum(A,n);
    return 0;
}