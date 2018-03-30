#include <stdio.h>

int main() {
    int n,k,r;
    scanf("%d %d %d\n",&n,&k,&r);
    char s[n+1];
    fgets(s,n+1,stdin);
    // printf("%s",s);
    int i;
    k = k%26;
    r = r%n;
    for(i=0;i<n+1;i++)
    {
        char c = s[i];
        if(c>='a' && c<='z')
        {
            c = (c - 'a' + k)%('z' - 'a' + 1) + 'a';
            s[i] = c;
        }
    }
    // printf("%s",s);
    char s2[n+1];
    s2[n+1] = "\0";
    int k2=0;
    for(i=n-r;i<n;i++)
    {
        s2[k2] = s[i];
        k2++;
    }
    for(i=0;i<n-r;i++)
    {
        s2[k2] = s[i];
        k2++;
    }
    for(i=0;i<n;i++)
    {
        printf("%c",s2[i]);
    }
    // printf("%d\n",k2);
    // printf("%s\n",s);
    // printf("%s",s2);
    return 0;
}