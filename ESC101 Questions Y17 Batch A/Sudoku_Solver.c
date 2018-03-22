#include<stdio.h>
#include<stdlib.h>

int flag = 0;

int* copy_mat(int N, int A[])
{
    int* B;
    B = (int *)malloc(N*N*sizeof(int));
    for(int i=0;i<N*N;i++)
        B[i] = A[i];
    return B;
}

void printmat(int A[], int N)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(j==N-1)
            {
                printf("%d\n",A[i*N+j]);
                continue;
            }
            printf("%d ",A[i*N+j]);
        }
    }
    flag = 1;
}

void solver(int A[], int N, int R, int C, int curr_i, int curr_j)
{
    // printmat(A,N);
    // printf("\n");
    for(int j=0;j<N;j++)
    {
        if(j==curr_j || A[curr_i*N+j]==0)
            continue;
        if(A[curr_i*N+curr_j]==A[curr_i*N+j])
        {
            // printf("1\n");
            return;
        }
    }
    for(int i=0;i<N;i++)
    {
        if(i==curr_i || A[i*N+curr_j]==0)
            continue;
        if(A[curr_i*N+curr_j]==A[i*N+curr_j])
        {
            // printf("2\n");
            return;
        }
    }
    int r=-1,c=-1;
    for(int i=0;i<N;i+=R)
    {
        if(i>curr_i)
        {
            r = i-R;
            break;
        }
        if(i+R==N)
        {
            r = i;
            break;
        }
    }
    // printf("%d %d\n",r,c);
    for(int i=0;i<N;i+=C)
    {
        if(i>curr_j)
        {
            c = i-C;
            break;
        }
        if(i+C==N)
        {
            c = i;
            break;
        }
    }
    // printf("yes = %d %d %d %d\n",r,c,curr_i,curr_j);
    for(int i=r;i<r+R;i++)
    {
        for(int j=c;j<c+C;j++)
        {
            if((i==curr_i && j==curr_j) || A[i*N+j]==0)
                continue;
            if(A[i*N+j]==A[curr_i*N+curr_j])
            {
                // printf("%d %d 3\n",r,c);
                return;
            }
        }
    }
    for(int i=curr_i;i<N;i++)
    {
        int j;
        if(i==curr_i)
            j = curr_j;
        else
            j = 0;
        for(; j<N; j++)
        {
            if(A[i*N+j]==0)
            {
                for(int k=1;k<=N;k++)
                {
                    A[i*N+j] = k;
                    solver(copy_mat(N, A),N,R,C,i,j);
                    if(flag==1)
                        return;
                }
                return;
            }
        }
    }
    printmat(A,N);
}

int main()
{
    int N, R, C;
    scanf("%d %d %d", &N, &R, &C);
    int A[N*N];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            scanf("%d",&A[i*N+j]);
        }
    }
    //printmat(A,N);
    solver(copy_mat(N, A), N, R, C, 0, 0);
    if(flag==0)
        printf("Invalid\n");
    return 0;
}