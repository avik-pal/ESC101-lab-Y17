#include<stdio.h>

int main()
{
    int cr;
    long money;
    scanf("%d",&cr);
    scanf("%ld",&money);
    double converted = (double)cr *(double)money;
    printf("%.1lf\n",converted);
}