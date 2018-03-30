#include<stdio.h>
#include<stdlib.h>

int main()
{
    int mi = 0;
    int n,l;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&l);
        int *M = (int *)malloc(l*sizeof(int));
        int r = 1;
        for(int j=0;j<l;j++)
        {
            scanf("%d",&M[j]);
            mi += M[j]*r*r;
            r++;
        }
        free(M);
    }
    printf("%d",mi);
    return 0;
}