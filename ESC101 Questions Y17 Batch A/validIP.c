#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int num(char s[], int n)
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
        int a = num(str,n-1) + ((int)s[0]-'0')*pow(10,n-1);
        return a;
    }
}

int main()
{
    int len=0, i=13;
    char s[13], ch;
    ch=getchar();
    while(ch!='\0' && ch!=EOF && i>0)
    {
        i--;
        s[len++] = ch;
        ch = getchar();
    }
    if(i==0)
    {
        printf("No Valid IP exists");
        return 0; 
    }
    s[len] = '\0';
    int a,b,c;
    int count = 0;
    
    for(a=1;a<=len-3;a++)
    {
        for(b=a+1;b<=len-2;b++)
        {
            for(c=b+1;c<=len-1;c++)
            {
                char *sb = (char *)malloc(a*sizeof(char));
                char *s1 = (char *)malloc((b-a)*sizeof(char));
                char *s2 = (char *)malloc((c-b)*sizeof(char));
                char *s3 = (char *)malloc((len-c)*sizeof(char));
                // printf("a = %d b = %d c = %d len = %d\n",a,b,c,len);
                int pos = 0;
                for(i = 0;i<a;i++)
                {
                    sb[pos++] = s[i];
                }
                pos = 0;
                for(i = a;i<b;i++)
                {
                    s1[pos++] = s[i];
                }
                pos = 0;
                for(i = b;i<c;i++)
                {
                    s2[pos++] = s[i];
                }
                pos = 0;
                for(i = c;i<len;i++)
                {
                    s3[pos++] = s[i];
                }
                int nn = num(sb,a);
                int n1 = num(s1,b-a);
                int n2 = num(s2,c-b);
                int n3 = num(s3,len-c);
                // printf("%s %s %s %s\n",sb,s1,s2,s3);
                // printf("%d %d %d %d\n",nn,n1,n2,n3);
                if(s2[0]=='0' && c-b>1)
                    continue;
                if(s1[0]=='0' && b-a>1)
                    continue;
                if(s3[0]=='0' && len-c>1)
                    continue;
                if(sb[0]=='0' && a>1)
                    continue;
                if(nn>=0 && nn<=255 && n1>=0 && n1<=255 && n2>=0 && n2<=255 && n3>=0 && n3<=255)
                {
                    count++;
                    printf("%d.%d.%d.%d\n",nn,n1,n2,n3);
                }
                free(sb);
                free(s1);
                free(s2);
                free(s3);
            }
        }
    }
    if(count==0)
        printf("No Valid IP exists");
    return 0;
}