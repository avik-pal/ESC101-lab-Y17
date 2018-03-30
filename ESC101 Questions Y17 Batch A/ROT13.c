#include<stdio.h>

int read_line(char str[],int limit ) {
    // read a line into str, return length.
    // maximum allowed length is limit
    int length = 0;
    int c;
    while(limit>0)
    {
        c = getchar();
        //printf("%c\n",c);
        if(c==EOF)
        {
            str[length] = '\0';
            return length+1;
        }
        str[length] = c;
        length++;
        limit--;
    }
    return length;
}

void rotCipher(char *str, int length){
    for(int i=0;i<length;i++)
    {
        if(str[i]=='\0')
            break;
        if(str[i]==' ')
            continue;
        // printf("1. %s\n",str);
        int l = (str[i] - 2 * 'a'- 12 + 'z')%('z'-'a' + 1);
        str[i] = l + 'a';
        // printf("2. %c\n",str[i]);
    }
}

int main()
{
    char str[100];
    int length = read_line(str,100);
    //printf("%d\n",length);
    rotCipher(str, length);
    printf("%s",str);
    return 0;
}