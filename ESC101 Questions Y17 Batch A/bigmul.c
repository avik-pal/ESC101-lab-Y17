# include<stdio.h>
# include<string.h>

void multiply(char A[], char B[]) 
{
    int la = strlen(A);
    int lb = strlen(B);
    
    char res[la+lb+1]; // To Store A*B
    int i, j, k, start = 0, carry=0;
    
    for(i = 0; i < ( la + lb + 1); ++i)
        res[i] = '0';
    //printf("%d %d\n",la,lb);
    // Multiply A and B
    for(i=lb-1;i>=0;i--)
    {
        k = (la+lb)-(lb-i-1);
        for(j=la-1;j>=0;j--)
        {
            int pro_temp = ((int)A[j] - '0') * ((int)B[i] - '0')+carry;
            carry = 0;
            int pp = ((int)res[k]-'0'+(pro_temp)%10);
            carry = carry + pp/10;
            pp = pp%10;
            // printf("%d\n",pp);
            res[k] = (char)(pp+'0');
            // printf("%d %d %d %d %s\n",pro_temp,carry,((int)A[j] - '0'),((int)B[i] - '0'),res);
            carry = carry + pro_temp/10;
            k--;
        }
        res[k] = (char)((((int)res[k]-'0'+carry)) +'0');
        carry = 0;
        // printf("%s\n",res);
        // printf("\n");
    }
    // Remove Extra Zeros from start.
    // printf("%d\n",k);
    // printf("%s\n",res);
    int kon=0;
    for(kon=0;kon<la+lb;kon++)
    {
        if(res[kon]!='0')
            break;
    }
    for(i=kon;i<la+lb+1;i++)
         printf("%c",res[i]);
}

// Driver code
int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    char a[m],b[n];
    scanf("%s %s",a,b);
    multiply(a,b);
    return 0;
}