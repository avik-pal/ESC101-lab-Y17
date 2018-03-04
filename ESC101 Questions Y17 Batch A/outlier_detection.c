#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int read_to_array(int arr[], int);
void print_array(int arr[], int);
void copy_array(int arr1[], int arr2[], int size);

float array_mean(int arr[], int);
float array_std(int arr[], int size);

void normal_outliers(int arr[], int size);

int main(){
    int temp[100];
    int size = read_to_array(temp,100);
    int array[size];
    copy_array(temp,array,size);
    normal_outliers(array,size);
    return 0;
}

int read_to_array(int arr[], int size){
    int cnt = 0;
    for(cnt=0;cnt<size;cnt++)
    {
        scanf("%d",&arr[cnt]);
        if(arr[cnt]==-1)
            break;
    }
    
    return cnt;         // we are returning a value. what are we returning and why?
}

void print_array(int arr[], int size){
    int i;
    for(i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return;
}

float array_mean(int arr[], int size){
    int sum = 0;
    for(int i=0;i<size;i++)
    {
        sum+=arr[i];
    }
    return sum/(float)size;
}

float array_std(int arr[], int size){
    int mean = array_mean(arr,size);
    int sum = 0;
    for(int i=0;i<size;i++)
        sum += (arr[i]-mean)*(arr[i]-mean);
    return sqrt(sum/(float)size);
}


void copy_array(int arr1[], int arr2[], int size){
    int i;
    for(i=0;i<size;i++){
        arr2[i] = arr1[i];
    }
    return;
}

void normal_outliers(int arr[], int size){
    int i, sum = 0, cnt = 0;
    float mean = array_mean(arr,size);
    int flag = mean>0?1:0;
    float std = mean>0?array_std(arr,size):-array_std(arr,size);
    print_array(arr,size);
    for(i=0;i<size;i++)
    {
        if(arr[i]<=mean+std && arr[i]>=mean-std && flag==1)
        {
            printf("%d ",arr[i]);
            sum += arr[i];
            cnt++;
        }
        if(arr[i]>=mean+std && arr[i]<=mean-std && flag==0)
        {
            printf("%d ",arr[i]);
            sum += arr[i];
            cnt++;
        }
    }
    printf("\nOriginal mean is %.2f\nCorrected mean is %.2f",mean,(float)sum/cnt);
    return;
}