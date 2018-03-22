#include <stdio.h>
#include <stdlib.h>

void swap( int *p1, int *p2 ){
	// Insert your code here. DO NOT modify the arguments of the function.
	int num = *(p1 + *(p2));
	*(p1 + *(p2)) = *(p1 + *(p2+1));
	*(p1 + *(p2+1)) = num;
}

int main(){
	int t,m,n;
	scanf("%d",&t);
	int *A, *B;
	for(int i=0;i<t;i++)
	{
	    scanf("%d %d",&n,&m);
	    A = (int *)malloc(n*sizeof(int));
	    B = (int *)malloc(2*sizeof(int));
	    for(int j=0;j<n;j++)
	        scanf("%d",A+j);
	    for(int j=0;j<m;j++)
	    {
	        scanf("%d %d",B,B + 1);
	        swap(A,B);
	    }
	    for(int j=0;j<n;j++)
	        printf("%d ",*(A+j));
	    printf("\n");
	    free(B);
	    free(A);
	}
    return 0;
}