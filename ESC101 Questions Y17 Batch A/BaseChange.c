#include<stdio.h>
#include<math.h>

int convToDeci(int base, int n)
{
    int deci = 0, count = 0;
    while(n>0)
    {
        deci += (n%10)*pow(base+1,count);
        //printf("%d %d %f\n",base,count,pow(base,count));
        count++;
        n /= 10;
    }
    return deci;
}

void deciToHexa(int deci)
{
    //printf("%d\n",deci);
    if(deci==0)
    {
        return;
    }
    deciToHexa(deci/16);
    //printf("%d\n",deci);
    int temp = deci%16;
    //printf("%d\n",temp);
    if(temp>=10)
        printf("%c",'A'+(temp-10));
    else
        printf("%d",temp);
}

int main()
{
    int base,n;
    int deci;
    scanf("%1d",&base);
    scanf("%d",&n);
    
    if(base!=9)
        deci = convToDeci(base,n);
    else
        deci = n;
    //printf("%d",deci);
    deciToHexa(deci);
    
    return 0;
}