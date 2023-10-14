#include <stdio.h>
#include <stdlib.h>
#include "List.h"

int main()
{
  printf("IMPLEMANTING STACK USING SINGLY LINKED LIST\n");
  int z;
  while(1)
  {
      printf("Enter :\n 1 for Push operation\n 2 for Pop Operation\n 3 for Display operation\n 4 to Exit Program\n");
      scanf("%d",&z);
      if(z==1)
      {
         if(i==0)
         {
             insertB(); //insert at beginning only for the initial case//
         }
         else
         {
             insertE();//insert at the end//
         }
      }
      else if(z==2)
      {
          deleteE(); //delete from the end//
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
          printf("Invalid output by user.Try again\n");
      }
  }
}
