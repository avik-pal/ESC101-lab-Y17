#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int A[n];
    int i;
    for(i=0;i<n;i++)
        scanf("%d",&A[i]);
    int sumevenl = 0, sumevenr = 0;
    int sumoddl = 0, sumoddr = 0;
    for(i=0;i<n;i++)
    {
        if(A[i]%2==0)
            sumevenr++;
        else
            sumoddr++;
    }
    for(i=0;i<n;i++)
    {
        //printf("%d %d %d %d %d\n",i,sumevenr,sumevenl,sumoddl,sumoddr);
        if(sumevenr==sumevenl || sumoddl==sumoddr)
        {
            printf("%d",i);
            return 0;
        }
        else
        {
            if(A[i]%2==0)
            {
                sumevenl++;
                sumevenr--;
            }
            else
            {
                sumoddl++;
                sumoddr--;
            }
        }
    }
    printf("-1");
    return 0;
}