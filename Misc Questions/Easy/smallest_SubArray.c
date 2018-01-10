/*Given an array, A.Let x be an element in the array which has the maximum frequency in the array.Find the smallest subsegment of the array which also has x as the maximum frequency element.*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int t;
    printf("Enter number of test cases:");
    scanf("%d",&t);
    int i;
    for(i=1;i<=t;i++)
    {
        int n;
        printf("Enter the size of array:");
        scanf("%d",&n);
        int A[n];
        int j;
        int count[] = {0,0,0,0,0,0,0,0,0,0};
        int maxpos = -1;
        for(j=0;j<n;j++)
        {
            printf("Enter element %d:",j);
            scanf("%d",&A[j]);
            count[A[j]]++;
            if(maxpos==-1)
                maxpos = A[j];
            else if(count[A[j]]>count[maxpos])
                maxpos = A[j];
        }
        int startpos = 0, endpos = n-1;
        for(j=0;j<n;j++)
        {
            if(A[j]==maxpos)
            {
                startpos = j;
                break;
            }
        }
        for(j=n-1;j>=0;j--)
        {
            if(A[j]==maxpos)
            {
                endpos = j;
                break;
            }
        }
        for(j=startpos;j<=endpos;j++)
            printf("%d ",A[j]);
    }
    return 0;
}
