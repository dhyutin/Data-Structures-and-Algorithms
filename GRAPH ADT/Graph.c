#include <stdio.h>
#include <stdlib.h>
struct node                         //Nodes of the adjacency linked list//
{
    int vertex;      //Value stored in the node//
    struct node* next; //Address of next node//
};
struct list                        // Pointers to point the head nodes of each linked list//
{
    struct node *head; //Node pointer pointing to the fist element of linked list//
};
struct graph                      //An array of linked lists//
{
    int V; //Number of vertices in the graph//
    struct list* array; //Array storing addresses of each list//
    int* visited; //array to check if we visited a vertex or not//
};

struct node* create_node(int vertex) //function to create a node//
{
    struct node* newnode =(struct node*) malloc(sizeof(struct node)); //dynamic memory allocation for a node//
    newnode->vertex = vertex; //Assign vertex value to node//
    newnode->next = NULL; //Initially assign the node's next address as NULL//
    return newnode;
}

struct graph* create_graph(int V) //Function to create a graph//
{
    struct graph* graph =(struct graph*) malloc(sizeof(struct graph)); //Dynamic memory allocation for a graph//
    graph->V = V; //Assigning the number of vertices//
    graph->array =(struct list*)(malloc(V * sizeof(struct list))); //Creating an array of dynamic memory to store list address//
    graph->visited=( int*)(malloc(V*sizeof(int))); //Creating an array of visited array//
    int i;
    for (i = 0; i < V; ++i)
        {
            graph->array[i].head = NULL;
            graph->visited[i]=0; //Initiating all vertices as NOT VISITED//
        }
    return graph;
}

void join(struct graph* graph, int v1, int v2) //Function to join to vertices bidirectionally//
{
    struct node* newNode = create_node(v2);
    newNode->next = graph->array[v1].head;
    graph->array[v1].head = newNode;


    newNode = create_node(v1);
    newNode->next = graph->array[v2].head;
    graph->array[v2].head = newNode;
}

int present=0;
void search(struct graph* graph,int i,int a) //Searches if a vertex is already joined with another vertex//
{
        struct node* ptr = graph->array[i].head;
        while (ptr)
        {
            if(ptr->vertex==a)
                present=1;
            ptr = ptr->next;
        }
}

void display_graph(struct graph* graph) //Function to display the adjacency list of each vertex//
{
    int v;
    for (v = 0; v < graph->V; ++v)
    {
        struct node* ptr = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (ptr)
        {
            printf("-> %d", ptr->vertex);
            ptr = ptr->next;
        }
        printf("\n");
    }
}
                                             //STACK AND ITS OPERATIONS//
struct int_stack
{
    int top;
    int arr[100];
};

void push(int n,struct int_stack * stk) //push1 funstion definition//
{
    if(stk->top==9) //when the stack if filled completely//
    {
        printf("You have reached stack overflow condition\n");
    }
    else
    {
        stk->top=stk->top+1;
        stk->arr[stk->top]=n;
    }
}

int pop(struct int_stack * stk) //pop1 function definition//
{
    if(stk->top==-1) //when the stack is empty//
    {
        printf("You have reached the stack underflow condition\n");
    }
    else
    {
        stk->top=stk->top-1;
        printf("%d\n",stk->arr[stk->top+1]);
          return stk->arr[stk->top+1];
    }
}

void display(struct int_stack * stk) //display function definition//
{
    int i;
    if(stk->top==-1) //when the stack is empty//
    {
        printf("You have reached the stack underflow condition.\nThere are no elements to display\not");
    }
    else
    {
       printf("Displaying STACK:\n");
        for(i=0;i<=stk->top;i++)
        {
            printf("%d ",stk->arr[i]);
        }
    }
}

int is_filled_s(struct int_stack* stk)
{
    if(stk->top==-1)
        return 0;
    else
        return 1;
}
                                        //QUEUE AND ITS FUNCTIONS//
struct queue
{
   int queue[100];
   int front;
   int rear;
}*q=NULL;

void enqueue(int x,struct queue* q) //Enqueue operation function definition//
{

      if(q->rear==4)
    {
        printf("You have reached overflow condition\n");
    }
    else if(q->front==-1&&q->rear==-1)
    {
        q->front=0;
        q->rear=0;
        q->queue[q->rear]=x;
    }
    else
    {
        q->rear=q->rear+1;
        q->queue[q->rear]=x;
    }
}

int dequeue(struct queue* q )  //Dequeue operation function definition//
{
    if(q->front==q->rear)
    {
        int r= q->queue[q->front];
        q->front=-1;
        q->rear=-1;
        return r;
    }
    else
    {
       int r=q->queue[q->front];
        q->front=q->front+1;
        return r;
    }

}

int display_q(struct queue* q)  //Display operation function definition//
{
    int i;
    if(q->front==-1&&q->rear==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Displaying queue:\n");
        for(i=q->front;i<=q->rear;i++)
        {
            printf("%d ",q->queue[i]);
        }
    }
}

struct queue* createq(struct queue* q)
{
    q=(struct queue*)(malloc(sizeof(struct queue)));
    q->front=-1;
    q->rear=-1;
    return q;
};

int is_filled(struct queue* q)
{
    if (q->rear == -1)
    {
        return 0;
    }
    else
    {
        return 1;
    }

}
                                            //Depth First Search Function//
void DFS(struct graph* graph,int start,struct int_stack* stk)
{
    push(start,stk); //Push the vertex you have traversed//
    graph->visited[start]=1; //Mark it as visited//
    printf("Visited : %d\n",start);
    while(is_filled_s(stk)) //while the stack is not empty//
    {
       struct node* temp = (struct node*)(malloc(sizeof(struct node)));
       int tem = pop(stk);
       temp = graph->array[tem].head;
       while(temp!=NULL)
       {
          if(graph->visited[temp->vertex]==0)
           {
              DFS(graph,temp->vertex,stk); //Recursive calling till we traverse an element with no unvisited adjacent vertices//
           }
          temp=temp->next;
       }
    }
}
                             //Breadth First Search//
void BFS(struct graph* graph,int start)
{
    int filled;
    q = createq(q);
    enqueue(start,q); //Enqueue the vertex that you traversed//
    while(is_filled(q))
    {
        printf("\n");
        int new_ver=dequeue(q);
        graph->visited[new_ver]=1; //Mark the visited vertex as Visited//
        printf("Visited : %d\n",new_ver);
        display_q(q);         //Display Queue//
        struct node* temp= graph->array[new_ver].head;
        while(temp!=NULL)
        {
            if(graph->visited[temp->vertex]==0)
            {
                enqueue(temp->vertex,q);
                graph->visited[temp->vertex]=1;
            }
            temp=temp->next;
        }
    }
}

void clear_visits(struct graph* graph)//Function to reset all the vertices as unvisited for reusing DFS and BFS functions//
{
    int i;
    for (i = 0; i < graph->V; ++i)
            graph->visited[i]=0;
}

int main()
{
    struct int_stack* stk = (struct int_stack*)(malloc(sizeof(struct int_stack)));
    stk->top=-1;

    int vertices,choice,v1,v2,start;
    printf("Graph ADT\n");
    printf("Enter the number of vertices of graph: ");
    scanf("%d",&vertices);

    struct graph* graph=create_graph(vertices);

    while(1)
    {
        printf("\n\n====================================================================================\n");
        printf("Enter:\n 1.Add an edge\n 2.Display all connections\n 3.DFS\n 4.BFS\n 5.Exit Graph\n");
        printf("====================================================================================\n\n");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            {
                printf("Enter the vertices you want to join: \n");
                printf("Vertex 1: ");
                scanf("%d",&v1);
                while(v1<0||v1>=vertices)
                {
                    printf("Enter a valid vertex number.\n");
                    printf("Vertex 1: ");
                    scanf("%d",&v1);
                }
                printf("Vertex 2: ");
                scanf("%d",&v2);
                while(v2<0||v2>=vertices)
                {
                    printf("Enter a valid vertex number.\n");
                    printf("Vertex 2: ");
                    scanf("%d",&v2);
                }
                search(graph,v1,v2);
                if(present==1)
                {
                    printf("\n%d and %d already form an edge\n",v1,v2);
                    present=0;
                }
                else
                {
                    join(graph,v1,v2);
                }
                break;
            }
        case 2:
            {
                display_graph(graph);
                break;
            }
        case 3:
            {
                printf("From which vertex do you want to start Depth First Search? : ");
                scanf("%d",&start);
                while(start<0||start>=vertices)
                {
                    printf("Enter a valid value of vertex\n");
                    printf("From which vertex do you want to start Depth First Search? : ");
                    scanf("%d",&start);
                }
                DFS(graph,start,stk);
                clear_visits(graph);
                break;
            }
        case 4:
            {
                printf("From which vertex do you want to start Breadth First Search? : ");
                scanf("%d",&start);
                while(start<0||start>vertices)
                {
                    printf("Enter a valid value of vertex\n");
                    printf("From which vertex do you want to start Breadth First Search? : ");
                    scanf("%d",&start);
                }
                BFS(graph,start);
                clear_visits(graph);

                break;
            }
        case 5:
            {
                printf("Exiting Program");
                return 0;
            }
        default:
            {
                printf("Invalid input by user.Try again\n");
                break;
            }
        }
    }
    return 0;
}
