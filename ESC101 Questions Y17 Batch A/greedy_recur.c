#include<stdio.h>

int greedy(int n)
{
    
    if(n==1 || n==2 || n==3)
        return 0;
    else
    {
        return n/2 - 1 + greedy(n-2);
    }
    // if(a+2<=n-2 && b+2<=n-2)
    //     count++;
    // else
    //     return;
    // if(a==0 && b==0)
    // {
    //     greedy(n,a+2,b,1);
    //     greedy(n,a,b+2,0);
    // }
    // else if(inc_A==1)
    // {
    //     greedy(n,a+2,b,1);
    //     greedy(n-2,a,b+2,0);
    // }
    // else
    // {
    //     greedy(n,a,b+2,0);
    //     greedy(n-2,a+2,b,1);
    // }
}

int main()
{
    int n;
    scanf("%d",&n);
    int count = greedy(n);
    printf("%d",count);
    return 0;
}