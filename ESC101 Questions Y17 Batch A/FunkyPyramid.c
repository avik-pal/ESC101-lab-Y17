#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    
    for(int i=1;i<=n;i++)
    {
        int pluses = (i/2)+(i%2);
        int start_minus = n - (2*pluses - 1);
        for(int j=1; j<=start_minus; j++)
        {
            printf("-");
        }
        for(int j=1;j<=2*pluses-1;j++)
        {
            if(j%2==0)
                printf("-");
            else
                printf("+");
        }
        printf("\n");
    }
    
    return 0;
}