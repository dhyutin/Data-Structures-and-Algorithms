/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>


struct queue
{
    int front;
    int rear;
    int que[5];
}

void enqueue(int n,struct queue*q)
{
    if(q->front==0 && q->rear==4)
    {
        printf("Queue is full \n");
    }
    else
    {
        printf("Enter the item to be added in the queue \n")
        scanf("%d",n);
        q->que[q->rear+1] = n;
        q->rear = q->rear+1;
        
    }
    break;
}

void dequeue(int n,struct queue*q)
{
    if(q->front==-1)
    {
        printf("The queue is empty \n");
    }
    else
    {
        n=q->que[q->front];
        q->que[q->front]=q->que[q->front+1];
        printf("The deleted element is %d \n",n);
        
    }
    break;
}


void display(int n,struct queue*q)
{
    printf("The elements in the queue are: \n")
    for(q->front<=q->rear)
    {
        printf("%d \n"q->que[q->front]);
    }
}


int main()
{
    struct queue q1;
    q1.front=-1;
    q1.rear=-1;
    int choice,num;
    while(1)
 {
    printf("Enter 1 for enqueue \n Enter 2 for dequeue\n Enter 3 for displaying the elements of the queue \n");
    scanf("%d",choice);
    switch(choice)
     {
      case 1:
      printf("Enter the number you want to add in the queue \n");
      scanf("%d",&num);
      enqueue(num,&q1);
      break;
      
      case 2:
      dequeue(&q1);
      break;
      
      case 3:
      display(&q1);
      break;
      
      default:
      printf("Enter a valid element");
     }
     
 }   
   
  return 0;
}   
   