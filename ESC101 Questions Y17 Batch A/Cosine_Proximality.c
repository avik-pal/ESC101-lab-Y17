#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
    int A[10], B[10];
    for(int i=0;i<10;i++)
        scanf("%1d",&A[i]);
    for(int i=0;i<10;i++)
        scanf("%1d",&B[i]);
    float sum1=0.0, sum2=0.0, sum3=0.0;
    for(int i=0;i<10;i++)
    {
        sum1 += A[i]*B[i];
        sum2 += A[i]*A[i];
        sum3 += B[i]*B[i];
    }
    float s = sum1/(sqrt(sum2)*sqrt(sum3));
    printf("Your compatibility is %.2f\n",s);
    printf("The corresponding grade is ");
    if(s>=0.9)
        printf("S");
    else if(s>=0.8)
        printf("A");
    else if(s>=0.7)
        printf("B");
    else if(s>=0.6)
        printf("C");
    else if(s>=0.5)
        printf("D");
    else
        printf("F");
    return 0;
}