#include<stdio.h>

int Palin(long long int n)
{
    long long int m = 0, n2 = n;
    while(n>0)
    {
        m = m*10 + n%10;
        //printf("%d\n",n%10);
        n = n/10;
    }
    //printf("%lld %lld\n",m,n2);
    if(m==n2)
        return 1;
    return 0;
}

int main()
{
    int t;
    long long int n;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%lld",&n);
        if(Palin(n))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}