#include<stdio.h>

typedef struct number
{
    char sign;
    float m;
    int e;
}num;

int check_valid(num *a)
{
    if(a->sign!='+' && a->sign!='-')
    {
        // printf("Fail1 %c\n",a->sign);
        return 0;
    }
    if(a->m<1.0 || a->m>=10.0)
    {
        // printf("Fail2 %f\n",a->m);
        return 0;
    }
    return 1;
}

void add(num *res, num *a, num *b)
{
    if(b->e - a->e > 6)
    {
        res->e = b->e;
        res->m = b->m;
        res->sign = b->sign;
    }
    else if(a->e - b->e > 6)
    {
        res->e = b->e;
        res->m = b->m;
        res->sign = b->sign;
    }
    else
    {
        int min = a->e > b->e ?b->e:a->e;
        float a1 = a->m;
        float a2 = b->m;
        for(int i=0;i<a->e-min;i++)
        {
            a1 *= 10;
        }
        for(int i=0;i<b->e-min;i++)
        {
            a2 *= 10;
        }
        if(a->sign=='-')
            a1 *= -1;
        if(b->sign=='-')
            a2 *= -1;
        res->e = min;
        float val = a1+a2;
        if(val<0)
        {
            val *= -1;
            res->sign = '-';
        }
        else
            res->sign = '+';
        res->m = val;
        while(res->m>10.0)
        {
            res->e += 1;
            res->m /= 10;
        }
    }
}

int main()
{
    //  Insert your code here.
    char *op;
    op = (char *)malloc(4*sizeof(char));
    fgets(op,4,stdin);
    num a,b;
    scanf("\n%c %f %d\n",&a.sign,&a.m,&a.e);
    scanf("%c %f %d",&b.sign,&b.m,&b.e);
    if(check_valid(&a)==0)
        printf("First number is invalid");
    else if(check_valid(&b)==0)
        printf("Second number is invalid");
    else
    {
        num new;
        if(op[0]=='a')
        {
            add(&new,&a,&b);
        }
        else if(op[0]=='s')
        {
            if(b.sign=='-')
                b.sign = '+';
            else
                b.sign = '-';
            add(&new,&a,&b);
        }
        else
        {
            if(((a.sign=='+')&&(b.sign=='-'))||((a.sign=='-')&&(b.sign=='+')))
                new.sign = '-';
            else
                new.sign = '+';
            new.m = a.m * b.m;
            new.e = a.e + b.e;
            if(new.m>=10.0)
            {
                new.m /= 10;
                new.e += 1;
            }
        }
        printf("%c %f %d",new.sign,new.m,new.e);
    }
    return 0;
}