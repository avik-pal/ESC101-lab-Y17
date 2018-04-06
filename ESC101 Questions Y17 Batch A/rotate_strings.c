#include<stdio.h>
#include<string.h>

void rotate(char *s, int n)
{
    int i;
    char temp =s[0];
    for(i=0;i<n-1;i++)
    {
        s[i] = s[i+1];
    }
    s[n-1] = temp;
}

void operation(char str1[], char str2[], int n)
{
    int i;
    for(i=0;i<=strlen(str1)-strlen(str2);i++)
    {
        // printf("i = %d\n",i);
        int flag = 1;
        for(int j=0;j<strlen(str2);j++)
        {
            if(str1[i+j]!=str2[j])
            {
                flag = 0;
                break;
            }
        }
        if(flag==1)
        {
            for(int j=0;j<n;j++)
            {
                // printf("matched at %d where s is %c %s\n",i,str1[i],str1);
                rotate(str1+i,strlen(str2));
            }
            i += strlen(str2)-1;
        }
    }
    // printf("%s %s\n",str1,str2);
}

int main()
{
    char str1[1000],str2[1000];
    int len1=0,len2=0;
    char c;
    int i;
    c = getchar();
    for(i=0;i<1000;i++)
    {
        if(c=='\0' || c==EOF || c=='\n')
            break;
        str1[len1] = c;
        len1++;
        c = getchar();
    }
    str1[len1] = '\0';
    c = getchar();
    for(i=0;i<1000;i++)
    {
        if(c=='\0' || c==EOF || c=='\n')
            break;
        str2[len2] = c;
        len2++;
        c = getchar();
    }
    str2[len2] = '\0';
    int n;
    scanf("%d",&n);
    operation(str1,str2,n);
    printf("%s",str1);
    return 0;
}