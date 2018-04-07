#include<stdio.h>
#include<string.h>
#include<math.h>

long long int num(char s[], int n)
{
    if(n==0)
        return 0;
    else
    {
        char str[n-1];
        for(int i=0;i<n-1;i++)
        {
            str[i] = s[i+1];
        }
        str[n-1] = '\0';
        // printf("%s %s %d\n",str,s,((int)s[0]-'0')*10);
        int a = num(str,n-1) + ((int)s[0]-'0')*pow(10,n-1);
        // printf("%d\n",a);
        return a;
    }
}

long long int revnum(char s[], int n)
{
    if(n==0)
        return 0;
    else
    {
        char str[n-1];
        for(int i=0;i<n-1;i++)
        {
            str[i] = s[i+1];
        }
        str[n-1] = '\0';
        // printf("%s %s %d\n",str,s,((int)s[0]-'0')*10);
        int a = 10*revnum(str,n-1) + ((int)s[0]-'0');
        // printf("%d\n",a);
        return a;
    }
}

int main()
{
    int len=0,i=7;
    char c;
    char s[7];
    c = getchar();
    while(c!='\0' && c!=EOF && i!=0)
    {
        s[len++] = c;
        c = getchar();
        i--;
    }
    s[len] = '\0';
    printf("%lld",revnum(s,len)+num(s,len));
    return 0;
}