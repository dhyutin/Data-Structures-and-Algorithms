#include <stdio.h>
#include "header.h"
int linear(int* arr,int n,int k);
int binary(int* arr,int n,int k);
int main()
{
    int n,k,i,j,arr[100];
    printf("Enter the number of elements in array");
    scanf("%d",&n);
    while(n<=5)
    {
        printf("Please enter a value above 5.Try again");
        scanf("%d",&n);
    }
    printf("enter the values of %d elements in the array without repeating any number",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the value of number you want to search for:");
    scanf("%d",&k);
    printf("Press 1 for doing linear search\n Press 2 for doing Binary Search");
    scanf("%d",&j);
    if(j==1)
    {
        linear(arr,n,k);
    }
    if(j==2)
    {
        insertion(arr,n);
        binary(arr,n,k);
    }
}

int linear(int* arr,int n,int k)
{
    int i,a,c,d=0;
    for(a=0;a<n;a++)
    {
        if(k==arr[a])
        {
            printf("given number %d is in position %d",k,c+1);
            break;
            d=d+1;
        }
    }


}

int binary(int* arr, int n,int k)
{
    int first,last,middle;
    first=0;
    last=n-1;
    middle=(first+last)/2;
while(first<=last)
  { if(arr[middle]<k)
    {
        first=middle+1;
    }
    else if(arr[middle]==k)
    {
        printf("Number found at position %d",middle+1);
        break;
    }
    else
    {
        last=middle-1;
        middle=(first+last)/2;
    }
  }
    if(first>last)
    {
        printf("Given number not found in array");
    }
}
