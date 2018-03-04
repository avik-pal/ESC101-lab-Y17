#include<stdio.h>

void print_arr(int a[], int n) {
    for(int i=0;i<n-1;i++)
        printf("%d ",a[i]);
    printf("%d\n",a[n-1]);
}

void copy_arr(int a[], int b[], int n) {
    for(int i=0;i<n;i++)
        b[i] = a[i];
}

int same_arr(int a[], int b[], int n) {
    for(int i=0;i<n;i++)
        if(a[i]!=b[i])
            return 0;
    return 1;
}

int remove_mode(int a[], int n, int LIM) {
    int i=0;
    int c_max=-1,cnt=0,j=0,num=-1;
    for(i=0;i<n;i++)
    {
        cnt = 0;
        for(j=i+1;j<n;j++)
        {
            if(a[j]==a[i])
                cnt++;
        }
        if(cnt>c_max)
        {
            c_max = cnt;
            num = a[i];
        }
        else if(cnt==c_max)
        {
            if(num>a[i])
            {
                num=a[i];
                c_max = cnt;
            }
        }
    }
    int b[n-c_max];
    int counter = 0;
    for(i=0;i<n;i++)
    {
        if(a[i]!=num)
        {
            b[counter] = a[i];
            counter++;
        }
    }
    copy_arr(b,a,n-c_max);
    return n-c_max;
}

int append_prod(int a[], int n, int LIM) {
    int b[n+1];
    copy_arr(a,b,n);
    b[n] = 10;
    for(int i = 0;i<n;i++)
        b[n] *= a[i];
    //printf("%d ",b[n]);
    //print_arr(b,n+1);
    b[n] = b[n]%LIM;
    //printf("%d\n",b[n]);
    copy_arr(b,a,n+1);
    return n+1;
}

int main() {
    int n,m,lim;
    scanf("%d %d %d",&n,&m,&lim);
    int a[n];
    int i;
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    
    if(n==1)
    {
        print_arr(a,1);
        return 0;
    }
    //print_arr(a,n);
    for(i=0;i<m;i++)
    {
        int b[n];
        copy_arr(a,b,n);
        int new_size = remove_mode(a,n,lim);
        for(int j=1;j<=n-new_size+1;j++)
        {
            int c = append_prod(a,new_size+j-2,lim);
        }
        print_arr(a,n);
        if(same_arr(a,b,n))
            return 0;
    }
    return 0;
}