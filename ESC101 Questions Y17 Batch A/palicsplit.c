#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int ispalin(char *a)
{
    // printf("%s\n",a);
    int i;
    for(i=0;i<strlen(a)/2;i++)
    {
        if(a[i]!=a[strlen(a)-i-1])
        {
            // printf("%d %c\n",i,a[i]);
            return 0;
        }
    }
    // printf("\n");
    return 1;
}

int main()
{
    //  Insert your code here.
    char str[20];
    int i,len=0;
    char c = getchar();
    for(i=0;i<20;i++)
    {
        if(c=='\0' || c==EOF)
            break;
        str[len++] = c;
        c = getchar();
    }
    str[len] = '\0';
    int count = 0;
    for(i=1;i<len;i++)
    {
        char *s1 = (char *)malloc(i+1*sizeof(char));
        char *s2 = (char *)malloc((len-i+1)*sizeof(char));
        int j;
        for(j=0;j<i;j++)
            s1[j] = str[j];
        s1[j] = '\0';
        int k=0;
        for(j=i;j<len;j++)
            s2[k++] = str[j];
        s2[j] = '\0';
        // printf("%s %s\n",s1,s2);
        if(ispalin(s1) && ispalin(s2))
        {
            // printf("Palindromes are %s %s\n",s1,s2);
            count++;
        }
        free(s1);
        free(s2);
    }
    printf("%d",count);
    return 0;
}