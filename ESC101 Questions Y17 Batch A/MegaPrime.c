#include<stdio.h>

int isPrime(long long int n)
{
    long long int i;
    if(n==1)
        return 0;
    if(n==2 || n==3)
        return 1;
    if(n%2==0 || n%3==0)
        return 0;
    for(i=5;i*i<=n;i+=6)
    {
        if(n%i==0 || n%(i+2)==0)
            return 0;
    }
    return 1;
}

int megaPrime(long long int n)
{
    if(isPrime(n))
    {
        while(n>0)
        {
            if(isPrime(n%10)==0)
                return 0;
            n = n/10;
        }
        return 1;
    }
    return 0;
}

int main()
{
    long long int a,b;
    
    scanf("%d %d",&a,&b);
    
    for(long long int i = a;i<=b;i++)
    {
        if(megaPrime(i))
        {
            printf("%lld ",i);
        }
    }
    
    return 0;
}