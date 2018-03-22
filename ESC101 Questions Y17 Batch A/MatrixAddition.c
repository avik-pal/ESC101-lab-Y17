#include<stdio.h>

int main()
{
    int n,m,i;
    scanf("%d %d",&n,&m);
    int *A, *B;
    A = (int *)malloc(n*m*sizeof(int));
    B = (int *)malloc(n*m*sizeof(int));
    for(i=0;i<m*n;i++)
        scanf("%d",A+i);
    for(i=0;i<m*n;i++)
        scanf("%d",B+i);
    for(int i=0;i<m*n;i++)
        *(A+i) = *(A+i) + *(B+i);
    for(int i=0;i<m*n;i++)
    {
        printf("%d ",*(A+i));
        if((i+1)%m==0)
            printf("\n");
    }
    return 0;
}