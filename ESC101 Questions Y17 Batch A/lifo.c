#include<stdio.h>
#include <stdlib.h>

void deal_queries(int *top, int filled, int left, int queries) {
    // just use top here, 
    // don't pass the pointer to the first element of the array to this function
    // filled: how many elements of A are filled
    // left: how many elements are left to be filled in A
    // queries: number of queries left to be dealt with
    // top: pointer to the last element of the stack
    if(queries==0)
        return;
    int a,b;
    scanf("%d %d",&a,&b);
    if(a==1)
    {
        if(left==0)
            printf("Incorrect Operation\n");
        else
        {
            *(top+1) = b;
            top = top + 1;
            filled++;
            left--;
            printf("%d\n",*top);
        }
    }
    else
    {
        if(filled==1)
            printf("Incorrect Operation\n");
        else
        {
            top = top-1;
            filled--;
            left++;
            printf("%d\n",*top);
        }
    }
    deal_queries(top,filled,left,queries-1);
}

int main()
{
    //  Insert your code here.
    int N, Q;
    scanf("%d %d",&N,&Q);
    int n;
    scanf("%d",&n);
    int *A = (int *)malloc(N*sizeof(int));
    for(int i=0;i<n;i++)
    {
        scanf("%d",(A+i));
    }
    int top = n-1;
    deal_queries(A+top,n,N-n,Q);
    return 0;
}