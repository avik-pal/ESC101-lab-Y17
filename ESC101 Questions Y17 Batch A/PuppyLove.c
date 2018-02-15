#include<stdio.h>

int bin_digits(int n)
{
    int count = 0;
    while(n>0)
    {
        count++;
        n = n/2;
    }
    return count;
}

int main()
{
    int n, k;
    scanf("%d %d",&n,&k);
    int count=0;
    
    for(int i=1;i<=n;i++)
    {
        int value, person;
        
        value = bin_digits(i);
        
        for(int j=1;j<=k;j++)
        {
            person = (value + j*i)%n + 1;
            
            if(person==i)
                continue;
            
            int value2 = bin_digits(person);
            
            for(int p=1;p<=k;p++)
            {
                if((value2 + p*person)%n + 1 == i)
                {
                    count++;
                    break;
                }
            }
            
        }
    }
    
    printf("%d",count/2);
    
    return 0;
}