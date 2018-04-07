#include<stdio.h>
int count=0;

void numways(char str[], int len)
{
    if(len==1)
    {
        count++;
    }
    else if(len==2)
    {
        int n1 = str[len-1] - '0';
        int n2 = str[len-2] - '0';
        n2 = n2*10 + n1;
        if(n2<=26)
            count++;
        numways(str,len-1);
    }
    else
    {
        int n1 = str[len-1] - '0';
        int n2 = str[len-2] - '0';
        n2 = n2*10 + n1;
        numways(str,len-1);
        if(n2<=26)
            numways(str,len-2);
    }
}

int main()
{
    int len = 0;
    char c = getchar(), str[100];
    while(c!='\0' && c!=EOF)
    {
        str[len++] = c;
        c = getchar();
    }
    str[len] = '\0';
    numways(str,len);
    printf("Number of possible strings is %d.",count);
    return 0;
}