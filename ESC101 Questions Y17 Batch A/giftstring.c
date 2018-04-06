#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

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

int main()
{
    //  Insert your code here.
    int k;
    int len=0;
    char *s = (char *)malloc(100*sizeof(char));
    char c = getchar();
    int i = 100;
    while(c!='\n' && c!=EOF)
    {
        s[len] = c;
        len++;
        c = getchar();
        i--;
        if(i==0)
            break;
    }
    s[len] = '\0';
    scanf("%d\n",&k);
    int flag = 0;
    for(i=1;pow(2,i)<=strlen(s);i++)
    {
        if(pow(2,i)==strlen(s))
        {
            flag = 1;
            break;
        }
    }
    if(flag == 1)
        k = k/2;
    else
        k = k*2;
    if(strlen(s)<k)
    {
        printf("-1");
        return 0;
    }
    sort(s);
    for(i=0;i<strlen(s)-k;i++)
        printf("%c",s[i]);
    free(s);
    return 0;
}