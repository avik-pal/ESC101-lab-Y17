//Write a program to print the first n euclid numbers

#include<stdio.h>

int isPrime(int n)
{
    for(int i=2;i<=n/2;i++)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}

void first_n_euclid(int n)
{
    int pn = 2, i=2;
    while(n>0)
    {
        printf("%d\n",pn+1);
        for(int j=i+1; ;j++)
        {
            if(isPrime(j))
            {
                pn = pn*j;
                i=j;
                break;
            }
        }
        n--;
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    first_n_euclid(n);
}