#include<stdio.h>

int count = 0, n, x;

void counter(int a,int b,int c)
{
    //printf("%d %d %d\n",a,b,c);
    if((a+b+c)%x==0 && a!=0 && b!=0 && c!=0)
        count++;
    if(a==0)
    {
        for(int i=1;i<n-1;i++)
            counter(i,b,c);
    }
    else
    {
        if(b==0)
        {
            for(int i=a+1;i<n;i++)
                counter(a,i,b);
        }
        else if(c==0)
        {
            for(int i=b+1;i<=n;i++)
                counter(a,b,i);
        }
    }
}

int main()
{
    scanf("%d %d",&n,&x);
    counter(0,0,0);
    printf("%d",count);
    return 0;
}