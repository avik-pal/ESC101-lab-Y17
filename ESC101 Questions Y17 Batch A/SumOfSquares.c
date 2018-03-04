#include <stdio.h>
#include <stdlib.h>

void read_to_array(int arr[], int);
void print_array(int arr[], int);
void copy_array(int arr1[], int arr2[], int);
int array_sum(int arr[], int);


int main(){
    int n;
    scanf("%d",&n);
    int a[n], b[n];
    read_to_array(a,n);
    copy_array(a,b,n);
    print_array(b, n);
    printf("%.2f",sqrt(array_sum(b,n)));
    return 0;
}

void read_to_array(int a[], int n)
{
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]); 
}

void print_array(int a[], int n)
{
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}

void copy_array(int a[], int b[], int n)
{
    for(int i=0;i<n;i++)
        b[i] = a[i]*a[i];
}

int array_sum(int a[], int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
        sum += a[i];
    return sum;
}