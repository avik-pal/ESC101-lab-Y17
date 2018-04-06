#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

typedef struct Vertices
{
    int x;
    int y;
} Vertex;

typedef struct Triangles
{
    Vertex A;
    Vertex B;
    Vertex C;
} Triangle;

float norm(Vertex a, Vertex b)
{
    return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}

float area(float a, float b, float c)
{
    float s = (a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main()
{
    Triangle T;
    Vertex V;
    
    // Take Input of Triangle and Vertex
    // Insert your code here
    scanf("%d %d %d %d %d %d %d %d",&T.A.x,&T.A.y,&T.B.x,&T.B.y,&T.C.x,&T.C.y,&V.x,&V.y);
    float a,b,c;
    a = norm(T.C,T.B);
    b = norm(T.A,T.C);
    c = norm(T.B,T.A);
    if(a+b<=c || a+c<=b || b+c<=a)
        printf("Invalid Triangle");
    else
    {
        float f,d,e;
        f = norm(T.A,V);
        d = norm(T.B,V);
        e = norm(T.C,V);
        // printf("%f %f %f %f %f %f\n",area(a,b,c),area(a,d,e),area(b,f,e),area(c,f,d),area(a,d,e)+area(b,f,e)+area(c,f,d),area(a,b,c)-area(a,d,e)-area(b,f,e)-area(c,f,d));
        if(area(a,b,c)-area(a,d,e)-area(b,f,e)-area(c,f,d)<=0.1 && area(a,b,c)-area(a,d,e)-area(b,f,e)-area(c,f,d)>=-0.1)
            printf("Yes");
        else
            printf("No");
    }
    return 0;
}