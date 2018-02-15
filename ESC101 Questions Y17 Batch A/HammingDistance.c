#include<stdio.h>
#include<math.h>

long long int bin(int n)
{
    long long int binary = 0, count = 0;
    while(n>0)
    {
        binary += pow(10,count++)*(n%2);
        n = n/2;
    }
    return binary;
}

int hammingDist(long long int a, long long int b)
{
    int count = 0;
    if(a==0 && b==0)
        return 1;
    while(a>0 || b>0)
    {
        if(a%10 != b%10)
            count++;
        a /= 10;
        b /= 10;
    }
    return count;
}

int main()
{
    int t,a,b;
    
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d %d",&a,&b);
        long long int bina = bin(a);
        long long int binb = bin(b);
        //printf("%lld %lld\n",bina,binb);
        printf("%lld\n",hammingDist(bina,binb));
    }
    
    return 0;
}