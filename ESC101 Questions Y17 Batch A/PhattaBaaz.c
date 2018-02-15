#include<stdio.h>

int main()
{
    int min=-1, max=-1;
    double ovr_rate = 0.0;
    int overs = 0;
    int min_pos = 1, max_pos = 1;
    scanf("%d",&overs);
    
    for(int i = 1;i<=overs;i++)
    {
        int runs = 0;
        scanf("%d",&runs);
        
        ovr_rate += runs;
        if(min == -1)
            min = runs;
        if(runs>max)
        {
            max = runs;
            max_pos = i;
        }
        if(runs<min)
        {
            min = runs;
            min_pos = i;
        }
    }
    ovr_rate /= overs;
    
    if(ovr_rate - min > max - ovr_rate)
        printf("%d",min_pos);
    else if(ovr_rate - min < max - ovr_rate)
        printf("%d",max_pos);
    else
        if(max_pos<min_pos)
            printf("%d",max_pos);
        else
            printf("%d",min_pos);
    
    return 0;
}