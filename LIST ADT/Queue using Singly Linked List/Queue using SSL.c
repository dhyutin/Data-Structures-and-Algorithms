#include <stdio.h>
#include <stdlib.h>
#include "List.h"

int main()
{
    printf("IMPLEMENTING LINEAR QUEUE USING SINGLY LINKED LIST\n");
    int z;
    while(1)
    {
        printf("Enter:\n 1 for Enqueue operation\n 2 for Dequeue operation\n 3 for Displaying queue\n 4 to Exit program\n");
        scanf("%d",&z);
        if(z==1)
        {
          insertB(); //insert at the beginning//
        }
        else if(z==2)
        {
            deleteE(); //delete from the other side,i.e,from end//
        }
        else if(z==3)
        {
            display(); //display//
        }
        else if(z==4)
        {
            break;
        }
        else
        {
            printf("Invalid Output by user.Try again");
        }
    }
}
