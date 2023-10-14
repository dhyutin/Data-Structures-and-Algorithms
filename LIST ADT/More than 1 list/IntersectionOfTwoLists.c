#include <stdio.h>
#include "List.h"

int main()
{
    printf("INTERSECTIONF OF TWO LISTS\n");
    int num,choice,g,j,m,p,r,s;
    struct list list1,list2,list3; //Defining 3 lists//
    //Assigning functions to each list//
    list1.n.insertbeg=insertbeg1;list1.n.insertend=insertend1;list1.n.search=search1;list1.n.display=display1;
    list2.n.insertbeg=insertbeg1;list2.n.insertend=insertend1;list2.n.search=search1;list2.n.display=display1;
    list3.n.insertbeg=insertbeg1;list3.n.insertend=insertend1;list3.n.search=search1;list3.n.display=display1;
    list1.start=NULL;
    list2.start=NULL; //initiating heads of each list as NULL//
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
        case 3: //Display resultant list//
            {
               head=list3.start;
               ptr1=list1.start;
               ptr2=list2.start;
               if(ptr1==NULL&&ptr2==NULL)
               {
                    printf("No data inputted by user\n");
               }
               else if(ptr1==NULL&&ptr2!=NULL)
               {
                   while(ptr2->next!=NULL)
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
               else if(ptr1!=NULL&&ptr2==NULL)
               {
                   while(ptr1->next!=NULL)
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
               else
               {
                   while(ptr1->next!=NULL)
                   {
                       r=list3.n.search(ptr1->data);
                       head=list2.start;
                       s=list2.n.search(ptr1->data);
                       head=list3.start;
                       if(r==0&&s==1)
                       {
                           head=list3.start;
                           list3.n.insertend(ptr1->data);
                           list3.start=head;
                       }
                       ptr1=ptr1->next;
                   }
                    r=list3.n.search(ptr1->data);
                    head=list2.start;
                    s=list2.n.search(ptr1->data);
                    head=list3.start;
                    if(r==0&&s==1)
                    {
                        head=list3.start;
                        list3.n.search(ptr1->data);
                        list3.start=head;
                    }
                    while(ptr2->next!=NULL)
                    {
                        r=list3.n.search(ptr2->data);
                        head=list1.start;
                        s=list1.n.search(ptr2->data);
                        head=list3.start;
                        if(r==0&&s==1)
                        {
                            head=list3.start;
                            list3.n.insertend(ptr2->data);
                            list3.start=head;
                        }
                        ptr2=ptr2->next;
                    }
                    r=list3.n.search(ptr2->data);
                    head=list1.start;
                    s=list1.n.search(ptr2->data);
                    head=list3.start;
                    if(r==0&&s==1)
                    {
                        head=list3.start;
                        list3.n.insertend(ptr2->data);
                        list3.start=head;
                    }
               }
                printf("List 1 :\n");
                head=list1.start;
                list1.n.display(); //display list 1//
                head=list2.start;
                printf("List 2 :\n");
                list2.n.display(); //display list 2//
                head=list3.start;
                printf("List 3 : (Intersection of List1 and List2)\n");
                list3.n.display(); //display resultant list//
               break;
            }
        case 4:
            {
                exit(0); //exit program//
            }
        default:
            {
                printf("Invalid input by user.Try again\n");
                break;
            }
        }
    }
}
