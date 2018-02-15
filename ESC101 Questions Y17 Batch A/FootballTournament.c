#include<stdio.h>

int main()
{
    char c;
    int points = 0;
    int matches = 0;
    int flag = 1;
    
    while(flag==1)
    {
        scanf("%c",&c);
        switch(c)
        {
            case 'W':
                    points += 2;
            case 'D':
                    points += 1;
            case 'L':
                    matches++;
                    break;
            case '$':
                    flag=0;
                    break;
            default:
                    printf("Invalid");
                    return 0;
        }
    }
    
    if(matches==0)
    {
        printf("Forfeit");
        return 0;
    }
    
    float val = ((float)points)/matches;
    
    if(val>=1.5)
        printf("Qualified");
    else
        printf("Not Qualified");
    
    return 0;
}