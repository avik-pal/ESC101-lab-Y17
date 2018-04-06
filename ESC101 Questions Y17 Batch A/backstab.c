#include<stdio.h>
#include<stdlib.h>

struct Interval {
     int start;
     int end;
 };
typedef struct Interval interval;

void read_intervals(interval **interval_p, int n);
void print_intervals(interval *intervals, int n);

// new_n : populate the new length of returned array of intervals in new_n
interval* merge(interval *intervals, int n, int *new_n);

int main()
{
    //  Insert your code here.
    int n;
    scanf("%d",&n);
    interval *intervals = (interval *)malloc(n * sizeof(interval));
    read_intervals(&intervals, n);
    int merge_size = 0;
    print_intervals(merge(intervals,n,&merge_size),merge_size+1);
    // printf("%d\n",merge_size);
    return 0;
}

interval* merge(interval *a, int n, int *new_n)
{
    interval *b = (interval *)malloc(sizeof(interval));
    b[0].start = a[0].start;
    b[0].end = a[0].end;
    for(int i=1;i<n;i++)
    {
        if(b[*new_n].end>=a[i].start)
        {
            b[*new_n].end = a[i].end>b[*new_n].end?a[i].end:b[*new_n].end;
        }
        else
        {
            *new_n = *new_n + 1;
            b[*new_n].start = a[i].start;
            b[*new_n].end = a[i].end;
        }
        // printf("new_n is %d\n",*new_n);
    }
    return b;
}

void print_intervals(interval *a, int n)
{
    for(int i=0;i<n;i++)
        printf("%d %d \n",(a[i]).start,(a[i]).end);
}

void read_intervals(interval **a, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&((*(a)+i)->start),&((*(a)+i)->end));
    }
}