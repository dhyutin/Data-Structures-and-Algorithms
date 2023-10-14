#include <stdio.h>
int front=-1;      //global variable//
int rear=-1;       //global variable//
struct q
{
    void (*enqueue)(int* queue,int x,struct q*); //Enqueue operation function prototype//
    void (*dequeue)(int* queue,int x,struct q*); //Dequeue operation function prototype//
    int (*display)(int* queue,struct q*);       //Display operation function prototype//
};
void enqueue1(int* queue,int x,struct q*); //structure variable//
void dequeue1(int* queue,int x,struct q*); //structure variable//
int display1(int* queue,struct q*);        //structure variable//


int main()
{
    struct q q1;
    q1.enqueue=enqueue1; //assigning enqueue1 function as Enqueue operation for queue//
    q1.dequeue=dequeue1; //assigning dequeue1 function as Dequeue operation for queue//
    q1.display=display1; //assigning display1 function as Display operation for queue//


    int a=0,x,queue[5];
    printf("This is a integer queue of size 5\n");
    while(1)
    {
        printf("Press 1 for Enqueueing\nPress 2 for Dequeueing\nPress 3 to Display the queue\nPress 4 to STOP\n");
        scanf("%d",&a);
         if(a==1)
          {
            q1.enqueue(queue,x,&q1);  //Enqueue operation function call//
          }
         else if(a==2)
         {
            q1.dequeue(queue,x,&q1);  //Dequeue operation function call//
         }
         else if(a==3)
         {
            q1.display(queue,&q1);   //Display operation function call//
         }
         else if(a==4)
        {
          break;    //For user to exit program//
        }
        else     //When user gives an invalid input//
        {
            printf("Invalid input.Try again\n");
        }
    }

}

void enqueue1(int* queue,int x,struct q* stk) //Enqueue operation function definition//
{

      if(rear==4)
    {
        printf("You have reached overflow condition\n");
    }
    else if(front==-1&&rear==-1)
    {   printf("Enter the integer to be enqueued:\n");
        scanf("%d",&x);
        front=0;
        rear=0;
        queue[rear]=x;

    }
    else
    {
        printf("Enter the integer to be enqueued:\n");
        scanf("%d",&x);
        rear=rear+1;
        queue[rear]=x;
    }
}

void dequeue1(int* queue,int x,struct q* stk )  //Dequeue operation function definition//
{
    if(front==-1&&rear==-1)
    {
        printf("You have reached underflow condition\n");
    }
    else if(front==rear)
    {
        printf("Dequeued integer : %d\n",queue[front]);
        front=-1;
        rear=-1;
    }
    else
    {
        printf("Dequeued integer : %d\n",queue[front]);
        front=front+1;
    }
}

int display1(int* queue,struct q* stk)  //Display operation function definition//
{
    int i;
    if(front==-1&&rear==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Displaying queue:\n");
        for(i=front;i<=rear;i++)
        {
            printf("%d\n",queue[i]);
        }
    }
}
