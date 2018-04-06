#include<stdio.h>
#include<stdlib.h>
int *head,*tail,size;
void createQueue(int siz)
{
    head = (int *)malloc(siz * sizeof(int));
    tail = head;
    size = siz;
}

void Enqueue(int element)
{
    if(tail-head==size)
        printf("Queue Overflow\n");
    else
    {
        *(tail) = element;
        tail = tail + 1;
        printf("Enqueued %d\n",*(tail-1));
    }
}

void Dequeue()
{
    if(tail==head)
        printf("Underflow\n");
    else
    {
        printf("Removed %d\n",*head);
        for(int i=1;i<=tail-head;i++)
        {
            *(head+i-1) = *(head+i);
        }
        tail = tail-1;
    }
}

int main()
{
	int siz,ch;
	scanf("%d",&siz);
	createQueue(siz);
	do {
		int ele;
		scanf("%d",&ch);
		switch(ch) {
			case 1: scanf("%d",&ele);Enqueue(ele);break;
			case 2: Dequeue();break;
			case 3: break;	
		}
// 		for(int i=0;i<siz;i++)
// 		{
// 		    printf("%d ",*(head+i));
// 		}
// 		printf("\n");
	}while(ch!=3);
	return 0;
}