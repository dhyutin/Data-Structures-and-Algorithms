#include <stdio.h>
#include "List.h"

int main()
{
    printf("MERGING OF TWO LISTS\n");
    int num,choice,r,s,t,u;
    struct list list1,list2,list3; //defining 3 lists//
    //assigning functions to each list via Structure encapsulation//
    list1.n.insertbeg=insertbeg1;list1.n.insertend=insertend1;list1.n.search=search1;list1.n.display=display1;
    list2.n.insertbeg=insertbeg1;list2.n.insertend=insertend1;list2.n.search=search1;list2.n.display=display1;
    list3.n.insertbeg=insertbeg1;list3.n.insertend=insertend1;list3.n.search=search1;list3.n.display=display1;
    list3.n.modify=modify1;
    list1.start=NULL;
    list2.start=NULL; //initiating head of each list as NULL//
    list3.start=NULL;

    while(1)
    {
        printf("Enter your choice:\n");
        printf("1.Insert in List1 2.Insert in List2 3.Display all lists 4.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1: //Inserts in list 1 //
            {
                printf("Enter the value to be inserted in list 1:");
                scanf("%d",&num);
                head=list1.start;
                list1.n.insertend(num);
                list1.start=head;
                head=list3.start;
                list3.n.insertend(num); //simultaneously insert in resultant list:list 3 also//
                list3.start=head;
                break;
            }
        case 2: //Insert in list 2//
            {
                printf("Enter the value to be inserted in list 2:");
                scanf("%d",&num);
                head=list2.start;
                list2.n.insertend(num);
                list2.start=head;
                head=list3.start;
                list3.n.insertend(num); //simultaneously insert in resultant list:list 3 also//
                list3.start=head;
                break;
            }
        case 3: //display resultant list//
            {
              ptr1=list1.start;
              ptr2=list2.start;
              if(ptr1==NULL&&ptr2==NULL)
              {
                  printf("No data inputted by user\n");
              }
              else
              {
                   head=list3.start;
               ptr1=list3.start;
               r=2;
               u=1;
               while(ptr1->next!=NULL) //Sorting of elements in final list in ascending order//
               {
                   ptr2=ptr1->next;
                   while(ptr2->next!=NULL)
                   {
                       if(ptr2->data <= ptr1->data)
                       {
                           t=ptr2->data;
                           s=ptr1->data;
                           head=list3.start;
                           list3.n.modify(s,r);
                           head=list3.start;
                           list3.n.modify(t,u);
                       }
                       r=r+1;
                       ptr2=ptr2->next;
                   }
                   if(ptr2->data <= ptr1->data)
                   {
                       t=ptr2->data;
                       s=ptr1->data;
                       head=list3.start;
                       list3.n.modify(s,r);
                       head=list3.start;
                       list3.n.modify(t,u);
                   }
                   ptr1=ptr1->next;
                   u=u+1;
                   r=u+1;
               }
              }
               printf("List 1 :\n");
               head=list1.start;
               list1.n.display(); //Display list 1//
               head=list2.start;
               printf("List 2 :\n");
               list2.n.display(); //Display list 2 //
               head=list3.start;
               printf("List 3 : (Merging of List1 and List2)\n");
               list3.n.display(); //Display resultant list//
               break;
            }
        case 4:
            {
                exit(0); //exit program//
            }
        default:
            {
                printf("Invalid input by user\n");
                break;
            }
        }
    }
}

