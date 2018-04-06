#include<stdio.h>

typedef struct Point{
    long double x;
    long double y;
}pt;

int main()
{
    //  Insert your code here.
    pt a[4];
    for(int i=0;i<4;i++)
    {
        scanf("%llf %llf",&a[i].x,&a[i].y);
    }
    if((a[1].y-a[0].y)*(a[3].x-a[2].x)!=(a[1].x-a[0].x)*(a[3].y-a[2].y))
        printf("Yes");
    else
        printf("No");
    return 0;
}