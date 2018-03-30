#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>

typedef char* String;

int isSubStr(String s1, String s2)
{
    int len1 = strlen(s1);
    for(int i=0;i<len1;i++)
    {
        // printf("%s %c\n",s2,s1[i]);
        char *c = strchr(s2,s1[i]);
        // printf("%s\n",c);
        if(c==NULL)
            return 0;
        s2 = c;
    }
    return 1;
}

int main()
{
    // Allocate memory dynamically for each string seperately.
    // You will be penalized if you are using more than the optimal memory needed by input.
    int lena, lenb;
    scanf("%d %d\n",&lena,&lenb);
    //printf("%d %d\n",lena,lenb);
    String a = (String)malloc(lena * sizeof(char));
    String b = (String)malloc(lenb * sizeof(char));
    for(int i=0;i<lena;i++)
    {
        scanf("%c",&a[i]);
    }
    scanf("\n");
    for(int i=0;i<lenb;i++)
    {
        scanf("%c",&b[i]);
    }
    if(isSubStr(a,b))
        printf("YES");
    else
        printf("NO");
    free(a);
    free(b);
    return 0;
}