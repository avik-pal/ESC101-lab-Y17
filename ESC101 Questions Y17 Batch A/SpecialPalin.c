#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int lengthof(int n)
{
    int count = 0;
    while(n>0)
    {
        count ++;
        n = n/10;
    }
    return count;
}

int is_special(long long int num, int num_digits) {
    //printf("%lld\n",num);
        if(num_digits<=1)
            return 1;
        if(num%10-1!=num/(long long int)pow(10,num_digits-1))
        {
           // printf("%lld %lld\n",num%10-1,num/(long long int)pow(10,num_digits-1));
            if(num%10==0)
            {
                if(9!=num/(int)pow(10,num_digits-1))
                    return 0;
            }
            else
                return 0;
        }
        long long int new_num = (num/10)%(long long int)pow(10,num_digits-2);
        //printf("%lld\n",new_num);
        return is_special(new_num, num_digits-2);
}

int main()
{
    long long int n,m;
    scanf("%lld",&n);
    m = n;
    int len = 0;
    while(m>0)
    {
        len++;
        m=m/10;
    }
    //printf("%d\n",len);
    int c =is_special(n,len);
    //printf("%d\n",c);
    if(c)
        printf("YES");
    else
        printf("NO");
    return 0;
}