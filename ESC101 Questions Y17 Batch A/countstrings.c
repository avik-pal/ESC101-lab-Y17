#include<stdio.h>

int count(int n,int bs,int cs)
{
    if(n==1)
    {
        if(bs==0 && cs==0)
            return 1;
        else if(bs!=0 && cs==0)
            return 2;
        else if(cs!=0 && bs==0)
            return 2;
        else
            return 3;
    }
    else
    {
        int a = count(n-1,bs,cs);
        int b = 0, c = 0;
        if(bs>0)
            b = count(n-1,bs-1,cs);
        if(cs>0)
            c = count(n-1,bs,cs-1);
        return a+b+c;
    }
}

int main()
{
    //  Insert your code here.
    int n;
    scanf("%d",&n);
    int bs = 1, cs = 2;
    printf("%d",count(n,bs,cs));
    return 0;
}