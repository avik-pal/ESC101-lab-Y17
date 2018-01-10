/*Print the last letters of a given sentence*/

#include<stdio.h>
#include<string.h>

int main()
{
  printf("Enter the Sentence: ");
  char str[101];
  fgets(str,101,stdin);
  char s[101];
  int c=0;
  int i = 0;
  for(i = 0; i <= sizeof(str); i++)
  {
    if(str[i]==' ')
    {
      s[c] = str[i-1];
      c++;
    }
    if(str[i]=='\0')
      break;
  }
  //printf("%s\n",str);
  s[c] = str[i-2];
  s[c+1] = '\0';
  //printf("%d\n",i-1 );
  //printf("%c\n",str[i-1]);
  printf("%s\n",s);
  //printf("%c\n",s[3]);
  return 0;
}
