#include<stdio.h>

int main()
{
    long a = 0;
    char c;
    
    while(1)
    {
        scanf("%c",&c);
        if((c>'z' || c<'a') && (c>'Z' || c<'A'))
            break;
        if(c>'Z')
            c = c - 'a' + 'A';
        if(c-'A'+1>=10)
            a = a*100 + (c-'A'+1);
        else
            a = a*10 + (c-'A'+1);
    }
    while(a>0)
    {
        switch(a%10)
        {
            case 1:
                    printf("one ");
                    break;
            case 2:
                    printf("two ");
                    break;
            case 3:
                    printf("three ");
                    break;
            case 4:
                    printf("four ");
                    break;
            case 5:
                    printf("five ");
                    break;
            case 6:
                    printf("six ");
                    break;
            case 7:
                    printf("seven ");
                    break;
            case 8:
                    printf("eight ");
                    break;
            case 9:
                    printf("nine ");
                    break;
            case 0:
                    printf("zero ");
                    break;
        }
        a = a/10;
    }
    return 0;
}