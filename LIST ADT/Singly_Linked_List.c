#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node *head,*newnode,*temp,*prev,*ptr;
int i=0;

void insertB();
void insertM();
void insertE();
void deleteB();
void deleteM();
void deleteE();
void display();
void main()
{

    head=0;
    int choice=1,value;
    while(choice)
    {
         printf("Enter your choice:\n");
         printf("1.InsertB 2.InsertAtRandom 3.InsertE 4.DeleteB 5.DeleteAtRandom 6.DeleteE 7.Exit\n");
        scanf("%d",&choice);
           if(choice==1)
            {
               insertB();
               display();
            }
          else if(choice==2)
            {
               insertM();
               display();
            }
         else if(choice==3)
            {
               insertE();
               display();
            }
         else if(choice==4)
            {
              deleteB();
              display();
            }
         else if(choice==5)
         {
             deleteM();
             display();
         }
         else if(choice==6)
         {
             deleteE();
             display();
         }
         else if(choice==7)
         {
             printf("Exit\n");
             break;
         }
         else
         {
             printf("Wrong input\n");
             break;
         }
    }
}

void insertB()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value to be inserted at beginning:");
    scanf("%d",&newnode->data);
    newnode->next=0;
    if(head==0)
    {
        head=newnode;
        temp=newnode;
        i=1;
    }
    else
    {
       newnode->next=head;
       head=newnode;
       i=i+1;
    }
}

void insertM()
{
     if(head==0)
     {
         insertB();
     }
     else
     {
         int key,k,j,a,b=0;
         newnode=(struct node*)malloc(sizeof(struct node));
         printf("Enter the value to be inserted at the middle: ");
         scanf("%d",&newnode->data);
         printf("After which element do you want to insert? ");
         scanf("%d",&key);
         temp=head;
         for(j=0;j<i;j++)
          {
             if(temp->data!=key)
              {
                 temp=temp->next;
              }
             else
              {
                 k=k+1;
                 temp=temp->next;
              }
          }
          if(k==1)
          {
            temp=head;
            while(temp->data!=key)
            {
              temp=temp->next;
            }
            newnode->next=temp->next;
            temp->next=newnode;
             i++;
          }
          else if(k>1)
          {
              printf("The element you entered is repeated %d times\n",k);
              printf("For inserting after 1st Occurence of the value,press 1\n For inserting after 2nd occurence press 2 and so on..\n");
              scanf("%d",&a);
              temp=head;
              while(temp->data!=key||b!=a)
              {
                  if(temp->data==key)
                  {
                      b=b+1;
                      if(b==a)
                      {
                          break;
                      }
                  }
                  temp=temp->next;
              }
              newnode->next=temp->next;
              temp->next=newnode;
          }

     }
}

void insertE()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value to be inserted at the end: ");
    scanf("%d",&newnode->data);
    newnode->next=0;
    temp=head;
    while(temp->next!=0)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    i++;
}

void deleteB()
{
    if(head==0)
    {
        printf("No element to delete\n");
    }
    else
    {
        temp=head;
        head=head->next;
        free(temp);
        i=i-1;
    }
}

void deleteM()
{
    int key,j,k=0;
    printf("Enter the value of the element to be deleted: \n");
    scanf("%d",&key);
    temp=head;
    for(j=0;j<i;j++)
    {
        if(temp->data!=key)
        {
            temp=temp->next;
        }
        else
        {
            k=k+1;
            temp=temp->next;
        }
    }
    if(k==1)
    {
            temp=head;
            prev=temp;
            if(temp->data==key)
            {
              head=temp->next;
              i=i-1;
              return;
            }
            while(temp->data!=key)
             {
                prev=temp;
                temp=temp->next;
             }
            prev->next=temp->next;
            free(temp);
            i=i-1;
        }
    else if(k!=0&&k!=1)
    {
        int a,b=0;
        printf("There are %d number of elements with same value.\n",k);
        printf("Enter 1 for deleting the value's first appearance,2 for deleting the value's 2nd appearance and so on..\n");
        scanf("%d",&a);
        temp=head;
        while(temp->data!=key|| b!=a)
        {
          prev=temp;
          temp=temp->next;
          if(temp->data==key)
          {
            b++;
          }
          if(b==a)
          {
              break;
          }

        }
        prev->next=temp->next;
        free(temp);
        i=i-1;
    }
    else
    {
        printf("Element not found in the list\n");
    }

}

void deleteE()
{
    if(head==0)
    {
        printf("No element to delete\n");
    }
    else
    {
        temp=head;
        prev=temp;
        if(temp->next==0)
        {
            head=0;
            free(temp);
            return;
        }
        while(temp->next!=0)
        {
           prev=temp;
           temp=temp->next;
        }
        prev->next=0;
        free(temp);
        i=i-1;
    }
}

void display()
{
    temp=head;
    if(temp==0)
    {
        printf("No elements to display\n");
    }
    else
    {
        while(temp!=0)
        {
            printf(" %d ->",temp->data);
            temp=temp->next;
        }
        printf("NULL\n");
    }
}
