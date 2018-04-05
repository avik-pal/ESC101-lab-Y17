#include<stdio.h>
#include<stdlib.h>

int cal_num_days(int **arr , int n); // You have to use this function.
int main()
{
    //  Insert your code here.
    int n;
    scanf("%d",&n);
    int **arr = (int **)malloc(n*sizeof(int *));
    for(int i=0;i<n;i++)
    {
        *(arr+i) = (int *)malloc(n*sizeof(int));
        for(int j=0;j<n;j++)
            scanf("%d",*(arr+i)+j);
    }
    printf("%d",cal_num_days(arr,n));
    return 0;
}

int cal_num_days(int **arr, int n)
{
    int flag=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]==1)
            {
                flag=1;
                break;
            }
        }
    }
    if(flag==0)
        return 0;
    int zeros = 0;
    int **A = (int**)malloc(n*n*sizeof(int *));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]==0)
            {
                zeros++;
                *(A+zeros-1) = (int *)malloc(2 * sizeof(int));
                A[zeros-1][0] = i;
                A[zeros-1][1] = j;
            }
        }
    }
    // for(int i=0;i<zeros;i++)
    //     printf("%d = %d %d\n",i,A[i][0],A[i][1]);
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++)
    //         printf("%d ",arr[i][j]);
    //     printf("\n");
    // }
    // printf("\n");
    for(int i=0;i<zeros;i++)
    {
        int x = A[i][0];
        int y = A[i][1];
        // printf("%d %d\n",x,y);
        if(x>0 && x<n-1 && y>0 && y<n-1)
        {
            arr[x-1][y+1] = 0;
            arr[x-1][y] = 0;
            arr[x][y+1] = 0;
            arr[x+1][y-1] = 0;
            arr[x+1][y] = 0;
            arr[x][y-1] = 0;
            arr[x-1][y-1] = 0;
            arr[x+1][y+1] = 0;
        }
        else if(x==n-1)
        {
            if(y==0)
            {
                arr[x-1][y+1] = 0;
                arr[x-1][y] = 0;
                arr[x][y+1] = 0;
            }
            else if(y==n-1)
            {
                arr[x-1][y-1] = 0;
                arr[x-1][y] = 0;
                arr[x][y-1] = 0;
            }
            else
            {
                arr[x-1][y+1] = 0;
                arr[x][y+1] = 0;
                arr[x-1][y-1] = 0;
                arr[x-1][y] = 0;
                arr[x][y-1] = 0;
            }
        }
        else if(x==0)
        {
            if(y==0)
            {
                arr[x+1][y+1] = 0;
                arr[x+1][y] = 0;
                arr[x][y+1] = 0;
            }
            else if(y==n-1)
            {
                arr[x+1][y-1] = 0;
                arr[x+1][y] = 0;
                arr[x][y-1] = 0;
            }
            else
            {
                arr[x+1][y+1] = 0;
                arr[x][y+1] = 0;
                arr[x+1][y-1] = 0;
                arr[x+1][y] = 0;
                arr[x][y-1] = 0;
            }
        }
        else if(y==0)
        {
            arr[x-1][y] = 0;
            arr[x+1][y] = 0;
            arr[x+1][y+1] = 0;
            arr[x][y+1] = 0;
            arr[x-1][y+1] = 0;
        }
        else
        {
            arr[x-1][y] = 0;
            arr[x+1][y] = 0;
            arr[x+1][y-1] = 0;
            arr[x][y-1] = 0;
            arr[x-1][y-1] = 0;
        }
    }
    return 1 + cal_num_days(arr,n);
}