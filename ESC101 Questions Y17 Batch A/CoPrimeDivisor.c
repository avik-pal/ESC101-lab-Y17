#include<stdio.h>

int gcd(int a, int b)
{
    int max = a>b?a:b;
    int min = a+b-max;
    while(min!=max)
    {
        int temp = max - min;
        max = temp>min?temp:min;
        min = temp + min -max;
    }
    return min;
}

int main()
{
    int t, a, b;
    
    scanf("%d",&t);
    
    for(int i=1;i<=t;i++)
    {
        scanf("%d %d",&a,&b);
        for(int j=a;j>=1;j--)
        {
            if(a%j==0)
            {
                if(gcd(j,b)==1)
                {
                    printf("%d\n",j);
                    break;
                }
            }
        }
    }
    
    return 0;
}