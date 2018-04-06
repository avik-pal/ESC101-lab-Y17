#include<stdio.h>
#include<string.h>

int read_line(char str[],int limit ) {
    // read a line into str, return length.
    // maximum allowed length is limit
    int len = 0;
    char c = getchar();
    while(c!='\0' && c!=EOF)
    {
        str[len] = c;
        len++;
        c = getchar();
        limit--;
        if(limit==0)
            break;
    }
    len++;
    str[len-1] = '\0';
    return len;
}

void atbashCipher(char *str)
{
    // decrypts the given string
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]==' ')
            continue;
        str[i] = 'z' + 'a' - str[i];
    }
    printf("%s",str);
}

int main()
{
   char str[100];
   read_line(str,100);
   atbashCipher(str);
}