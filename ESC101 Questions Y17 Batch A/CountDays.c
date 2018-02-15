#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int isLeap(int y)
{
    if(y%400==0)
        return 1;
    if(y%4==0 && y%100!=0)
        return 1;
    return 0;
}

int Days(int m, int y)
{
    //printf("%d\n",m);
    switch(m)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
                return 31;
        case 4:
        case 6:
        case 9:
        case 11:
                return 30;
        default:
                return 28+isLeap(y);
    }
}

int max(int a,int b)
{
    return a>b?a:b;
}

int main()
{
    int d1,d2,m1,m2,y1,y2;
    scanf("%d",&d1);
    scanf("%d",&m1);
    scanf("%d",&y1);
    scanf("%d",&d2);
    scanf("%d",&m2);
    scanf("%d",&y2);
    //printf("%d %d %d\n%d %d %d\n",d1,m1,y1,d2,m2,y2);
    int days = Days(m1,y1) - d1 + 1;
    int m = m1 + 1;
    if(m1==m2 && y1==y2)
    {
        days = d2-d1+1;
        printf("%d",days);
        return 0;
    }
    if(y1==y2)
    {
        while(m<m2)
        {
                days+=Days(m,y2);
                m++;
        }
        days += d2;
        printf("%d",days);
        return 0;
    }
    while(m<=12)
    {
        days+=Days(m,y1);
        m++;
    }
    m=1;
    days += max(0,365*(y2-y1-1));
    for(int i=y1+1;i<y2;i++)
    {
        days += isLeap(i);
    }
    while(m<m2)
    {
        days+=Days(m,y2);
        m++;
    }
    days += d2;
    printf("%d",days);
    return 0;
}