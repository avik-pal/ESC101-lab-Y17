#include<stdio.h>

long long int catalan(long long int n)
{
    if(n==0)
        return 1;
    else
    {
        long long int k=0;
        for(int i=0;i<=n-1;i++)
        {
            //printf("%lld\n",k);
            k += catalan(i) * catalan(n-i-1);
        }
        return k;
    }
}

int main()
{
    int tests, num;
    scanf("%d",&tests);
    for(int i=0;i<tests;i++)
    {
        scanf("%d",&num);
        if(num<=2)
        {
            printf("-1\n");
            continue;
        }
        printf("%d\n",catalan(num-2));
    }
    return 0;
}