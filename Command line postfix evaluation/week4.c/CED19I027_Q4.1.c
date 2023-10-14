#include <stdio.h>
#include "CED19I027_4_Stack.h" //user defined library//
#include <stdlib.h>
#include <math.h>
int main(int argc,char *argv[]) //command line argument//
{
    struct char_stack stack1;
    stack1.top=-1;           //initialising top as -1//
    stack1.push=push1;       //assigning push1 function as the PUSH function for stack1//
    stack1.pop=pop1;       //assigning pop1 function as the POP function for stack//
    stack1.isfilled=isfilled1; //function to check if the stack is filled or not//
    int i,ans=0,r;
    printf("The given postfix expression is:\n");
    for(i=1;i<argc;i++)
    {
        printf("%s ",argv[i]); //prints out the postfix expression//
    }
    printf("\n");
    for(i=1;i<argc;i++)
    {
        int b,c;
        if(argv[i][0]=='+') //when '+' operator comes , 2 terms are popped from stack and are evaluated//
        {
            b=stack1.pop(&stack1);
            c=stack1.pop(&stack1);
            ans=c+b;
            if(b==-1||c==-1)  //if the stack becomes empty before evaluation//
            {
                printf("Invalid postfix expression\n");
                return;
            }
            stack1.push(ans,&stack1); //pushing the answer back to stack//
        }
        else if(argv[i][0]== '-') //when '-' operator comes , 2 terms are popper from stack and are evaluated//
        {
            b=stack1.pop(&stack1);
            c=stack1.pop(&stack1);
            if(b==-1||c==-1)  //if the stack becomes empty before evaluation//
            {
                printf("Invalid postfix expression\n");
                return;
            }
            ans=c-b;
            stack1.push(ans,&stack1);//pushing the answer back to stack//
        }
        else if(argv[i][0]=='x') //when '*' operator comes , 2 numbers are popped out and are evaluated//
        {
            b=stack1.pop(&stack1);
            c=stack1.pop(&stack1);
            if(b==-1||c==-1) //if the stack becomes empty before evaluation//
            {
                printf("Invalid postfix expression\n");
                return;
            }
            ans=c*b;
            stack1.push(ans,&stack1); //pushing the answer back to stack//
        }
        else if(argv[i][0]=='/') //when'/' operator comes,2 numbers are popped out and are evaluated//
        {
            b=stack1.pop(&stack1);
            c=stack1.pop(&stack1);
            if(b==-1||c==-1) //if the stack becomes empty before evaluation//
            {
                printf("Invalid postfix expression\n");
                return;
            }
            ans=c/b;
            stack1.push(ans,&stack1);//pushing the answer back to stack//
        }
        else if(argv[i][0]=='^') //when '^' operator comes,2 numbers and popped out and are evaluated//
        {
            b=stack1.pop(&stack1);
            c=stack1.pop(&stack1);
            if(b==-1||c==-1) //if the stack becomes empty before evaluation//
            {
                printf("Invalid postfix expression\n");
                return;
            }
            ans=pow(c,b);
            stack1.push(ans,&stack1); //pushing the answer back to stack//
        }
        else
        {
            stack1.push(atoi(argv[i]),&stack1); //if its a number ,it is simply pushed into stack//
        }
        }
 r=stack1.isfilled(&stack1); //checking whether the stack is full or not//
 if(r) // when the stack is empty after evaluation//
 {
     printf("It is valid.\n");
    printf("After evaluation , answer is %d",ans);
 }
 else //when stack is not empty after evaluation//
 {
    printf("It is invalid\n");
    printf("Therefore,No evaluation");
 }
}
