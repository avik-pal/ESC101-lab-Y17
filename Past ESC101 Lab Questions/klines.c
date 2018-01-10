/*Take a number K as input. Then take N strings as imput. Then print the strings as per the given condition.*/

#include<stdio.h>
#include<string.h>

int main()
{
    printf("Enter the value of k: ");
    int k;
    scanf("%d\n",&k);
    char str[1000][1000];
    int count = 0;
    while(1>0)
    {
        scanf("%[^\n]%c",str[count]);
        printf("Entered String No %d and string %s\n",count,str[count]);
        if(strcmp(str[count],"")==0)
            break;
        count++;
    }
    count++;
    if(count<=k)
    {
        printf("Yes break\n");
        for(int i=0;i<count;i++)
            printf("%s\n",str[i]);
    }
    else
        for(int i=count-k-1;i<count;i++)
            printf("%s\n",str[i]);
}
