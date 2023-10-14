int front=-1;      //global variable//
int rear=-1;       //global variable//
struct q
{
    void (*enqueue)(int* time,int x,struct q*,int n); //Enqueue operation function prototype//
    int (*dequeue)(int* time,struct q*,int n); //Dequeue operation function prototype//
    int (*display)(int* time,struct q*,int n);       //Display operation function prototype//
    int (*isfilled)(int* time,struct q*,int n); //Operation to check if the queue is filled or not//
};
void enqueue1(int* time,int x,struct q*,int n); //structure variable//
int dequeue1(int* time,struct q*,int n); //structure variable//
int display1(int* time,struct q*,int n);        //structure variable//
int isfilled1(int* time,struct q*,int n);  //Structure variable//

void enqueue1(int* time,int x,struct q* stk,int n) //Enqueue operation function definition//
{
    if(front==-1&&rear==-1) //When queue is empty//
    {
        front=0;
        rear=0;
        time[rear]=x;
    }
    else if((rear+1)%n==front) //When queue is full//
    {
        printf("Given circular queue is full.\n");
    }
    else //Other wise//
    {
        rear=(rear+1)%n;
        time[rear]=x;
    }
}

int dequeue1(int* time,struct q* stk ,int n)  //Dequeue operation function definition//
{
    if(front==-1&&rear==-1) //When queue is empty//
    {
        printf("No data has been inputted by user.\n");
        return -1;
    }
    else if(front==rear) //When only one element is left in queue//
    {
        int e =front;
        front=-1;
        rear=-1;
        return time[e];
    }
    else //Other wise//
    {
        int e=front;
        front=(front+1)%n;
        return time[e];
    }
}

int display1(int* time,struct q* stk,int n)  //Display operation function definition//
{
    int i;
    if(front==-1&&rear==-1) //When queue is empty//
    {
        printf("Queue is empty\n");
    }
    else //Other wise//
    {
        for(i=front;i<=n;i++)
        {
            printf("%d ",time[i%n]);
            i=(i)%n;
            if(i==rear)
            {
                break;
            }
        }
    }
    printf("\n");
}

int isfilled1(int* time,struct q* stk,int n) //Isfilled operation function definition//
{
    if(front==-1&&rear==-1) //When queue is empty//
        return 0;
    else                //When queue is filled//
        return 1;
}
