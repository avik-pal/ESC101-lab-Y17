#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int A[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    int cost = 0, cost_max = 0;
    if(n==2)
    {
        if(A[1]>A[0])
            printf("%d",A[1]-A[0]);
        else
            printf("0");
        return 0;
    }
    for(int i=0;i<n-3;i++)
    {
        for(int j=i+1;j<n-2;j++)
        {
            for(int k=j+1;k<n-1;k++)
            {
                for(int l=k+1;l<n;l++)
                {
                    cost = A[l]+A[j]-A[i]-A[k];
                    //printf("%d\n",cost);
                    if(cost>cost_max)
                        cost_max = cost;
                }
            }
        }
    }
    printf("%d",cost_max);
    return 0;
}