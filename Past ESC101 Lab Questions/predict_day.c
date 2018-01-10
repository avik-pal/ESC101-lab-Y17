#include<stdio.h>

int isLeap(int yr)
{
  if(yr%4==0)
  {
    if(yr%400==0 && yr%100==0)
      return 0;
    return 1;
  }
  printf("0");
  return 0;
}

int main()
{
  int yr, start, day, month;
  scanf("%d%d\n%d%d",&yr,&start,&day,&month);
  int leap = isLeap(yr);
  printf("%d\n",leap);
  int days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
  if(leap==1)
    days[2] += 1;
  int count = day;
  for(int i=1;i<month;i++)
  {
    count += days[i];
  }
  printf("%d\n",count);
  printf("%d\n",days[2]);
  printf("%d\n",(count+start-1)%7);
}
