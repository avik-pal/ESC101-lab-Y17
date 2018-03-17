#include<stdio.h>

int main()
{
    int n, m;
    char a[n+1];
    char b[m+1];
    scanf("%d\n%d\n",&n,&m);
    fgets(a,n+1,stdin);
    scanf("\n");
    fgets(b,m+1,stdin);
    int cost = 0, cost2 = 0;
    int charsize[26];
    for(int i=0;i<26;i++)
        charsize[i] = 0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>'Z')
            charsize[a[i]-'a']++;
        else
            charsize[a[i]-'A']++;
    }
    for(int i=0;i<m;i++)
    {
        if(b[i]>'Z')
            charsize[b[i]-'a']--;
        else
            charsize[b[i]-'A']--;
    }
    for(int i=0;i<26;i++)
    {
        printf("%c  %d\n",i+'a',charsize[i]);
        cost += charsize[i]>0?charsize[i]:-charsize[i];
        cost2 += charsize[i];
    }
    cost2 *= cost2>0?1:-1;
    printf("%d",(int)((cost+cost2)/2.0));
    return 0;
}