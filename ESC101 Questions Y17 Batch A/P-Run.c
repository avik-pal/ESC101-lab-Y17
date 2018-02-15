#include<stdio.h>

int main()
{
    int n;
    
    scanf("%d",&n);
    int m = n;
    int rev = 0;
    
    if(m==0)
        rev = -1;
    
    while(m>0)
    {
        rev = rev*10 + m%10;
        m = m/10;
    }
    
    if(rev==n)
        printf("STOP");
    else
        printf("NON-STOP");
    
    return 0;
}