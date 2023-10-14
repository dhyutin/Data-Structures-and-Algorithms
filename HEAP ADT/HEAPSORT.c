#include <stdio.h>
#define SIZE 100
int count=0;
int heap[SIZE];

void swap(int* heap,int i)
{
  // for every index i , this function will consider 3 nodes, node i , its sibling and its parent and do the requires swaps//
   int minimum=-1;
   if(i==1) //when there is only one element in the heap//
   {
       return;
   }
    else if(i%2==1) //when the selected nod is a right child//
    {
        if(heap[i] < heap[i-1])
            minimum=i;
        else
            minimum = i-1;
    }
    else //when the selected node is a left child//
    {
        if(heap[i] < heap[i+1] || i==count)
            minimum=i;
        else
            minimum = i+1;
    }
    if(minimum!=-1)
    {
        if(heap[minimum] < heap[i/2])
        {
             int temp=heap[i/2];
             heap[i/2]=heap[minimum];
             heap[minimum]=temp;
        }
    }
    return;
}
void heapify(int* heap,int i) //function to maintain heap property//
{
    int k=count;
    if(count==1||count==0)
        return;

    while(k>i)
    {
        swap(heap,k);
        if(2*k<=count)
            heapify(heap,2*k);
        if(2*k+1<=count)
            heapify(heap,2*k+1);
        k=k-1;
    }
}

void insert(int value) //Function to insert an element in to the hep//
{
   int f;
   for(f=1;f<=count;f++)
   {
       if(heap[f]==value)
       {
           printf("Entered Element is already present in heap.\n");
           return;
       }
   }
    count=count+1;
    heap[count]=value;
    int i= count;
    while( heap[i/2] > heap[i] && i != 1 )
    {
        int temp= heap[i];
        heap[i]=heap[i/2];
        heap[i/2] = temp;
        i=i/2;
    }
    return;
}


int display(int* heap)
{
    int j;
    for(j=1;j<=count;j++)
    {
        printf("%d ",heap[j]);
    }
    return 0;
}

void delete_min(int* heap) //Function to delete the minimum node element in the heap//
{
    heap[1]= heap[count];
    count=count-1;
    heapify(heap,1);
}

void delete(int* heap,int i) //function to delete a specific element in the heap//
{
    heap[i]= heap[count];
    count=count-1;
}

void heap_sort(int* heap) //Function that will perform heap sort and delete all elements in the heap//
{
    while(count!=0)
    {
        printf("%d ",heap[1]);
        delete_min(heap);
    }
}


int main()
{
    int choice,value,del,j;
    printf("Heap Sort\n\n");
    heap[0]=-1;
    while(1)
    {
        printf("\n\nPress :\n 1.Insert\n 2.Heapify\n 3.Delete\n 4.Heap Sort and Exit\n 5.Display\n 6.Exit Program\n\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            {
                printf("Enter value to be inserted: ");
                scanf("%d",&value);
                insert(value);
                break;
            }
        case 2:
            {
                int i=count;
                heapify(heap,1);
                break;
            }
        case 3:
            {
                printf("Enter the element you want to delete: ");
                scanf("%d",&del);
                int i=0;
                for(j=1;j<=count;j++)
                {
                    if(heap[j]==del)
                    {
                        i=j;
                        delete(heap,j);
                    }
                }
                if(i==0)
                    printf("Entered element is not present in heap\n");
                break;
            }
        case 4:
            {
                printf("Heap Sort:\n");
                heap_sort(heap);
                break;
            }
        case 5:
            {
                printf("Displaying heap:\n");
                display(heap);
                break;
            }
        case 6:
            {
                printf("Exiting Program\n");
                return 0;
            }
        default:
            {
                printf("Invalid input by user. Try again\n");
                break;
            }
        }
    }
    return 0;
}
