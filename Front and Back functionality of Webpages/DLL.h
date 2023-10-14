#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* next;
    struct node* prev;
    int (*insertbeg)(int num);
    void(*insertend)(int num);
    void(*modify)(int num,int pos);
    void(*display)();
};
struct node *head,*newnode,*temp,*ptr1,*ptr,*current;
int i=0;

int insertbeg1(int num)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=0;
    newnode->prev=0;
    if(head==0)
    {
        head=newnode;
        temp=newnode;
        i=1;
    }
    else
    {
       head->prev=newnode;
       newnode->next=head;
       head=newnode;
       head->prev=0;
       i=i+1;
    }
}

void insertend1(int num)
{
    if(i==0)
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
    i++;
}

void display1()
{
    temp=head;
    if(temp==0)
    {
        printf("There are no web pages to display. Try again!\n");
    }
    else
    {
        while(temp!=0)
        {
            printf(" %d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}

void modify1(int num,int pos)
{
    int j;
    if(i==0)
    {
        printf("List is empty.No node to modify\n");
    }
    else if(pos>=0&&pos<=i)
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
