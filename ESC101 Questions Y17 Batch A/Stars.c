#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    scanf("%d",&n);
    
    int i;
    int d = n*n;
    
    for(i=1;i<=n;i++)
    {
        for(int j=1;j<=d-i*i;j++)
            printf("-");
        for(int j=1;j<=i*i;j++)
            printf("*");
        printf("\n");
    }
    
    return 0;
}