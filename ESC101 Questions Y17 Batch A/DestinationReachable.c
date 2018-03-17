#include<stdio.h>

int flag = 0;

void check_dest(int a, int b, int c, int d)
{
    if(a==c && b==d)
    {
        flag = 1;
        return;
    }
    if(a>c || b>d)
    {
        return;
    }
    if(flag==0)
    {
        check_dest(a+b,b,c,d);
        check_dest(a,a+b,c,d);
    }
}

int main()
{
    int t;
    int a,b,c,d;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d %d %d %d",&a,&b,&c,&d);
        check_dest(a,b,c,d);
        if(flag==1)
            printf("Yes\n");
        else
            printf("No\n");
        flag = 0;
    }
    return 0;
}