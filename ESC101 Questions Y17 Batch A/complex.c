#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct complex
{
    int r;
    int i;
};
    
void read(struct complex *);
void print(struct complex *);
struct complex add(struct complex *,struct complex *);
struct complex mul(struct complex *,struct complex *);
struct complex divide(struct complex *,struct complex *);

int main()
{
    //  Insert your code here.
    struct complex *a = (struct complex *)malloc(sizeof(struct complex *));
    struct complex *b = (struct complex *)malloc(sizeof(struct complex *));
    read(a);
    read(b);
    struct complex *c = (struct complex *)malloc(sizeof(struct complex *));
    *c = add(a,b);
    print(c);
    *c = mul(a,b);
    print(c);
    *c = divide(a,b);
    print(c);
    return 0;
}

void read(struct complex *a)
{
    scanf("%d",&(a->r));
    scanf("%d",&(a->i));
}

void print(struct complex *a)
{
    printf("%d %d\n",a->r,a->i);
}

struct complex divide(struct complex *a, struct complex *b)
{
    b->i = -b->i;
    struct complex c = mul(a,b);
    float norm = b->r * b->r + b->i * b->i;
    c.r = floor(c.r/norm);
    c.i = floor(c.i/norm);
    return c;
}

struct complex mul(struct complex *a, struct complex *b)
{
    struct complex c;
    c.r = a->r * b->r - a->i * b->i;
    c.i = a->i * b->r + a->r * b->i;
    return c;
}

struct complex add(struct complex *a, struct complex *b)
{
    struct complex c;
    c.r = a->r + b->r;
    c.i = a->i + b->i;
    return c;
}