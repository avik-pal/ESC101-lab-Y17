#include<stdio.h>

int main()
{
    int k;
    scanf("%d\n",&k);
    char str[k];
    for(int i=0;i<k;i++)
        scanf("%c",&str[i]);
    int flag=1;
    for(int i=0;i<k;i++)
    {
        if(str[i]!='9')
        {
            flag = 0;
            break;
        }
    }
    if(flag==1)
    {
        for(int i=0;i<k+1;i++)
        {
            if(i==0 || i==k)
                printf("1");
            else
                printf("0");
        }
        return 0;
    }
    for(int i=0;i<k/2;i++)
    {
        if(str[i]!=str[k-1-i])
        {
            flag = 1;
            break;
        }
    }
    if(flag==0)
    {
        if(k%2==0)
        {
            int j = k/2-1;
            while(str[j]!='9')
            {
                str[j] = '0';
                str[k-1-j] = '0';
                j--;
            }
            str[j] = str[j] + 1;
        }
        else
        {
            int j = k/2;
            while(str[j]!='9')
            {
                str[j] = '0';
                str[k-1-j] = '0';
                j--;
            }
            str[j] = str[j] + 1;
        }
    }
    else
    {
        int flg = 0, pos=-1;
        for(int i=(k%2==0?k/2-1:k/2);i>=0;i--)
        {
            //printf("%d\n",flg);
            if(flg==1)
            {
                str[k-1-i] = str[i];
            }
            else
            {
                if(str[i]>str[k-1-i])
                    str[k-1-i] = str[i];
                else if(str[i]<str[k-1-i])
                {
                    char prev = str[i];
                    char mean = (str[i]+str[k-1-i])/2;
                    if(prev<mean)
                    {
                        //printf("%c %c\n",prev,mean);
                        flg = 1;
                        pos = i;
                    }
                    str[i] = mean;
                    str[k-1-i] = mean;
                }
            }
        }
        if(flg==1)
        {
            for(int i=pos+1;i<=(k%2==0?k/2-1:k/2);i++)
            {
                str[i] = '0';
                str[k-i-1] = '0';
            }
        }
    }
    for(int i=0;i<k;i++)
        printf("%c",str[i]);
    return 0;
}