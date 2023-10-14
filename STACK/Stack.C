
#include <stdio.h>
#define size 10
// structure of variable type stack for INTEGER TYPE is defined below//
struct int_stack
{
    int top;
    int arr[10];
    void(*push)(int,struct int_stack*); //for PUSH operation in stack//
    void(*display)(struct int_stack*);  //for DISPLAY operation in stack//
    int(*pop)(struct int_stack*); //for POP operation in stack
};
void push1(int,struct int_stack*); //structure variable//
void display1(struct int_stack*);  //structure variable/
int pop1(struct int_stack*);      //structure variable/

//structure of variable type stack for CHARACTER TYPE is defined below//
 struct char_stack
 {
     int top;
     char arr[10];
     void(*push)(char,struct char_stack*);
     void(*display)(struct char_stack*);
     int (*pop)(struct char_stack*);
 };
 void push2(char,struct char_stack *);
 void display2(struct char_stack *);
 int pop2(struct char_stack *);

int main()
{
    int x;
    printf("For initiating an Interger Stack,Press 1\nFor initiating a Character Stack,Press 2\n");
    scanf("%d",&x);

    if(x==1||x==2)
    {
    struct int_stack stack1;
    stack1.top=-1;           //initialising top as -1//
    stack1.push=push1;       //assigning push1 function as the PUSH function for stack1//
    stack1.pop=pop1;         //assigning pop1 function as the POP function for stack1//
    stack1.display=display1; //assigning display1 function as the DISPLAY function for stack1//

    struct char_stack stack2;
    stack2.top=-1;           //initialisinf top as -1//
    stack2.push=push2;       //assigning push2 function as the PUSH function for stack2//
    stack2.pop=pop2;         //assigning pop2 function as the POP function for stack2//
    stack2.display=display2; //assigning display2 function as the DISPLAY function for stack2//

    while(1)
    {
        int option , n;
        char c;
        printf("Choose one of the following options:\n");
        printf("press 1 to push\n press 2 to pop\n press 3 to display \n press 4 to exit\n");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
            {
                if(x==1)
                {
                    stack1.push(n,&stack1);  //calls PUSH function from structure//
                }
                else
                {
                    stack2.push(c,&stack2);
                }
                break;
            }
            case 2:
            {
                if(x==1)
                {
                    stack1.pop(&stack1);    //calls POP function from structure//
                }
                else
                {
                    stack2.pop(&stack2);
                }
                break;
            }
            case 3:
            {
                if(x==1)
                {
                    stack1.display(&stack1);  //calls DISPLAY function from structure//
                }
                else
                {
                    stack2.display(&stack2);
                }
                break;
            }
            case 4:
            return 0;  //exits program//
            default:
            {
                printf("Invalid option."); //when user input is not appropriate//

            }
        }
    }
    }
    else
    {
        printf("Invalid input by user");
    }
}

void push1(int n,struct int_stack * stk) //push1 funstion definition//
{
    printf("Enter the value of element to be pushed\n");
    scanf("%d",&n);
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

void display1(struct int_stack * stk) //display1 function definition//
{
    int i;
    if(stk->top==-1) //when the stack is empty//
    {
        printf("You have reached the stack underflow condition.\nThere are no elements to display\not");
    }
    else
    {
       printf("The stack is now as follows:\n");
        for(i=0;i<=stk->top;i++)
        {
            printf("%d\n",stk->arr[i]);
        }
    }
}

int pop1(struct int_stack * stk) //pop1 function definition//
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

void push2(char c,struct char_stack * stk) //push2 funstion definition//
{
    printf("Enter the character to be pushed\n");
    scanf(" %c",&c);
    if(stk->top==9) //when the stack if filled completely//
    {
        printf("You have reached stack overflow condition\n");
    }
    else
    {
        stk->top=stk->top+1;
        stk->arr[stk->top]=c;
    }
}

void display2(struct char_stack * stk) //display2 function definition//
{
    int i;
    if(stk->top==-1) //when the stack is empty//
    {
        printf("You have reached the stack underflow condition.\nThere are no elements to display\n");
    }
    else
    {
       printf("The stack is now as follows:\n");
        for(i=0;i<=stk->top;i++)
        {
            printf("%c\n",stk->arr[i]);
        }
    }
}

int pop2(struct char_stack * stk) //pop2 function definition//
{
    if(stk->top==-1) //when the stack is empty//
    {
        printf("You have reached the stack underflow condition\n");
    }
    else
    {
        stk->top=stk->top-1;
        printf("%c\n",stk->arr[stk->top+1]);
          return stk->arr[stk->top+1];
    }
}
