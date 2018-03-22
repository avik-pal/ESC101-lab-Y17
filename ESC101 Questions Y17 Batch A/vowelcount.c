#include <stdio.h>
#include <stdlib.h>

int* count( char *A, int n ){
	// Insert your code here. DO NOT modify the arguments of the function.
	int *B = (int *)malloc(2 * sizeof(int));
    for(int i=0;i<n;i++)
    {
        char c = *(A+i);
        //printf("%c\n",c);
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
            *(B) += 1;
        else if((c<='z'&&c>='a') || (c<='Z'&&c>='A'))
            *(B+1) += 1;
    }
    return B;
}

int main(){
	int n;
	scanf("%d\n",&n);
	char *A;
	A = (char *)malloc(n * sizeof(char));
	for(int i=0;i<n;i++)
	    scanf("%c",(A+i));
	int *B = count(A,n);
	printf("%d %d",*B,*(B+1));
    return 0;
}