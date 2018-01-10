#include<stdio.h>

int main()
{
  int n;
  scanf("%d",&n);
  int A[n];
  int i;
  for(i=0;i<n;i++)
    scanf("%d",&A[i]);
  int maxSum = -1;
  for(i=0;i<n;i++)
  {
    if(A[i]<=0)
      continue;
    int bestSum = -1;
    for(int j=i;j<n;j++)
    {
      int currSum = 0;
      for(int k=i;k<=j;k++)
        currSum += A[k];
      if(currSum>bestSum)
        bestSum = currSum;
    }
    if(maxSum<bestSum)
      maxSum = bestSum;
  }
  printf("%d\n",maxSum);
}
