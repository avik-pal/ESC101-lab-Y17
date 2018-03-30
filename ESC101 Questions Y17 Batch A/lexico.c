#include<stdio.h>

void sort(char s[], int n)
{
    char temp;
    int i,j;
    for(i=0;i<n-1;i++)
    {
        char c = s[i];
        int pos = i;
        for(j=i+1;j<n-1;j++)
        {
            if(s[j]<c)
            {
                pos = j;
                c = s[j];
            }
        }
        // printf("2. %d %d\n",i,pos);
        temp = s[i];
        s[i] = s[pos];
        s[pos] = temp;
    }
    // printf("\n");
}

int main()
{
    int i;
    char str1[10], str2[10];
    int len1 = 0, len2 = 0;
    for(i=0;i<10;i++)
    {
        char c = getchar();
        len1++;
        if(c=='\n' || c=='\0' || c==EOF)
        {
            str1[i] = '\0';
            break;
        }
        str1[i] = c;
    }
    for(i=0;i<10;i++)
    {
        char c = getchar();
        len2++;
        if(c=='\n' || c=='\0' || c==EOF)
        {
            str2[i] = '\0';
            break;
        }
        str2[i] = c;
    }
    // printf("%d %d\n%s\n%s\n",len1,len2,str1,str2);
    sort(str1, len1);
    sort(str2, len2);
    // printf("%s\n%s\n",str1,str2);
    int flag = 1;
    for(i = 0;i<((len1>len2)?len2:len1)-1;i++)
    {
        // printf("%c %c\n",str1[i],str2[i]);
        if(str1[i] > str2[i])
        {
            // printf("%c %c\n",str1[i],str2[i]);
            flag = -1;
            break;
        }
    }
    printf("%d",flag);
    
    return 0;
}