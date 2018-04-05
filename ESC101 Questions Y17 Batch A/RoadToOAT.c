#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    return a>b?a:b;
}

int get_max_points(int **P, int nrow, int ncol, int N) {
    // function to compute the maximum number of points obtainable
    // printf("%d\n",P[nrow][ncol]);
    if(nrow==N-1 && ncol==N-1)
    {
        // printf("%d\n",P[nrow][ncol]);
        return P[nrow][ncol];
    }
    else
    {
        // printf("%d\n",P[nrow][ncol]);
        if(nrow<N-1 && ncol<N-1)
            return P[nrow][ncol] + max(get_max_points(P,nrow,ncol+1,N),get_max_points(P,nrow+1,ncol,N));
        else if(ncol<N-1)
            return P[nrow][ncol] + get_max_points(P,nrow,ncol+1,N);
        else
            return P[nrow][ncol] + get_max_points(P,nrow+1,ncol,N);
    }
}

int main()
{
    //  Insert your code here.
    int N;
    scanf("%d",&N);
    int **M = (int **)malloc(sizeof(int *) * N);
    for(int i=0;i<N;i++)
    {
        *(M+i) = (int *)malloc(sizeof(int));
        for(int j=0;j<N;j++)
            scanf("%d",(*(M+i)+j));
    }
    printf("%d",get_max_points(M,0,0,N));
    return 0;
}