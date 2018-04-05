#include<stdio.h>
#include<stdlib.h>

int main()
{
    int M, n, Q;
    scanf("%d %d %d",&M,&n,&Q);
    // declaring H
    long long int ***H = (long long int***) malloc(n*sizeof(long long int**));
    // Each cell H[i][j] would be a pointer to an element in A
    long long int A[M];
    for(int i=0;i<n;i++)
    {
        *(H+i) = (long long int**)malloc(3*sizeof(long long int*));
        H[i][0] = NULL;
        H[i][1] = NULL;
        H[i][2] = NULL;
    }
    for(int i=0;i<M;i++)
    {
        scanf("%lld",&(A[i]));
        int p = A[i]%n;
        int j;
        for(j=0;j<3;j++)
            if(H[p][j]==NULL)
                break;
        if(j!=3)
            H[p][j] = &A[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(H[i][j]!=NULL)
                printf("%lld ",*(H[i][j]));
        }
        printf("\n");
    }
    for(int i=0;i<Q;i++)
    {
        long long int q;
        scanf("%lld",&q);
        int p = q%n;
        // printf("%d ",p);
        if((H[p][0]!=NULL && q==*(H[p][0])) || (H[p][1]!=NULL && q==*(H[p][1])) || (H[p][2]!=NULL && q==*(H[p][2])))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}