#include<stdio.h>
#include<string.h>

int main()
{
    //  Insert your code here.
    char str1[100],str2[100];
    int len1=0,len2=0;
    char c;
    int i;
    c = getchar();
    for(i=0;i<100;i++)
    {
        if(c=='\0' || c==EOF || c=='\n')
            break;
        str1[len1] = c;
        len1++;
        c = getchar();
    }
    str1[len1] = '\0';
    c = getchar();
    for(i=0;i<100;i++)
    {
        if(c=='\0' || c==EOF)
            break;
        str2[len2] = c;
        len2++;
        c = getchar();
    }
    str2[len2] = '\0';
    int flag1 = 0;
    for(i=0;i<len1;i++)
    {
        int flag = 0;
        for(int j=0;j<len1;j++)
        {
            if(str1[i]==str2[j])
            {
                flag = 1;
                str2[j] = '_';
                break;
            }
        }
        if(flag==0)
        {
            flag1 = 1;
            printf("no");
            break;
        }
    }
    if(!flag1)
        printf("yes");
    return 0;
}