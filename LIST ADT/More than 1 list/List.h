#include <stdio.h>
#include <stdlib.h>
struct node //node definition//
{
    int data;
    struct node* next; //node pointer pointing to next node//
    struct node* prev; //node pointer pointing to prev node//
    int (*insertbeg)(int);
    void (*insertend)(int);
    void (*display)();
    int (*search)(int);
    void (*modify)(int,int);
};
struct node *head=NULL,*newnode,*temp,*ptr1,*ptr,*ptr2,*temp1;

struct list //List Definition//
{
    struct node n;
    struct node* start; //Node pointer to point the starting node of every list//
};

int insertbeg1(int num) //Insert at beginning function definition//
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=0;
    newnode->prev=0;
    if(head==0) //when list is empty//
    {
        head=newnode;
        temp=newnode;
    }
    else //general case//
    {
       head->prev=newnode;
       newnode->next=head;
       head=newnode;
       head->prev=0;
    }
}

void insertend1(int num) //Insert at end function definition//
{
    if(head==0) //When list is empty//
    {
        insertbeg1(num);
        return;
    }
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=0;
    newnode->prev=0;
    temp=head;
    while(temp->next!=0)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
    newnode->next=0;
}


int search1(int num) //Search the value in the list function definition//
{
   temp=head;
   if(temp==NULL) //When list is empty//
   {
       return 0;
   }
   while(temp->next!=0) //When list is not empty//
   {
       if(temp->data==num) //If the element repeats atleast once//
       {
           return 1;
       }
       temp=temp->next;
   }
   if(temp->data==num)
   {
       return 1;
   }
   return 0;

}
void display1() //display function definition//
{
    temp=head;
    if(temp==0)
    {
        printf("\nNo elements to display\n");
    }
    else
    {
        printf("\n\n");
        while(temp!=0)
        {
            printf(" %d ",temp->data);
            if(temp->next==NULL)
            {
                break;
            }
            printf("-> ");
            temp=temp->next;
        }
        printf("\n\n");
    }
}

void modify1(int num,int pos)
{
    int j;
    if(head==NULL) //When list is empty//
    {
        printf("List is empty.No node to modify\n");
    }
    else if(pos>=0)
    {
        temp=head;
        for(j=1;j<pos;j++)
        {
          temp=temp->next;
        }
        temp->data=num;
    }
    else
    {
        printf("Invalid input by user\n");
    }
}
