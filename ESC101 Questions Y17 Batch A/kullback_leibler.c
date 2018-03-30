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

int main()
{
    int d;
    scanf("%d",&d);
    float *p1 = (float *)malloc(d * sizeof(int));
    float *p2 = (float *)malloc(d * sizeof(int));
    int i;
    for(i=0;i<d;i++)
    {
        scanf("%f",p1+i);
    }
    for(i = 0;i<d;i++)
    {
        scanf("%f",p2+i);
    }
    printf("%f",getKLD(p1,p2,d));
    free(p1);
    free(p2);
    return 0;
}