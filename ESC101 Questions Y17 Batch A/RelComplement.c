#include<stdio.h>

int main()
{
    int n, m;
    scanf("%d\n%d",&n,&m);
    int A[n], B[m];
    for(int i=0;i<n;i++)
        scanf("%d",&A[i]);
    for(int i=0;i<m;i++)
        scanf("%d",&B[i]);
    for(int i=0;i<n;i++)
    {
        int flag = 0;
        for(int j=0;j<m;j++)
        {
            if(A[i]==B[j])
            {
                flag = 1;
                break;
            }
        }
        flag==1 || printf("%d ",A[i]);
    }
    return 0;
}