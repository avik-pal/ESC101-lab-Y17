#include<stdio.h>

struct record{
    char *name;
    int id;
};
typedef struct record rec;

void read_records(rec **records_p, int n);
void print_records(rec *records, int n);
void update1(rec *records);
void update2(rec *records);

int main()
{
    //  Insert your code here.
    int n;
    scanf("%d",&n);
    rec *arr = (rec *)malloc(n * sizeof(rec));
    read_records(&arr,n);
    update1(arr);
    update2(arr);
    print_records(arr,n);
    return 0;
}

void read_records(rec **a, int n)
{
    for(int i=0;i<n;i++)
    {
        int size;
        scanf("%d ",&size);
        // printf("size = %d\n",size);
        ((*a)+i)->name = (char *)malloc(size * sizeof(char));
        fgets(((*a)+i)->name,size+1,stdin);
        // printf("string = %s\n",(((*a)+i)->name));
        scanf(" %d",&(((*a)+i)->id));
        // printf("id = %d\n",(((*a)+i)->id));
    }
}

void update1(rec *a)
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int c;
        scanf("%d",&c);
        if(c==1)
            continue;
        free((a+c-1)->name);
        (a+c-1)->name = (char *)malloc(strlen(a[c-2].name) * sizeof(char));
        for(int j=0;j<strlen(a[c-2].name);j++)
        {
            (a+c-1)->name[j] = a[c-2].name[j];
        }
        a[c-1].id = a[c-2].id;
    }
}

void update2(rec *a)
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int c;
        scanf("%d",&c);
        char c2 = a[c-1].name[0];
        a[c-1].name[0] =  islower(c2)?c2 - 'a' + 'A':c2;
    }
}

void print_records(rec *a, int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%s %d\n",a[i].name,a[i].id);
    }
}