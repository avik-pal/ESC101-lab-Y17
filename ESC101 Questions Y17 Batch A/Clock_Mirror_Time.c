#include<stdio.h>

int main()
{
    int hr, min;
    scanf("%d\n%d",&hr,&min);
    
    int h,m;
    
    h = 11 - hr;
    m = 60 - min;
    
    printf("%d:%d\n",h,m);
    printf("%d",h*60+m);
    
    return 0;
}