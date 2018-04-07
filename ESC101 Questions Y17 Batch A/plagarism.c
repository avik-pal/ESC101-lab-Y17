#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    //define the details of the structure
    int data;
    struct node *next;
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
NODE *solve(NODE *head)
{
    NODE *ptr = head;
    NODE *p = head;
    int flag = 0;
    while(ptr->next!=NULL)
    {
        // printList(head);
        // printf("\nptr at %d %d p at %d flag is %d\n",ptr->data,ptr->next->data,p->data,flag);
        if(ptr->data!=ptr->next->data)
        {
            if(flag==1)
            {
                flag = 0;
                if(p==head && p->data==ptr->data)
                    head = ptr->next;
                else
                    p->next = ptr->next;
            }
            else
                p = ptr;
            ptr = ptr->next;
        }
        else
        {
            flag = 1;
            ptr->next = ptr->next->next;
        }
    }
    if(flag==1)
    {
        if(p==head)
            head = NULL;
        else
            p->next = NULL;
    }
    return head;
}

NODE *input()
{
    NODE *head = (NODE *)malloc(sizeof(NODE));
    head = NULL;
    NODE *ptr = (NODE *)malloc(sizeof(NODE));
    ptr = NULL;
    int n;
    scanf("%d",&n);
    while(n>0)
    {
        n--;
        int val;
        scanf("%d",&val);
        NODE *new = (NODE *)malloc(sizeof(NODE));
        new->next = NULL;
        new->data = val;
        if(head==NULL)
        {
            head = new;
            ptr = new;
        }
        else
        {
            ptr->next = new;
            ptr = ptr->next;
        }
    }
    return head;
}

void printList(NODE *head)
{
    NODE *ptr = (NODE *)malloc(sizeof(NODE));
    ptr = head;
    while(ptr->next!=NULL)
    {
        printf("%d->",ptr->data);
        ptr = ptr->next; 
    }
    printf("%d",ptr->data);
}