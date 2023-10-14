#include <stdio.h>
#include "Cqueue.h"
int main()
{
    printf("Round Robin Scheduling program\n");
    struct q q1;
    q1.enqueue=enqueue1; //assigning enqueue1 function as Enqueue operation for queue//
    q1.dequeue=dequeue1; //assigning dequeue1 function as Dequeue operation for queue//
    q1.display=display1; //assigning display1 function as Display operation for queue//
    q1.isfilled=isfilled1; //assigning a function to check if the queue is filler ot not//

    int n,time[10],i,x;
    printf("Enter the Number of Processes: ");
    scanf("%d",&n);
    printf("Enter the time required for each process :\n");
    for(i=0;i<n;i++) //Taking inputs from user//
    {
        printf("For process %d :",i+1);
        scanf("%d",&time[i]);
        if(time[i]<0) //when user gives invalid time//
        {
            printf("Time taken cannot be negative try again\n");
            printf("Time taken for process %d : ",i+1);
            scanf("%d",&time[i]);
        }
        q1.enqueue(time,time[i],&q1,n);
    }
    printf("Time required for each process:\n");
    for(i=0;i<n;i++)
    {
        printf("P%d : %d\n",i+1,time[i]);
    }
    int cst;
    printf("Enter CPU Share Time: ");
    scanf("%d",&cst);
    while(cst<0) //when user gives invalid input of time//
    {
        printf("CPU share time cannot be negative.Try again\n");
        printf("Enter CPU Share Time: ");
        scanf("%d",&cst);
    }
       int a,b=1,d;
       d=q1.isfilled(time,&q1,n);
       while(d) //while the queue is filled//
       {
            printf("\n\n");
            printf("Switch %d\n",b);
            a=q1.dequeue(time,&q1,n);
            printf("%d Dequeued\n",a);
            a=a-cst;
           if(a>0) //when time left for the process>CPU Sharing time//
           {
              q1.enqueue(time,a,&q1,n);
              printf("%d units executed\n",cst);
              printf("%d Enqueued\n",a);
           }
           else
           {
              if(a<0) //When time left for the process<CPU sharing time//
              {
                  printf("%d units Executed\n",a+cst);
                  printf("That process is complete\n");
              }
              else  //When time left for the process= CPU Sharing time//
              {printf("%d units Executed\n",cst);}
              printf("0 is not enqueued and that process is complete\n");
           }
         printf("Remaining ");
         q1.display(time,&q1,n); //Displays the current queue//
         d=q1.isfilled(time,&q1,n);
         b=b+1;
       }
       printf("All Processes completed\n");
       printf("CPU returning to Idle state.Stopping program.\n");
}
