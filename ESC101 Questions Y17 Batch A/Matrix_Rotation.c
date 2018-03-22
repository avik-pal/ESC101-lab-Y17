#include <stdio.h>
#include <stdlib.h>


void rotate(int **, int);

void print2d(int **, int);

int main(){
  int n, **mat;
  
  scanf("%d",&n);
  mat = (int *)malloc(n*sizeof(int *));
  for(int i=0;i<n;i++)
  {
      *(mat+i) = (int *)malloc(n*sizeof(int));
      for(int j=0;j<n;j++)
      {
          scanf("%d",*(mat+i)+j);
      }
  }
  
  rotate(mat, n);
  print2d(mat, n);
  return 0;
}

void rotate(int **mat, int n){
    int i,j;
    int top = 0, bot = n-1, left = 0, right = n-1;
    for(i=1;i<=(n/2+1);i++)
    {
      for(j=left;j<=right-1;j++)
      {
          int temp = mat[top][j];
          //printf("%d  %d  %d  %d\n",mat[top][j],mat[j][right],mat[bot][n-j-2*i+1], mat[n-j-2*i+1][left]);

          mat[top][j] = mat[n-j-1][left];
          mat[n-j-1][left] = mat[bot][n-j-1];
          mat[bot][n-j-1] = mat[j][right];
          mat[j][right] = temp;
      }
      top = i;
      bot = n-i-1;
      left = i;
      right = n-i-1;
    }
}

void print2d(int **mat, int n){
  int i, j;

  for(i=0;i<n;i++){
    for(j=0;j<n;j++)
      printf("%d ", mat[i][j]);

    printf("\n");
  }
  return;
}