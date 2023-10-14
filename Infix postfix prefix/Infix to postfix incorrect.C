#include <stdio.h>
#include <string.h>

struct char_stack
 {
     int top;
     char arr[50];
     void(*push)(char,struct char_stack*);
     int (*pop)(struct char_stack*);
 };
 void push1(char,struct char_stack *);
 void display1(struct char_stack *);
 int pop1(struct char_stack *);

 void push1(char c,struct char_stack * stk) //push1 function definition//
{
    if(stk->top==49) //when the stack if filled completely//
    {
        printf("You have reached stack overflow condition\n");
    }
    else
    {
        stk->top=stk->top+1;
        stk->arr[stk->top]=c;
    }
}

int pop1(struct char_stack * stk) //pop1 function definition//
{
    if(stk->top==-1) //when the stack is empty//
    {
        printf(" Invalid Postfix expression\n");
    }
    else
    {
        stk->top=stk->top-1;
          return stk->arr[stk->top+1];
    }
}

 int imp(char ch)
{
if(ch=='^') return 5;        //presidence order
else if(ch=='*') return 4;
else if(ch=='/') return 3;
else if(ch=='+') return 2;
else if(ch=='-') return 1;
else return 0;
}

int main()
{
    struct char_stack stack1;
    stack1.push=push1;
    stack1.pop=pop1;
    stack1.top=-1;
    int i,j,k,x,y;
    char c;
    char inf[100],psf[100];
    printf("Enter the infix expression without spaces: ");
    scanf("%s",inf);
    int len= strlen(inf);
    j=0;

    for(i=0;i<len;i++)
    {
        if(inf[i]>='a'&&inf[i]<='z')
        {
            psf[j]=inf[i];
            j++;
        }
        else if(inf[i]=='(')
        {
            stack1.push(inf[i],&stack1);
        }
        else if(inf[i]==')')
        {
            while(stack1.arr[stack1.top]!='(')
            {
                c=stack1.pop(&stack1);
                psf[j]=stack1.arr[c];
                j++;
            }
            stack1.pop(&stack1);
        }
        else
        {
            x=imp(inf[i]);
            y=imp(stack1.arr[stack1.top]);

            if(x>y)
            {
                stack1.push(inf[i],&stack1);
            }
            else
            {
                while(stack1.arr[stack1.top]!='(')
                {
                    c=stack1.pop(&stack1);
                    psf[j]=stack1.arr[c];
                    j++;
                    y=imp(stack1.arr[stack1.top]);
                }
                stack1.push(inf[i],&stack1);
            }
            if(i>0)
            {   printf("pass - %d : \n",i);
                for(k=0;k<j;k++)
                {
                    printf("%c\n",psf[k]);
                }
                printf("\n");
            }
        }
    }
    printf("Now the resultant postfix expression is:\n ");
    while(stack1.top+1)
    {
        psf[j++]=stack1.pop(&stack1);
    }
    for(i=0;i<len;i++)
        {
            printf("%c",psf[i]);
        }
}

