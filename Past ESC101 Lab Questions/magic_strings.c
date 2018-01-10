/*Check if a given sentence is a magic string or not*/

#include<stdio.h>
#include<string.h>

int magic(char s[4])
{
  int flag = 1;
  for(int i =0;i<=2;i++)
  {
    if(s[0]-'a'<0 || s[0]-'a'>26)
      flag = 0;
    if(s[1]-'A'<0 || s[1]-'A'>26)
      flag = 0;
    if(s[2]-'0'<0 || s[2]-'0'>10)
      flag = 0;
  }
  return flag;
}

int main()
{
  printf("Enter the sentence: ");
  char str[31];
  fgets(str,31,stdin);
  printf("YES\n");
  char srt[4];
  srt[3] = '\0';
  int flag = 1;
  for(int i = 0;i<=29;i+=3)
  {
    if(str[i+1]=='\0')
      break;
    srt[0] = str[i];
    srt[1] = str[i+1];
    srt[2] = str[i+2];
    printf("Before Call %d flag %d srt %s\n",i,flag,srt);
    flag = magic(srt);
    printf("Call %d flag %d\n",i,flag);
    if(flag==0)
      break;
  }
  printf("%d\n",flag);
}
