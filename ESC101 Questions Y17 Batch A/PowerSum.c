#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int count=0,n;

void counter(int num,int left)
{
    left = (int)(left-pow(num,n));
    //printf("%d %d\n",num,left);
    if(left==0)
    {
        count++;
        return;
    }
    if((int)(left - pow(num,n))<0)
        return;
    else
    {
        for(int i=1;i<=left;i++)
        {
            if((int)pow(i,n)>left)
                break;
            counter(num+i,left);
        }
    }
}

int main()
{
    int x,t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d %d",&x,&n);
        counter(0,x);
        printf("%d\n",count);
        count = 0;
    }
    return 0;
}