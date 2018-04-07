#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    //define the details of the structure
    int data;
    struct node *next;
}NODE;
void printList(NODE *);//function to print the solution
NODE* input();//Function to take input
NODE* solve(NODE*,int);//function to solve the problem
//define any function prototype you want to use

int main(){
    NODE* head;
    head=input();
    int k;
    scanf("%d", &k);
    printList(solve(head,k));
    return 0;
}
/*Do not modify the main function
 *Define the structure NODE properly
 *Write the body of the above mentioned function*/
 
//Write the body for all function definitions below
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
}

NODE *solve(NODE *head, int n)
{
    NODE *ptr = (NODE *)malloc(sizeof(NODE));
    ptr = head;
    int count = 0;
    while(ptr!=NULL)
    {
        count++;
        ptr = ptr->next;
    }
    if(n==0)
        return head;
    n = n%count;
    ptr = head;
    while(count-n>=2)
    {
        count--;
        // printf("%d %d\n",count+1-n,head->data);
        head = head->next;
    }
    // printf("%d\n",head->data);
    NODE *ptr2 = (NODE *)malloc(sizeof(NODE));
    ptr2 = head;
    head = head->next;
    // printf("%d\n",head->data);
    ptr2->next = NULL;
    // printf("%d\n",ptr2->data);
    ptr2 = head;
    while(ptr2->next!=NULL)
    {
        ptr2 = ptr2->next;
    }
    // printf("%d\n",ptr2->data);
    // printf("%d\n",ptr->data);
    ptr2->next = ptr;
    return head;
}