#include<stdio.h>

int main()
{
    int n, flag=1;
    scanf("%d",&n);
    int A[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
        //printf("%d\n",A[i]);
        if(A[i]>n || A[i]<1)
        {
            flag = 0;
            break;
        }
    }
    if(flag==0)
    {
        printf("No");
        return 0;
    }
    else if(flag==1 && n==1)
    {
        printf("Yes");
        return 0;
    }
    int sorted = 1;
    for(int i=0;i<n-1;i++)
    {
        if(A[i]>A[i+1])
        {
            sorted = 0;
            break;
        }
    }
    if(sorted==1)
    {
        printf("No");
        return 0;
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(A[i]==A[j])
            {
                flag = 0;
                break;
            }
        }
        if(flag==0)
        {
            printf("No");
            return 0;
        }
    }
    printf("Yes");
    return 0;
}