#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void sort(char *s)
{
    int i,j;
    for(i=0;i<strlen(s);i++)
    {
        for(j=0;j<strlen(s)-i-1;j++)
        {
            if(s[j]>s[j+1])
            {
                char temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }
}

int findpos(char *s, char c)
{
    int pos=0;
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]=='_')
            continue;
        pos++;
        if(c==s[i])
        {
            s[i] = '_';
            return pos-1;
        }
    }
    return -1;
}

int fact(int n)
{
    int facto = 1;
    while(n>0)
    {
        facto *= n;
        n--;
    }
    return facto;
}

int main()
{
    int len=0;
    char *s = (char *)malloc(7*sizeof(char));
    char c = getchar();
    int i = 7;
    while(c!='\0' && c!=EOF)
    {
        s[len] = c;
        len++;
        c = getchar();
        i--;
        if(i==0)
            break;
    }
    char str[len+1];
    for(i=0;i<len+1;i++)
    {
        str[i] = s[i];
    }
    s[len] = '\0';
    sort(s);
    int rank = 1;
    for(i=0;i<len;i++)
    {
        int a = findpos(s,str[i]);
        int b = fact(len-i-1);
        // printf("%s %s %d %d\n",s,str,a,b);
        rank += a * b;
    }
    printf("%d",rank);
    return 0;
}