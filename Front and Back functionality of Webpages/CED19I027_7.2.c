#include <stdio.h>
#include "DLL.h"

int main()
{
    struct node wp; //Structure encapsulation//
    int pos;
    wp.insertbeg=insertbeg1; //Structure encapsulation//
    wp.insertend=insertend1;//Structure encapsulation//
    wp.display=display1;//Structure encapsulation//
    wp.modify=modify1;//Structure encapsulation//
    int choice=1,num;
    head=0;
    while(choice)
    {
        printf("Choose any one of the following option:\n");
        printf("1.Insert a page number\n2.Go Next\n3.Go Previous\n4.Display Current\n5.Display\n6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            {
                printf("Enter a page number: \n ");
                scanf("%d",&num);
                if(i==0)
                {
                    wp.insertbeg(num);
                    current=head;
                }
                else if(current->next==0)
                {
                    wp.insertend(num);
                   current=current->next;
                }
                else if(current->next!=0)
                    {
                       int a=1;
                       ptr=head;
                       while(ptr!=current)
                       {
                          ptr=ptr->next;
                          a=a+1;
                       }
                       pos=a+1;
                       wp.modify(num,pos);
                       current=current->next;
                       temp=current->next;
                       while(temp->next!=0)
                       {
                         temp=temp->next;
                         free(temp->prev);
                         i=i-1;
                       }
                       free(temp);
                       i=i-1;
                       current->next=0;
                   }
                printf("Current page is %d\n",current->data);
                printf("All pages are ");
                wp.display();
                break;
            }
        case 2:
            {

               if(i==0)
               {
                   printf("No web pages opened yet\n");
                   break;
               }
               if(current->next==0||head==0)
               {
                   printf("There are no web pages next. Try again!\n");
               }
               else
               {
                   current=current->next;
                   printf("Current page is %d\n",current->data);
                   printf("All pages are ");
                   wp.display();
               }
               break;

            }
        case 3:
            {
                if(current->prev==0||head==0)
                {
                    printf("There are no web pages previously. Try again!\n");
                }
                else
                {
                    current=current->prev;
                    printf("Current page is %d\n",current->data);
                    printf("All pages are ");
                    wp.display();
                }
                break;
            }
        case 4:
            {
               if(head==0)
               {
                   printf("No web page is on right now \n");
               }
               else
               {
                   printf("Current page is %d\n",current->data);
                   printf("All pages are ");
                   wp.display();
               }
               break;
            }
        case 5:
            {
                printf("All pages are ");
                wp.display();
                break;
            }
        case 6:
            {
                printf("Exiting Program\n");
                return 0;
            }
        default:
            {
                printf("Invalid input by user.Try again\n");
                break;
            }
        }
    }
}
