#include<stdio.h>
#include<stdlib.h>

void make_wave(int * a , int num ){
    // Complete the function
    for(int i=0;i<num-1;i++)
    {
        if(i%2==0)
        {
            if(a[i]<a[i+1])
            {
                int temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
            }
        }
        else
        {
            if(a[i]>a[i+1])
            {
                int temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
            }
        }
    }
}

int main()
{
    // Don't Edit
    int n;
    scanf("%d",&n);
    int * sorted_array;
    sorted_array = (int*)malloc(n*sizeof(int));
    int i;
    
    for(i = 0; i < n ; ++i){
        scanf("%d",sorted_array + i);
    }
    make_wave(sorted_array ,n); 
    // Don't Edit above written code.
    
    // Print the Array
    for(i =0; i<n;i++)
    {
        printf("%d ",*(sorted_array+i));
    }
    return 0;
}