#include <stdio.h>
#include<stdlib.h>

//your functions for updating A and Ai here
void copyelems(int *A, int *B, int n)
{
    for(int i=0;i<n;i++)
        *(B+i) = *(A+i);
}

int main()
{
    int n,m;
    int *A, *Ai;
    int s, f, i;

    //Your code here
    scanf("%d %d",&n,&m);
    A = (int *)malloc(n*sizeof(int));
    Ai = (int *)malloc(n*sizeof(int));
    for(i = 0;i<n;i++)
        scanf("%d",A+i);
    copyelems(A,Ai,n);
    for(i = 0;i<m;i++)
    {
        scanf("%d",&s);
        if(s==-1)
            copyelems(A,Ai,n);
        else
        {
            scanf("%d",&f);
            *(A+s) = *(Ai + f);
            *(A+f) = *(Ai + s);
        }
    }
    free(Ai);
    //Print output
    for(i = 0; i < n-1; i++)
        printf("%d ", *(A + i));
    printf("%d", A[n-1]);
    free(A);
    return 0;
}