#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    //define the details of the structure
    int data;
    struct node *next;
}NODE;

NODE *input()
{
    NODE *head = (NODE *)malloc(sizeof(NODE));
    NODE *ptr = (NODE *)malloc(sizeof(NODE));
    head = NULL;
    ptr = NULL;
    int val;
    scanf("%d",&val);
    while(val!=-1)
    {
        NODE *new = (NODE *)malloc(sizeof(NODE));
        new->data = val;
        new->next = NULL;
        if(head==NULL)
        {
            head = new;
            ptr = new;
        }
        else
        {
            ptr->next = new;
            ptr = new;
        }
        scanf("%d",&val);
    }
    return head;
}

void printList(NODE *head)
{
    NODE *ptr = (NODE *)malloc(sizeof(NODE));
    ptr = head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->next; 
    }
    printf("\n");
}

NODE *solve(NODE *head)
{
    NODE *ptr1;
    NODE *ptr2;
    NODE *ptr;
    ptr1 = head;
    int n=0;
    if(head==NULL)
        return head;
    while(ptr1!=NULL)
    {
        n++;
        ptr1 = ptr1->next;
    }
    n = n/2;
    ptr1 = head;
    ptr = head;
    ptr2 = head->next;
    for(int i=1;i<=n;i++)
    {
        // printf("%d %d %d %d yes\n",i,ptr->data,ptr1->data,ptr2->data);
        // printList(head);
        if(i==1)
        {
            ptr1->next = ptr2->next;
            ptr2->next = ptr1;
            head = ptr2;
        }
        else
        {
            ptr1->next = ptr2->next;
            ptr2->next = ptr1;
            ptr->next = ptr2;
        }
        ptr = ptr1;
        ptr1 = ptr1->next;
        if(ptr1!=NULL)
            ptr2 = ptr1->next;
    }
    return head;
}

int main()
{
    NODE* head;
    head = input();
    printList(solve(head));
    return 0;
}