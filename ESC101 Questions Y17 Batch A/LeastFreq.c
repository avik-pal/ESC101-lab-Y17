#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int A[n];
    int B[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
        B[i] = n+1;
        //printf("%d\n",A[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(A[i]!=-1)
        {
            //printf("YES\n");
            int a = A[i];
            int count = 1;
            for(int j=i+1;j<n;j++)
            {
                if(A[j]==a)
                {
                    A[j] = -1;
                    count++;
                }
            }
            B[i] = count;
        }
    }
    //for(int i=0;i<n;i++)
        //printf("%d ",B[i]);
    //printf("\n");
    int min_pos = 0;
    for(int i=1;i<n;i++)
    {
        if(B[min_pos]>B[i])
            min_pos = i;
    }
    printf("%d",A[min_pos]);
    return 0;
}