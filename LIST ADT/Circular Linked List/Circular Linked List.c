#include <stdlib.h>
#include <stdio.h>
struct node //defining a node//
{
    int data;
    struct node* next; //struct node pointer//
};
struct node *head,*newnode,*temp,*prev,*ptr;
int i=0; //global variable//

void insertB(); //function prototype//
void insertM(); //function prototype//
void insertE(); //function prototype//
void deleteB(); //function prototype//
void deleteM(); //function prototype//
void deleteE(); //function prototype//
void display(); //function prototype//
void count(); //function prototype//

void main()
{
    printf("Circular Linked List\n");
    head=0;
    int choice=1,value;
    while(choice)
    {
         printf("Enter your choice:\n");
         printf("1.InsertB 2.InsertAtRandom 3.InsertE 4.DeleteB 5.DeleteAtRandom 6.DeleteE 7.Count No of Nodes 8.Exit\n");
        scanf("%d",&choice);
           if(choice==1)
            {
               insertB(); //Insert at beginning function call//
               display(); //Display function call//
            }
          else if(choice==2)
            {
               insertM(); //Insert at random function call//
               display(); //Display function call//
            }
         else if(choice==3)
            {
               insertE(); //Insert at end function call//
               display(); //Display function call//
            }
         else if(choice==4)
            {
              deleteB(); //Delete at beginning function call//
              display(); //Display function call//
            }
         else if(choice==5)
         {
             deleteM(); //Delete at random function call//
             display(); //Display function call//
         }
         else if(choice==6)
         {
             deleteE(); //Delete at end function call//
             display(); //display function call//
         }
         else if(choice==7)
         {
             count(); //Function that diplays number of nodes//
         }
         else if(choice==8) //Exit program//
         {

           printf("Exit\n");
           break;
         }
         else //When user gives wrong input//
         {
             printf("Wrong input\n");
             break;
         }
    }
}

void insertB() //Insert at beginning function definition//
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value to be inserted at beginning:");
    scanf("%d",&newnode->data);
    newnode->next=0;
    if(head==0)//when linked list is empty//
    {
        head=newnode;
        newnode->next=head;
        i=i+1;
    }
    else
    {
       ptr=head;
       newnode->next=head;
       head=newnode;
       i=i+1;
    }
    temp=head;
   if(i!=1) //assigning last node's next adress as head//
   {
       while(temp->next!=0)
       {
           temp=temp->next;
           if(temp->next==ptr)
           {
               temp->next=head;
               break;
           }
       }
   }
}

void insertM() //insert at random function definition//
{
     if(head==0) //when list is empty//
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
         for(j=0;j<i;j++) //to count the number of times the inputted number has been repeated//
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
          if(k==1) //when the given number is present only once in the list//
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
          else if(k>1) //when the number occurs multiple times//
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

void insertE() //insert at end function definition//
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value to be inserted at the end: ");
    scanf("%d",&newnode->data);
    newnode->next=0;
    temp=head;
    while(temp!=0)
    {
        if(temp->next==head)
        {
            break;
        }
         temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=head;
    i++;
}

void deleteB() //delete at beginning function definition//
{
    if(head==0)//when list is empty//
    {
        printf("No element to delete\n");
    }
    else if(i==1)//when list has only one element//
    {
        free(head);
        head=0;
    }
    else
    {
       temp=head;
        while(temp->next!=0)
        {
            temp=temp->next;
            if(temp->next==head)
            {
                break;
            }
        }
        ptr=head;
        head=head->next;
        temp->next=head;
        free(ptr);
        i=i-1;
    }
}

void deleteM() //delete at random position function call//
{
    int key,j,k=0;
    printf("Enter the value of the element to be deleted: \n");
    scanf("%d",&key);
    temp=head;
    for(j=0;j<i;j++) //for counting the number of times the number occurs in list//
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
    if(k==1)//when the inputted number occurs only once//
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
        while(temp->data!=key||b!=a)
        {
          prev=temp;
          if(temp->data==key)
          {
            b++;
            if(b==a)
            {
              break;
            }
          }
          temp=temp->next;
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

void deleteE()//delete at end function definiton//
{
    if(head==0)
    {
        printf("No element to delete\n");
    }
    else
    {
        temp=head;
        prev=temp;
        if(temp->next==head)
        {
            head=0;
            free(temp);
            return;
        }
        while(temp->next!=0)
        {
           prev=temp;
           temp=temp->next;
           if(temp->next==head)
           {
               prev->next=head;
               free(temp);
               break;
           }
        }
        i=i-1;
    }
}

void display() //display function definition//
{
    temp=head;
    if(temp==0)
    {
        printf("No elements to display\n");
    }
    else if(i==1)//when only one element is there//
    {
        printf("%d -> %d \n",temp->data,temp->data);
    }
    else
    {
        while(temp!=0)
        {
            printf(" %d ->",temp->data);
            temp=temp->next;
            if(temp->next==head)
            {
                printf(" %d -> %d\n",temp->data,head->data);
                break;
            }

        }
    }
}
void count()//counting number of nodes//
{
  printf("This Circular queue had %d node(s)\n",i);
//i was alloted to count every addition and removal of a node throughout the c program//
}
