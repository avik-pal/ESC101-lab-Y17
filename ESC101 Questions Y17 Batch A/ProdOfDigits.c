#include<stdio.h>

void do_job(int n,int prod)
{
    if(n/10==0)
        printf("%d %d",n,prod);
    else
    {
        int product = 1;
        while(n>0)
        {
            product *= n%10;
            n=n/10;
        }
        do_job(product,prod+1);
    }
}

int main()
{
    int num;
    scanf("%d",&num);
    do_job(num,0);
    return 0;
}