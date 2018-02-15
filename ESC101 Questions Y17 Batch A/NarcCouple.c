#include<stdio.h>
#include<math.h>

int countD(int n)
{
    int d=0;
    while(n>0)
    {
        d++;
        n /= 10;
    }
    return d;
}

int checkNarc(int n, int countd)
{
    int m = n;
    int sum = 0;
    while(n>0)
    {
        sum += (int)pow(n%10,countd);
        //printf("%d %d %d\n",m,sum,countd);
        n /= 10;
    }
    if(sum==m)
        return 1;
    else
        return 0;
}

void CHECKBREAK(int n,int d)
{
    int a,b,d_p = d;
    d=d;
    int prev_besta = 0;
    int prev_bestb = n;
    while(d>1)
    {
        a = n/(pow(10,d-1));
        b = n%(int)(pow(10,d-1));
        //printf("%d %d\n",a,b);
        int dig_b = d-1;
        int dig_a = d_p - dig_b;
        if(checkNarc(a,dig_a) && checkNarc(b,dig_b))
        {
            if(prev_bestb>b)
            {
                prev_bestb = b;
                prev_besta = a;
            }
        }
        d--;
    }
    if(prev_besta!=0)
    {
        printf("Yes\n");
        printf("%d %d",prev_besta,prev_bestb);
    }
    else
        printf("No");
}

int main()
{
    int n;
    scanf("%d",&n);
    int countd = countD(n);
    CHECKBREAK(n,countd);
    return 0;
}