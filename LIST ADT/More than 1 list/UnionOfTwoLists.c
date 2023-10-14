#include <stdio.h>
#include "List.h"

int main()
{
   int num,choice,r;
   printf("UNION OF TWO LISTS\n");
    struct list list1,list2,list3;//Defining 3 lists//
    //Assigning functions to each list//
    list1.n.insertbeg=insertbeg1;list1.n.insertend=insertend1;list1.n.search=search1;list1.n.display=display1;
    list2.n.insertbeg=insertbeg1;list2.n.insertend=insertend1;list2.n.search=search1;list2.n.display=display1;
    list3.n.insertbeg=insertbeg1;list3.n.insertend=insertend1;list3.n.search=search1;list3.n.display=display1;
    list1.start=NULL;
    list2.start=NULL; //Initiating heads of each list as NULL//
    list3.start=NULL;

    while(1)
    {
        printf("Enter your choice:\n");
        printf("1.Insert in List1 2.Insert in List2 3.Display all lists 4.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1: //Insert in list 1//
            {
                printf("Enter the value to be inserted in list 1:");
                scanf("%d",&num);
                head=list1.start;
                list1.n.insertend(num);
                list1.start=head;
                break;
            }
        case 2: //Insert in list 2//
            {
                printf("Enter the value to be inserted in list 2:");
                scanf("%d",&num);
                head=list2.start;
                list2.n.insertend(num);
                list2.start=head;
                break;
            }
        case 3: //display resultant list//
              {
               head=list3.start;
               ptr1=list1.start;
               ptr2=list2.start;
               if(ptr1==NULL&&ptr2==NULL) //When both list 1 and list 2 are empty//
               {
                   printf("No data has been inputted by the user\n");
               }
               else if(ptr1==NULL&&ptr2!=NULL) //When list 1 is empty anf list 2 is not//
               {
                   head=list3.start;
                   while(ptr2->next!=0)
                   {
                      r=list3.n.search(ptr2->data);
                      if(r==0)
                      {
                          head=list3.start;
                          list3.n.insertend(ptr2->data);
                          list3.start=head;
                      }
                      ptr2=ptr2->next;
                   }
                     if(r==0)
                     {
                         head=list3.start;
                         list3.n.insertend(ptr2->data);
                         list3.start=head;
                     }
               }
               else if(ptr2==NULL&&ptr1!=NULL) //When list 2 is empty and list 1 is not//
               {
                   while(ptr1->next!=0)
                   {
                      r=list3.n.search(ptr1->data);
                      if(r==0)
                       {
                          head=list3.start;
                          list3.n.insertend(ptr1->data);
                          list3.start=head;
                       }
                       ptr1=ptr1->next;
                   }
                   r=list3.n.search(ptr1->data);
                   if(r==0)
                   {
                          head=list3.start;
                          list3.n.insertend(ptr1->data);
                          list3.start=head;
                   }
               }
               else //When both list 1 and list 2 are not empty//
               {
                   while(ptr1->next!=0)
                    {
                       r=list3.n.search(ptr1->data);
                       if(r==0)
                        {
                           head=list3.start;
                           list3.n.insertend(ptr1->data);
                           list3.start=head;
                        }
                        ptr1=ptr1->next;
                    }
                    r=list3.n.search(ptr1->data);
                    if(r==0)
                    {
                           head=list3.start;
                           list3.n.insertend(ptr1->data);
                           list3.start=head;
                    }

                    head=list3.start;
                    while(ptr2->next!=0)
                    {
                           r=list3.n.search(ptr2->data);
                           if(r==0)
                           {
                               head=list3.start;
                               list3.n.insertend(ptr2->data);
                               list3.start=head;
                           }
                           ptr2=ptr2->next;
                    }
                    r=list3.n.search(ptr2->data);
                    if(r==0)
                     {
                           head=list3.start;
                           list3.n.insertend(ptr2->data);
                           list3.start=head;
                     }
               }
                printf("List 1 :\n");
                head=list1.start;
                list1.n.display(); //displays list 1//
                head=list2.start;
                printf("List 2 :\n");
                list2.n.display(); //displays list 2//
                head=list3.start;
                printf("List 3 : (Union of List1 and List2)\n");
                list3.n.display(); //displays resultant list//
                break;
              }
        case 4:
            {
                exit(0); //Exit//
            }
        default:
            {
                printf("Invalid input by user");
                break;
            }
        }
    }
}
