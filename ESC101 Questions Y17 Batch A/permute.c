#include<stdio.h>
#include<string.h>

void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *a, int l, int r)
{
    int i;
    if (l == r)
        printf("%s\n", a);
    else
    {
        for (i = l; i <= r; i++)
        {
            swap((a+l), (a+i));
            permute(a, l+1, r);
            swap((a+l), (a+i));
        }
    }
}

int main()
{
    char str[6];
    fgets(str,6,stdin);
    permute(str,0,strlen(str)-1);
    // printf("%d",strlen(str));
    // strncpy(s1,str,2);strncpy(s2,str+3,6-4);
    // printf("%s %s",s1,s2);
    return 0;
}