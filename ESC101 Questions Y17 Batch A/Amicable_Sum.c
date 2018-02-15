#include<stdio.h>

int sumDivs(int n)
{
    int i;
    int sum = 0;
    for(i=1;i<=n/2;i++)
    {
        if(n%i==0)
        {
            sum += i;
        }
    }
    return sum;
}

int main()
{
    int t, n;
    
    scanf("%d",&t);
    
    for(int i = 1;i<=t;i++)
    {
        scanf("%d",&n);
        int a = sumDivs(n);
        int b = sumDivs(a);
        if(n==b)
            printf("Amicable\n");
        else
            printf("Not Amicable\n");
    }
    
    return 0;
}