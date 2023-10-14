
#include <stdio.h>
int bubble(int* arr,int n); //bubble sort fuction prototype
int selection(int* arr,int n);//selection sort function prototype
int insertion(int* arr,int n);//insertion sort function prototype
int main()
 {   int n,arr[50],a,i,j;
     printf("Enter the number of elements in array:\n"); //finding n
     scanf("%d",&n);
     while(n<=5)
      {
          printf("Please enter a value of n greater than 5"); //when user enter a value of n<=5
          scanf("%d",&n);
      }
     printf("enter the values of those %d elements",n);

     for(a=0;a<n;a++)
      {
         scanf("%d",&arr[a]);
      }
      //User instruction
     printf("for bubble sorting--->press 1\nfor selection sorting--->press 2\nfor insertion sorting--->press 3");
     scanf("%d",&a);
     if(a==1)
     {
         bubble(arr,n); //bubble sort function call
     }
     if(a==2)
     {
         selection(arr,n); //selection sort function call
     }
     if(a==3)
     {
         insertion(arr,n); //insertion sort function call
     }

 }

 int bubble(int* arr,int n) //bubble sort function definition
 {
     int i,j,k,l;
     for(i=0;i<n-1;i++)
      {
          for(j=0;j<n-i-1;j++)
           {
               if(arr[j] > arr[j+1])
                {
                    l=arr[j+1];
                    arr[j+1]=arr[j];
                    arr[j]=l;
                }
             for(k=0;k<n;k++)
                {
                    printf("%d ",arr[k]);
                }
          printf("\n");
           }

      }
 }

int selection(int* arr,int n) //selection sort function definition
 {
     int i,j,k;
     for(i=0;i<n-1;i++)
     {
         for(j=i;j<n-1;j++)
         {
             if(arr[i]>arr[j])
             {
                 k=arr[j];
                 arr[j]=arr[i];
                 arr[i]=k;
             }
            for(k=0;k<n;k++)
            {
               printf("%d ",arr[k]);
             }
             printf("\n");
         }

     }
}

int insertion(int* arr,int n) //insertion sort function definition
{
    int i,j,k,l;
    for (i=1;i<n;i++)
    {
        k=arr[i];
        j=i-1;
        while (j>=0&&arr[j]>k)
        {
            arr[j+1] = arr[j];
            j= j-1;
        }
        arr[j+1] = k;
        for(l=0;l<n;l++)
        {
            printf("%d ",arr[l]);
        }
        printf("\n");
    }
}
