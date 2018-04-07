#include<stdio.h>

int Count_Cont(char s[], int len)
{
    int i;
    int max = -1;
    int count = 0;
    for(i=0;i<len;i++)
    {
        if(s[i]=='0')
        {
            if(count>max)
                max = count;
            count = 0;
            continue;
        }
        count++;
    }
    if(count>max)
        max = count;
    return max;
}

int Ones(char s[], int len)
{
    int i, count = 0;
    for(i=0;i<len;i++)
    {
        if(s[i]=='1')
            count++;
    }
    return count;
}

int flipbits(char s[], int len)
{
    int enc1=0, enc0=0;
    int count = 0;
    int max = -1;
    int pos = 0;
    int end = -1, beg = -1;
    int end_best = -1, beg_best = -1;
    for(int i=0;i<len;i++)
    {
        if(s[i]=='0' && enc1==2 && enc0==1)
        {
            end = i;
            if(count>=max)
            {
                max = count;
                end_best = end;
                beg_best = beg;
            }
            enc1 = 0;
            enc0 = 0;
            count = 0;
            i = pos-1;
            continue;
        }
        if(s[i]=='0')
            enc0 = 1;
        if(s[i]=='1')
        {
            if(enc1==0)
            {
                beg = i;
                enc1++;
            }
            else if(enc1==1 && enc0==1)
            {
                pos = i;
                enc1++;
            }
        }
        count++;
    }
    if(count>=max)
    {
        end_best = len;
        beg_best = beg;
        max = count;
    }
    // printf("beg = %d end = %d\n",beg_best,end_best);
    // printf("max = %d\n",max);
    for(int i = 0;i<beg_best;i++)
    {
        if(s[i]=='1')
            max++;
    }
    // printf("max = %d\n",max);
    for(int i = end_best;i<len;i++)
    {
        if(s[i]=='1')
            max++;
    }
    // printf("max = %d\n",max);
    return max;
}

int main()
{
    //  Insert your code here.
    int len=0,i=500;
    char c;
    char s[500];
    c = getchar();
    while(c!='\0' && c!=EOF && i!=0)
    {
        s[len++] = c;
        c = getchar();
        i--;
    }
    s[len] = '\0';
    int contones = Count_Cont(s,len);
    printf("\'Original String\':\n%d\n",contones);
    printf("\'Flipped String\':\n%d",flipbits(s,len));
    return 0;
}