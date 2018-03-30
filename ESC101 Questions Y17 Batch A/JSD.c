#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float getKLD(float *P, float *Q, int dim)
{
    int i;
    float D = 0.0;
    for(i=0;i<dim;i++)
    {
        D += P[i]*log(P[i]/Q[i]);
    }
    return D;
}

float getJSD(float *P, float *Q, int dim)
{
    float *M = (float *)malloc(dim * sizeof(float));
    for(int i=0;i<dim;i++)
        M[i] = (P[i]+Q[i])/2;
    return 0.5 * (getKLD(P,M,dim) + getKLD(Q,M,dim));
}

int main()
{
    int d;
    scanf("%d",&d);
    float *p1 = (float *)malloc(d * sizeof(float));
    float *p2 = (float *)malloc(d * sizeof(float));
    int i;
    for(i=0;i<d;i++)
    {
        scanf("%f",p1+i);
    }
    for(i = 0;i<d;i++)
    {
        scanf("%f",p2+i);
    }
    printf("%f",getJSD(p1,p2,d));
    free(p1);
    free(p2);
    return 0;
}