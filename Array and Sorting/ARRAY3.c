#include <stdio.h>
int main()
{
    int arr[10], a, c=0, k;
    printf("Enter the value of intergers picked by the 10 people in ORDER:\n");
    for(a=0;a<10;a++)
      {
          scanf("%d",&arr[a]);
      }
     printf("Enter the interger to know its positions:\n");
         scanf("%d",&k);
     
     for(a=0;a<10;a++)
     {
        if(k==arr[a])
       { printf("This interger is picked by the person in the position %d\n",a+1);
           c=c+1;
       }
     }
     if(c==0)
     {printf("No person picked this integer");}
}  