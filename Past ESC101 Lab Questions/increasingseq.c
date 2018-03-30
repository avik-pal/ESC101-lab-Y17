#include<stdio.h>
#include<stdlib.h>

void copy_arr1(int *dest, int *source, int N)
{
    for(int i=0;i<N;i++)
        *(dest+i) = *(source+i);
}

void print_seqs2(int N, int n, int M, int num, int i, int max, int *B, int *A)
{
    // printf("%d %d\n",N,num);
    int j;
    // for(j=1;j<num;j++)
    // {
    //     if(B[j-1]>B[j])
    //     {
    //         // for(j=0;j<n;j++)
    //         // {
    //         //     printf("%d ",A[j]);
    //         // }
    //         // printf(" 009\n\n");
    //         return;
    //     }
    // }
    if(num>2 && B[num-2]>B[num-1])
    {
        return;
    }
    if(N==0)
    {
        for(j=0;j<M-1;j++)
        {
            if(B[j]>B[j+1])
                return;
        }
        for(j=0;j<n-1;j++)
        {
            printf("%d ",A[j]);
        }
        printf("%d\n",A[n-1]);
        return;
    }
    for(j=num;j<=M;j++)
    {
        int A2[n];
        int B2[M];
        copy_arr1(A2,A,n);
        copy_arr1(B2,B,M);
        A2[i] = j;
        B2[j-1]++;
        print_seqs2(N-1,n,M,j,i+1,max,B2,A2);
    }
}

int main() 
{
    int N,M;
    scanf("%d %d",&N,&M);
    int A[N];
    int B[M];
    for(int i=0;i<M;i++)
        B[i] = 0;
    int max = N/M;
    print_seqs2(N,N,M,1,0,max,B,A);
    return 0;
}