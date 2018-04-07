#include<stdio.h>

int max(int a, int b)
{
    return a>b?a:b;
}

int findlongsub(char *s1, char *s2, int n, int m)
{
    if(m==0 || n==0)
        return 0;
    else if(s1[n-1]==s2[m-1])
        return 1 + findlongsub(s1,s2,n-1,m-1);
    else
        return max(findlongsub(s1,s2,n,m-1),findlongsub(s1,s2,n-1,m));
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    char s1[n+1], s2[m+1];
    char c = getchar();
    fgets(s1,n+1,stdin);
    c = getchar();
    fgets(s2,m+1,stdin);
    int length = findlongsub(s1,s2,n,m);
    printf("%d",m+n-length);
    return 0;
}