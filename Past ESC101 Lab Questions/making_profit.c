#include <stdio.h>

int main() {
    int n;
    int profit = 0;
    scanf("%d",&n);
    int A[n];
    for(int i=0;i<n;i++)
        scanf("%d",&A[i]);
    int i,j;
    for(i=0;i<n;i++)
    {
        int price = A[i];
        int max = price;
        for(j=i+1;j<n;j++)
        {
            if(max<A[j])
                max = A[j];
        }
        if(max - price>profit)
            profit = max - price;
    }
    printf("%d",profit);
    return 0;
}