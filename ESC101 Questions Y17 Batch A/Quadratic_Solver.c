#include<stdio.h>
#include<math.h>

int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    
    int d = b*b - 4*a*c;
    double im1,im2,r1,r2;
    double deno = 2*a;
    
    if(d<0)
    {
        r1 = -b/deno;
        r2 = r1;
        im1 = -sqrt(-d)/deno;
        im2 = -im1;
        printf("%.2f%.2fi, %.2f+%.2fi",r1,im1,r2,im2);
    }
    else
    {
        im2 = 0;
        im1 = 0;
        r2 = (-b+sqrt(d))/deno;
        r1 = (-b-sqrt(d))/deno;
        printf("%.2f+%.2fi, %.2f+%.2fi",r1,im1,r2,im2);
    }
    
    return 0;
}