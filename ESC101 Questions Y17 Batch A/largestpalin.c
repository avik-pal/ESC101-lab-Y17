#include<stdio.h>

int flag = 0;

void sort(char s[], int len)
{
    int i,j;
    for(i=0;i<len;i++)
    {
        for(j=0;j<len-i-1;j++)
        {
            if(s[j]<s[j+1])
            {
                char temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }
}

void getlargest(char s[], int len)
{
    // printf("Input is %s\n",s);
    if(len==1 || len==0)
        return;
    sort(s,len);
    // printf("After sort is %s\n",s);
    int i;
    int f = 0;
    for(int j=0;j<len;j++)
    {
        f=0;
        for(i=j+1;i<len;i++)
        {
            if(s[i]==s[j])
            {
                f = 1;
                char temp = s[i];
                s[i] = s[len-1];
                s[len-1] = temp;
                temp = s[j];
                s[j] = s[0];
                s[0] = temp;
            }
        }
        if(f==1)
            break;
    }
    if(f==0)
    {
        flag = 1;
        return;
    }
    getlargest(s+1,len-2);
}

int main()
{
    //  Insert your code here.
    char s[500];
    char c;
    int len=0,i=500;
    c = getchar();
    while(c!='\0' && c!=EOF && i!=0)
    {
        s[len++] = c;
        i--;
        c = getchar();
    }
    s[len] = '\0';
    getlargest(s,len);
    if(flag==1)
        printf("Not possible");
    else
        printf("%s",s);
    return 0;
}