#include<stdio.h>
#include<stdlib.h>
int * rotate_array(int * arr , int size , int index)
{
    int *A = (int *)malloc(size*sizeof(int));
    int j=0;
    for(int i=index;i<size;i++)
    {
        A[j++] = arr[i];
    }
    for(int i=0;i<index;i++)
    {
        A[j++] = arr[i];
    }
    return A;
}
int main()
{
    int n;
    scanf("%d",&n);
    int * arr = (int * )malloc(n*sizeof(int));
    for(int i = 0 ;i < n ; ++i){
        scanf("%d",arr+i);
    }
    int m;
    scanf("%d",&m);
    arr = rotate_array(arr,n,m);
    for(int i = 0 ;i < n; ++i){
        printf("%d ",arr[i]);
    }
    return 0;
}