#include<stdio.h>
#include<stdlib.h>

int *get_elems(int a, int b)
{
    int u=1,v=0,x=0,y=1;
    while(a!=0)
    {
        int q = b/a;
        int r = b%a;
        int m = x - u*q;
        int n = y - v*q;
        b = a;
        a = r;
        x = u;
        y = v;
        u = m;
        v = n;
    }
    int *B = (int *)malloc(sizeof(int)*3);
    *(B) = b;
    *(B+1) = x;
    *(B+2) = y;
    return B;
}

int main()
{
    int i,t;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        int *B = get_elems(a,b);
        printf("%d %d %d\n",*(B),*(B+1),*(B+2));
        free(B);
    }
    return 0;
}