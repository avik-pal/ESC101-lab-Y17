#include<stdio.h>
#include<stdlib.h>

int cost_min = 100000;

void sort(int A[], int n)
{
    for(int i=0;i<n;i++)
    {
        int min = A[i];
        int pos = i;
        for(int j=i+1;j<n;j++)
        {
            if(min>A[j])
            {
                min = A[j];
                pos = j;
            }
        }
        int temp = min;
        A[pos] = A[i];
        A[i] = temp;
    }
}

void copy_arr(int Z[], int W[], int N)
{
    int i;
    for(i=0;i<N;i++)
        Z[i] = W[i];
}

void get_cost(int W[], int N, int i, int cost)
{
    // printf("1. %d %d\n",cost,cost_min);
    // for(int j=0;j<N;j++)
    // {
    //     printf("%d ",W[j]);
    // }
    // printf("\n");
    if(cost>cost_min)
        return;
    int flag = 0;
    for(int j=0;j<N;j++)
    {
        if(W[j]!=0)
        {
            flag = 1;
            break;
        }
    }
    if(flag==0)
    {
        
        if(cost<cost_min)
            cost_min = cost;
        return;
    }
    // printf("2. %d\n",cost);
    for(int j=i;j<N;j++)
    {
        // printf("3. %d %d\n",cost,W[j]);
        
        if(W[j]!=0)
        {
            // printf("4. %d\n",cost);
            int *Z = (int *)malloc(N * sizeof(int));
            copy_arr(Z,W,N);
            int val = W[j];
            int k;
            for(k=0;k<N;k++)
            {
                if(Z[k]>=val && Z[k]<=val+4)
                {
                    Z[k] = 0;
                }
            }
            get_cost(Z,N,j+1,cost+1);
            free(Z);
        }
    }
}

int main()
{
    int N;
    scanf("%d",&N);
    int *a = (int *)malloc(N * sizeof(N));
    for(int i = 0;i<N;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,N);
    get_cost(a,N,0,0);
    free(a);
    printf("%d",cost_min);
    return 0;
}