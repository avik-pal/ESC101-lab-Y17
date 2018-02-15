#include<stdio.h>

int isLeapYr(int n)
{
    if(n%400==0)
        return 29;
    else if(n%4==0 && n%100!=0)
        return 29;
    return 28;
}

void checkValidity(int d, int m, int y)
{
    int days = 28;
    if(d<=0 || m>12 || m<=0)
    {
        printf("Not Valid");
        return;
    }
    switch(m)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
                if(d>31)
                    printf("Not Valid");
                else
                    printf("Valid");
                break;
        case 4:
        case 6:
        case 9:
        case 11:
                if(d>30)
                    printf("Not Valid");
                else
                    printf("Valid");
                break;
        default:
                days = isLeapYr(y);
                if(d>days)
                    printf("Not Valid");
                else
                    printf("Valid");
    }
}

int main()
{
    int day,month,year;
    scanf("%d %d %d",&day,&month,&year);
    
    checkValidity(day,month,year);
    
    return 0;
}