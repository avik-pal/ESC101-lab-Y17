#include<stdio.h>
#include<math.h>

int checkRepeat(long long int n)
{
    int A[10];
    for(int i=0;i<10;i++)
        A[i] = 0;
    while(n>0)
    {
        int d = n%10;
        n = n/10;
        if(A[d]==1)
            return 1;
        else
        {
            A[d] = 1;
        }
    }
    return 0;
}

long long int Converter(int n, int deg)
{
    if(n==0)
        return 0;
    return Converter(n/deg,deg) * 10 + n%deg;
}

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int i;
    if(k==0)
        return 0;
    for(i=0;i<(int)pow(n,k);i++)
    {
        long long int conv = Converter(i,n);
        if(checkRepeat(conv)==0)
        {
            printf("%lld\n",conv);
        }
    }
    return 0;
}