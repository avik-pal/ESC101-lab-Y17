#include<stdio.h>
#include<stdlib.h>

int total = 0;
typedef struct node{
    //define the details of the structure
    int val;
    struct node *link;
}NODE;
void printList(NODE *);//function to print the solution
NODE* input();//Function to take input
NODE* solve(NODE*);//function to solve the problem
//define any function prototype you want to use


int main()
{
    NODE* head;
    head=input();
    printList(solve(head));
    return 0;
}
/*Do not modify the main function
 *Define the structure NODE properly
 *Write the body of the above mentioned function*/
 
//Write the body for all function definitions below
NODE* input()
{
    NODE *head = (NODE *)malloc(sizeof(NODE));
    NODE *ptr = (NODE *)malloc(sizeof(NODE));
    head = NULL;
    ptr = NULL;
    int a;
    scanf("%d",&a);
    while(a!=-1)
    {
        NODE *n;
        n = (NODE *)malloc(sizeof(NODE));
        n->val = a;
        n->link = NULL;
        if(head==NULL)
        {
            head = n;
            ptr = n;
        }
        else
        {
            (ptr->link) = n;
            ptr = ptr->link;
        }
        total++;
        scanf("%d",&a);
    }
    return head;
}

NODE *solve(NODE *a)
{
    int value = total - a->val - 1;
    // printf("%d\n",value);
    a = a->link;
    // printList(a);
    NODE *head_new = (NODE *)malloc(sizeof(NODE));
    head_new = a;
    if(value>0)
    {
        while(value!=1)
        {
            a = a->link;
            value--;
        }
        if(a->link->link==NULL)
        {
            a->link = NULL;
        }
        else
        {
            a->link = a->link->link;
        }
    }
    else if(value==0)
    {
        a = a->link;
        head_new = a;
    }
    return head_new;
}

void printList(NODE *a)
{
    while(a!=NULL)
    {
        printf("%d",a->val);
        a = a->link;
    }
    printf("\n");
}