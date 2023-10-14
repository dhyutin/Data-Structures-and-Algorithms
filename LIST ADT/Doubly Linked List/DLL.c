#include <stdio.h>
#include <stdlib.h>
struct node //node definition//
{
    int data;
    struct node* next; //node pointer pointing to next node//
    struct node* prev; //node pointer pointing to prev node//
};
struct node *head,*newnode,*temp,*ptr1,*ptr;
int i=0;

int insertbeg(int num) //Insert at beginning function definition//
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=0;
    newnode->prev=0;
    if(head==0) //when list is empty//
    {
        head=newnode;
        temp=newnode;
        i=1;
    }
    else //general case//
    {
       head->prev=newnode;
       newnode->next=head;
       head=newnode;
       head->prev=0;
       i=i+1;
    }
}

void insertmid(int num) //Insert at the middle function definition//
{
    int j,k;
    temp=head;
    if(i==1) //When there is only one element in the list//
    {
        printf("There is only one node in this list.Try this operation when the number of nodes is more than 1\n");
    }
    if(i%2==0) //when there are even number of nodes in the list//
    {
        for(j=1;j<(i/2);j++)
        {
            temp=temp->next;
        }
        i=i+1;
    }
    else //When there are odd number of nodes in the list//
    {
        for(j=1;j<(i/2)+1;j++)
        {
            temp=temp->next;
        }
        printf("\nThe list has odd number of elements and the middle term before insertion is %d\n",temp->data);
        printf("For inserting before %d press 1 and for inserting after %d press 2\n",temp->data,temp->data);
        scanf("%d",&k);
        if(k==1)
        {
            temp=temp->prev;
            i=i+1;
        }
        if(k==2)
        {
            i=i+1;
        }
        if(k!=1&&k!=2)
        {
            printf("Invalid input by user\n");
        }
    }
   newnode=(struct node*)malloc(sizeof(struct node));
   newnode->data=num;
   newnode->next=0;
   newnode->prev=0;
   newnode->next=temp->next;
  (temp->next)->prev=newnode;
   temp->next=newnode;
   newnode->prev=temp;

}

void insertend(int num) //Insert at end function definition//
{
    if(i==0) //When list is empty//
    {
        insertbeg(num);
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

void insertpos(int num,int pos) //Insert at a particular position function definition//
{
   newnode=(struct node*)malloc(sizeof(struct node));
   newnode->data=num;
   newnode->next=0;
   newnode->prev=0;
   int j;
   temp=head;
   for(j=1;j<pos-1;j++)
   {
       temp=temp->next;
   }
   newnode->next=temp->next;
   newnode->prev=temp;
   temp->next=newnode;
   (temp->next)->prev=newnode;
   i=i+1;
}

int isempty() //Funtion to check if the list is empty or not//
{
    if(i==0) // int i has been increasing by 1 for every insert and decreasing by 1 for every delete throughout the program//
    {
        printf("\nList is empty\n");
    }
    else
    {
        printf("\nList is not empty\n");
    }
}
void deletebeg() //Delete at beginning function definition//
{
    temp=head;
    if(head==0) //When List is empty//
    {
        printf("\nNo element to delete\n");
    }
    else if(i==1) //When there is one node in the list//
    {
        temp->next=0;
        temp->prev=0;
        head=0;
        free(temp);
        i=i-1;
    }
    else
    {
        head=head->next;
        head->prev=0;
        temp->next=0;
        free(temp);
        i=i-1;
    }
}

void deletemid() //Delete at middle function definition//
{
  int j,k;
  temp=head;
  if(i==0)
  {
      printf("\nNo element to delete\n");
  }
  if(i%2==0&&i!=0) //When there are even number of nodes//
  {
      printf("\nThis list has even number of nodes\n");
      while(1)
      {
          printf(" 2 middle terms are in positions %d and %d\n",i/2,i/2+1);
          printf("Of those 2 positions,Enter the position of the node you want to delete: ");
          scanf("%d",&k);
          if(k!=i/2&&k!=(i/2)+1)
           {
             printf("Invalid input.Try again\n");
           }
           else
           {
               break;
           }
      }
      for(j=1;j<k;j++) //
      {
          temp=temp->next;
      }
      i=i-1;
  }
  else
  {
      for(j=1;j<((i/2)+1);j++)
      {
          temp=temp->next;
      }
      i=i-1;
  }
  (temp->prev)->next=temp->next;
  (temp->next)->prev=temp->prev;
  free(temp);
}

void deleteend() //delete at end function definition//
{
    if(head==0) //when list is empty//
    {
        printf("\nNo element to delete\n");
    }
    else
    {
        temp=head;
        if(temp->next==0)
        {
            head=0;
            i=i-1;
            free(temp);
            return;
        }
        while(temp->next!=0)
        {
           temp=temp->next;
        }
        (temp->prev)->next=0;
        free(temp);
        i=i-1;
    }
}

void deletepos(int pos) //Delete at a particular position function definition//
{
    int j;
    temp=head;
    for(j=1;j<pos;j++)
    {
        temp=temp->next;
    }
   if(temp==head)
   {
       deletebeg(); //If it is the first element, delete at beginning//
   }
   else if(temp->next==0)
   {
       deleteend(); //If it is the last element ,delete at end//
   }
   else
   {
       (temp->prev)->next=temp->next;
       (temp->next)->prev=temp->prev;
       free(temp);
       i=i-1;
   }
}

void display() //display function definition//
{
    temp=head;
    if(temp==0)
    {
        printf("\nNo elements to display\n");
    }
    else
    {
        printf("\n\n");
        printf("NULL <->");
        while(temp!=0)
        {
            printf(" %d <->",temp->data);
            temp=temp->next;
        }
        printf("NULL\n\n");
    }
}

int listlength() //List length function definition//
{
    printf("\nLength of the list = %d\n",i);
}

int search(int val) //Search the value in the list function definition//
{
   int j,k=0;
   printf("\nGiven Value has been searched \n ");
   temp=head;
   for(j=1;j<=i;j++)
   {
       if(temp->data==val)
       {
           printf("\nThe values is present in position %d\n ",j);
           k=k+1;
       }
       temp=temp->next;
   }
   if(k==0)
   {
       printf("\nIt is not present in this list\n");
   }
}

void modify(int num,int pos) //Modify a node value function definition//
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
void main()
{

    head=0;
    int choice=1,value,num,m,pos,val;
    while(choice)
    {
         printf("\nEnter your choice:\n");
         printf("1.Insert 2.Delete 3.Check if list is empty 4.Display 5.Know List length 6.Search a value 7.Modify 8.Exit program\n");
         scanf("%d",&choice);
         if(choice==1)
         {
             printf("Where do you want to insert?\n");
             printf("1.Beginning 2.Middle 3.End 4.specific position 5.Exit Program\n");
             scanf("%d",&m);
             if(m==1)
             {
                 printf("Enter the value to be inserted at beginning: ");
                 scanf("%d",&num);
                 insertbeg(num); //insertbeg function call//
                 display(); //display function call//
             }
             else if(m==2)
             {
                 printf("Enter the value to be inserted at middle: ");
                 scanf("%d",&num);
                 insertmid(num); //insertmid function call//
                 display(); //display function call//
             }
             else if(m==3)
             {
                 printf("Enter the value to be inserted at end: ");
                 scanf("%d",&num);
                 insertend(num); //Insertend function call//
                 display(); //display function call//
             }
             else if(m==4)
             {
                 printf("Enter the value to be inserted : ");
                 scanf("%d",&num);
                 printf("Enter the position where you want to insert this element: ");
                 scanf("%d",&pos);
                 insertpos(num,pos); //Insertpos function call//
                 display(); //display function call//
             }
             else if(m==5)
             {
                 printf("Exiting Program\n");
                 return;
             }
             else
             {
                 printf("Invalid input by user\n");
             }
         }
         else if(choice==2)
         {
             printf("Where do you want to delete?\n");
             printf("1.Beginning 2.Middle 3.End 4.Specific Position 5.Exit program\n");
             scanf("%d",&m);
             if(m==1)
             {
                 deletebeg(); //deletebeg function call//
                 display(); //display function call//
             }
             else if(m==2)
             {
                 deletemid(); //deletemid function call//
                 display(); //display function call//
             }
             else if(m==3)
             {
                 deleteend(); //deleteend function call//
                 display(); //display function call//
             }
             else if(m==4)
             {
                 printf("Enter the position of the element you want to delete: ");
                 scanf("%d",&pos);
                 deletepos(pos); //deletepos function call//
                 display();  //display function call//
             }
             else if(m==5)
             {
                 printf("Exiting Program\n");
                 return;
             }
             else
             {
                 printf("Invalid input by user\n");
             }
         }
         else if(choice==3)
         {
             isempty(); //Isempty function call//
         }
         else if(choice==4)
         {
             display(); //display function call//
         }
         else if(choice==5)
         {
             listlength(); //listlength function call//
         }
         else if(choice==6)
         {
             printf("Enter the value to be searched: ");
             scanf("%d",&val);
             search(val); //searchval function call//
             display(); //display function call//
         }
         else if(choice==7)
         {
             printf("Enter the position of the node to be modified : ");
             scanf("%d",&pos);
             printf("Enter the value that should replace the value stored by this node : ");
             scanf("%d",&num);
             modify(num,pos); //Modify function call//
             printf("After modification:\n");
             display(); //display function call//
         }
         else if(choice==8)
         {
             printf("Exiting program\n"); //Exit program//
             break;
         }
         else
         {
             printf("Invalid input by user.Try again\n");
         }
    }
}
