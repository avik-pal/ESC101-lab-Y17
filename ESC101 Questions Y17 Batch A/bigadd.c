# include<stdio.h>
# include<string.h>

int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}

void addition(char A[], char B[]) 
{
    int la = strlen(A);
    int lb = strlen(B);
    int lc = max(la,lb) + 1;
    int poi = lc;
    char res[lc];  // To store result or sum of A and B
    
    int i, j, k, m, sum, carry=0;
    
    for(i = 0; i < lc; ++i)
        res[i] = '0';
        
    la = la-1;
    lb = lb-1;
    
    // Find Sum of A and B
    int l;
    int sum_temp = 0;
    // printf("%s\n",res);
    for(l=lc-1;l>=0;l--)
    {
        if(la>=0 && lb>=0)
        {
            sum_temp = (int)A[la]-'0' + (int)B[lb]-'0' + carry;
            // printf("%d %d %d %d\n",(int)A[la]-'0',(int)B[lb]-'0',sum_temp,carry);
            // printf("%c %c\n",A[la],B[lb]);
            la--;
            lb--;
        }
        else if(la==-1 && lb>=0)
        {
            sum_temp = (int)B[lb]-'0' + carry;
            // printf("%d %d %d %d\n",sum_temp,carry);
            lb--;
        }
        else if(la>=0 && lb==-1)
        {
            sum_temp = (int)A[la]-'0' + carry;
            // printf("%d %d %d %d\n",sum_temp,carry);
            la--;
        }
        else if(la==-1 && lb==-1)
        {
            // printf("%d %d %d %d\n",sum_temp,carry);
            break;
        }
        // printf("%d %d %d %d\n",la,lb,sum_temp,carry);
        if(sum_temp>=10)
        {
            carry = sum_temp/10;
            sum_temp = sum_temp%10;
        }
        else
            carry = 0;
        // printf("%d %d %d %d\n",la,lb,sum_temp,carry);
        res[l] = (char)sum_temp + '0';
        // printf("%s\n",res);
    }
    // Remove Extra Zeros from start.
    for(i=l+1;i<lc;i++)
        printf("%c",res[i]);
}



// Driver code
int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    char a[m],b[n];
    scanf("%s %s",a,b);
    addition(a,b);
    return 0;
}