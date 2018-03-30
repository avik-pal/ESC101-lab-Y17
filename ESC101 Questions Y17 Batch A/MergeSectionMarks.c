#include <stdio.h>

void print_array(int arr[], int);
void array_merge(int arr1[], int arr2[], int bigarr[], int size1, int size2);
float array_mean(int arr[], int);

int main()
{
    int M, N;
    scanf("%d %d",&M,&N);
    int A[M], B[N];
    int i;
    for(i=0;i<M;i++)
        scanf("%d",&A[i]);
    for(i=0;i<N;i++)
        scanf("%d",&B[i]);
    int C[M+N];
    array_merge(A,B,C,M,N);
    print_array(C,M+N);
    printf("%.2f",array_mean(C,M+N));
    return 0;
}

float array_mean(int A[], int n)
{
    float mean = 0.0;
    for(int i=0;i<n;i++)
        mean += A[i];
    return mean/n;
}

void array_merge(int A[], int B[], int C[], int n, int m)
{
    for(int i=0;i<n;i++)
        C[i] = A[i];
    for(int i=0;i<m;i++)
        C[i+n] = B[i];
}

void print_array(int A[], int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}