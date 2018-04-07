#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    //define the details of the structure
    int data;
    struct node* next;
}NODE;
void printList(NODE *);//function to print the solution
NODE* input();//Function to take input
int solve(NODE*, NODE*);//function to solve the problem
NODE* createNode(int n);

int main()
{
    NODE* list1, *list2;
    list1=input();
    list2=input();
    int tmp = solve(list1, list2);
    if(tmp){
        printf("Complementary!");
    }
    else{
        printf("Not Complementary");
    }
    return 0;
}
/*Do not modify the main function
 *Define the structure NODE properly
 *Write the body of the above mentioned function*/
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

int solve(NODE* a, NODE* b)
{
    NODE *head = NULL;
    NODE *ptr = head;
    NODE *new_node = (NODE*)malloc(sizeof(NODE));
    new_node->data = a->data;
    new_node->next = NULL;
    head = new_node;
    ptr = new_node;
    int i=1;
    a = a->next;
    while(a!=NULL && b!=NULL)
    {
        new_node = (NODE*)malloc(sizeof(NODE));
        // printList(a);
        // printf(" is a\n");
        // printList(b);
        // printf(" is b\n");
        // printList(head);
        // printf(" is head\n");
        if(i%2==0)
        {
            new_node->data = a->data;
            new_node->next = NULL;
            ptr->next = new_node;
            ptr = ptr->next;
            a = a->next;
        }
        else
        {
            new_node->data = b->data;
            new_node->next = NULL;
            ptr->next = new_node;
            ptr = ptr->next;
            b = b->next;
        }
        i++;
    }
    while(a!=NULL)
    {
        new_node = (NODE*)malloc(sizeof(NODE));
        new_node->data = a->data;
        new_node->next = NULL;
        ptr->next = new_node;
        ptr = ptr->next;
        a = a->next;
        i++;
        // printList(head);
        // printf("\n");
    }
    while(b!=NULL)
    {
        new_node = (NODE*)malloc(sizeof(NODE));
        new_node->data = b->data;
        new_node->next = NULL;
        ptr->next = new_node;
        ptr = ptr->next;
        b = b->next;
        i++;
        // printList(head);
        // printf("\n");
    }
    ptr->next = NULL;
    ptr = head;
    NODE *ptr2 = head;
    for(int j=0;j<i/2;j++)
    {
        ptr = head;
        for(int k=1;k<i-j;k++)
            ptr = ptr->next;
        if(ptr->data!=ptr2->data)
            return 0;
        ptr2 = ptr2->next; 
    }
    return 1;
}