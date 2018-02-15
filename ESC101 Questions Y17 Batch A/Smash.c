#include "stdio.h"
#include "math.h"
#include "stdlib.h"

int decide(int a, int b)
{
    if((a==11 && b<=9)||(b==11 && a<=9)||(a>11 && abs(a-b)==2)||(b>11 && abs(a-b)==2))
    {
        printf("Final Score\n");
        return 1;
    }
    if((a<11 && b<11)||(a>=11 && abs(a-b)==1)||(b>=11 && abs(a-b)==1))
    {
        printf("Ongoing\n");
        return 0;
    }
    printf("Invalid\n");
    return 2;
}

unsigned long long int permutes(int a, int b)
{
    unsigned long long int deno = 1, num = 1;
    for(int i=b+1;i<=a+b;i++)
        num *= i;
    for(int i=1;i<=a;i++)
        deno *= i;
    return num/deno;
}

int main()
{
    int a,b;
    char ch;
    unsigned long long int res = 0;
    scanf("%d%c%d",&a,&ch,&b);
    int choice = decide(a,b);
    if(choice == 2)
        return 0;
    else if(choice == 0)
    {
        if(a>11 || b>11)
            res = pow(2,(a-10+b-10-1)/2)*permutes(10,10);
        else
            res = permutes(a,b);
    }
    else
    {
        if(a>11 || b>11)
            res = pow(2,(a-10+b-10-1)/2)*permutes(10,10);
        else if(a>b)
            res = permutes(a-1,b);
        else
            res = permutes(a,b-1);
    }
    printf("%lld",res);
}