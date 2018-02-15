#include<stdio.h>

int main()
{
    int count = 0;
    int count_proper = 0;
    char ch = '.';
    char cnew = '0';
    do
    {
        scanf("%c",&cnew);
        if(ch=='.')
        {
            ch = cnew;
            printf("%c",cnew);
            count_proper++;
            count = -1;
        }
        if(ch==cnew)
            count++;
        else
        {
            ch=cnew;
            printf("%c",cnew);
            count_proper++;
        }
        
    }while(cnew!='.');
    
    printf("\n");
    if(count%count_proper==0)
        printf("Fail");
    else
        printf("Check_Safe");
    
    return 0;
}