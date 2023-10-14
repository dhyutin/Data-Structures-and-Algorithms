#include <stdio.h>
int scenario1(int* arr,int d); //function scenario1
int scenario2(int* arr,int d); //function scenario2
int scenario3(int* arr,int d); //function scenario3
int scenario4(int* arr,int d); //function scenario4

int main ()
{
  int n, N, a, b, c, i, f, d, e, arr[50];  

  printf ("Enter the number of students in the class: \n");
  scanf ("%d",&n);
  while (n <= 5)		//finding number of students
    {
      printf ("Please enter a value ABOVE 5 ONLY.Try again\n");
      scanf ("%d", &n);
    }

  printf ("Enter the class capacity: \n");
  scanf ("%d", &N);
  while (N < n)			// finding class capacity
    {
      printf
	("Please make sure class capacity is more than or equal to number of students.Try again \n");
      scanf ("%d", &N);
    }
  printf ("Enter the rollnumbers in rank-wise order \n");
  for (a = 0; a < n; a++)	//Taking roll numbers input
  {
      scanf ("%d", &arr[a]);
      for (c = 0; c < a; c++)	//Incase a roll number is re-entered
	{
	  if (arr[c] == arr[a])
	    {
	      printf
		("this rollnumber is already entered.Enter a different one:\n");
	      scanf ("%d", &arr[a]);
	    }
	}
  }
 printf("Choose a scenario:\n scenario1- 3rd ranker joins class\n scenario2- 1st ranker leaves the class\n scenario3-mth ranker leaves the class\n scenario4-Kth ranker joins the class");
 scanf("%d",&i);
 
 if(i==1)
 scenario1(arr,n); //function call scenario1
 if(i==2)
 scenario2(arr,n); //function call scenario2
 if(i==3)
 scenario3(arr,n); //function call scenario3
 if(i==4)
 scenario4(arr,n); //function call scenario4
 
 }  
 
 int scenario1(int* arr,int n) //function definition scenario1
 {
     int d,e,f,a;
      printf ("Enter the rollnumber of the new 3rd ranker:");	//New student
      scanf ("%d",&d);
   for(e=0;e<n;e++)	//incase the new student inputs an existing roll number
    {
      if (d==arr[e])
	{
	  printf("This rollnumber is already alloted to another student.Try again \n");
	   scanf("%d", &d);
	}
    }
  for(f = n; f > 2; f--)
    {
      arr[f] = arr[f - 1];
    }
  arr[2] = d;
  printf ("The updated rank-list is as follows:\n");
  for (a = 0; a <= n; a++)
    {
      printf("%d \n", arr[a]);
    }
}

int scenario2(int* arr,int n) //function definition scenario2
{ int d,e,a;
     printf("After the first ranker is shifted to another class,The updated rank list is as follows:\n");
  for(d=0;d<n-1;d++)
     {
      arr[d]=arr[d+1];
     }
   for(e=0;e<n-1;e++)
     {
       printf("%d \n",arr[e]);
     }
}

int scenario3(int* arr,int n) //function definition scenario3
{ int m,g,h;
    printf("enter the rank of the student who shifted to another class:\n");
 scanf("%d",&m);
    if(m>n) 
     {
         printf("The rollnumber is always less than or equal to %d. Try again\n",n);
         scanf("%d",&m);
     }
for(g=m-1;g<n-1;g++)     //removing the mth rank from list
     {
         arr[g]=arr[g+1];
     }
printf("The updated rank list is :\n");
for(h=0;h<n-1;h++)
     {
         printf("%d \n",arr[h]);
     }
}
int scenario4(int* arr,int n) //function definition scenario4
{ int k,q,l,d,p;
    printf("Enter the rank and roll number of the newly shifted student respectively:\n");
  scanf("%d %d",&k,&l);
  for(q=0;q<n-1;q++)
    {
        if(arr[q]==l)
       { printf("Roll number already exists.Try again:\n");
        scanf("%d",&l);
       }
    }
      for(d=n;d>k-1;d--)
         { 
            arr[d]=arr[d-1];
          }
     arr[k-1]=l;
  printf(" the final updated rank list is as follows:\n");
  for(p=0;p<n+1;p++)
     {printf("%d\n",arr[p]);}
}
