#include<stdio.h>

int main()
{
    int n,i;
    scanf("%d",&n);
    int A[n];
    for(i=0;i<n;i++)
        scanf("%d",&A[i]);
    int last = n-1;
    int first = 0;
    int flag = 0;
    int mid = (last+first)/2;
    int count = 0;
    while(last>=first)
    {
        printf("%d\n",count++);
        if(A[mid]==mid)
        {
            flag = 1;
            break;
        }
        else if(A[mid]>mid)
            last = mid - 1;
        else
            first = mid + 1;
        mid = (last+first)/2;
    }
    if(flag == 1)
        printf("Found at %d\n",mid);
    else
        printf("Not found");
    return 0;
}