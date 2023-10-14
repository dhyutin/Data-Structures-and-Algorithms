#include <stdio.h>
#include "List.h"
void main()
{
    int choice,num,r;
    struct list list1,list2; //Defining 2 lists//
    printf("TO REMOVE REPEATING ELEMENTS FROM THE LIST\n");
    //Assigning functions to each list//
    list1.n.insertbeg=insertbeg1;list1.n.insertend=insertend1;list1.n.search=search1;list1.n.display=display1;
    list2.n.insertbeg=insertbeg1;list2.n.insertend=insertend1;list2.n.search=search1;list2.n.display=display1;
    list1.start=NULL; //initiating heads as NULL //
    list2.start=NULL; //initiating heads as NULL//
    while(1)
    {
        printf("Enter choice:\n");
        printf("1.Insert\n2.Display\n3.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: //INSERT //
            {
               printf("Enter the value to be inserted: ");
               scanf("%d",&num);
                head=list1.start;  //Initiating the head as list1's head//
                list1.n.insertend(num); //Inserting the entered number in list 1//
                list1.start=head; //updating the head of list 1//
               break;
            }
            case 2: //DISPLAY//
            {
                ptr1=list1.start;
                head=list2.start;
                if(ptr1==NULL)
                {
                    printf("No data has been inputted by user\n");
                }
                else
                {
                    while(ptr1->next!=NULL)
                    {
                    r=list2.n.search(ptr1->data); //searching if the element already exists in final list//
                    if(r==0) //if it is not in final list, we insert it in the final list//
                    {
                        head=list2.start;
                        list2.n.insertend(ptr1->data);
                        list2.start=head;
                    }
                    ptr1=ptr1->next;
                    }
                    r=list2.n.search(ptr1->data);
                    if(r==0)
                    {
                    head=list2.start;
                    list2.n.insertend(ptr1->data);
                    list2.start=head;
                    }
                }
                    printf("Given list:\n");
                    head=list1.start;
                    list1.n.display(); //display user's inputted list//
                    printf("List after removing repeating elements:\n");
                    head=list2.start;
                    list2.n.display(); //display resultant list//
                    break;
            }
            case 3:
            {
                exit(0);
            }
            default:
            {
                break;
            }
        }
    }
}
