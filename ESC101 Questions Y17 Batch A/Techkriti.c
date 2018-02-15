#include<stdio.h>

int main()
{
    int c_open = 0, c_closed = 0;
    char ch;
    
    do
    {
        scanf("%c",&ch);
        switch(ch)
        {
            case '(':
                    c_open++;
                    break;
            case ')':
                    c_closed++;
                    break;
        }
        if(c_closed>c_open)
            break;
    }while(ch=='(' || ch==')');
    
    if(c_open==c_closed)
        printf("ALLOWED");
    else
        printf("NOT ALLOWED");
    
    return 0;
}