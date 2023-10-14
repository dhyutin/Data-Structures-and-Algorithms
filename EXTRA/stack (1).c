#include<stdio.h>
#define SIZE 10
//integer stack structure
struct Stack
{
    int top, Array[SIZE];
    void (*Push)(int ,struct Stack* );
    void (*Display)(struct Stack*  );
    void (*Pop)(struct Stack*  );
} ;
//character stack structure
struct StackC
{
    int top;
    char Array[SIZE];
    void (*pushc)(char,struct StackC* );
    int  (*popc)(struct StackC* );
    void (*displayc)(struct StackC* );
} ;
//pushes integer into stack
void Push(int num,struct Stack* stk1)
{
    if (stk1->top == SIZE-1)
        printf("Stack overflow");
    else
      {
        stk1->top = stk1->top+1;
        stk1->Array[stk1->top]=num;
      }
}
//pushes character into stack
void pushc(char ch ,struct StackC* stk1)
{
    if (stk1->top == SIZE-1)
        printf("Stack overflow");
    else
      {
        stk1->top = stk1->top+1;
        stk1->Array[stk1->top]=ch;
      }
}
//pops an integer from stack(returns the integer value )
int Pop(struct Stack* stk1 )
{
    int k;
    if (stk1->top == -1)
        printf("Stack empty\n");
    else
        k=stk1->Array[stk1->top];
        stk1->top = stk1->top-1;
        return k;
}
//pops an character from stack(returns the character value )
char popc(struct StackC* stk1 )
{
    char k ;
    if (stk1->top == -1)
        printf("Stack empty");
    else
        k=stk1->Array[stk1->top];
        stk1->top = stk1->top-1;
    return k;
}
//displays integer stack
void Display(struct Stack* stk1 )
{
    int i;
    if (stk1->top == -1)
        printf("Stack empty\n");
    else
    {
        printf("Stack: \n");
      for(i=stk1->top;i>-1;i--)
        printf("%d\n",stk1->Array[i]);
    }
}
//displays character stack
void displayc(struct StackC* stk1 )
{
    int i;
    if (stk1->top == -1)
        printf("Stack empty\n");
    else
    {
        printf("stack: \n");
      for(i=stk1->top;i>-1;i--)
        printf(" %c\n",stk1->Array[i]);
    }
}
int main()
{
   int num,choice,t=1,popped;
   char ch;

    struct Stack stk2;
    stk2.Push=Push;
    stk2.Display=Display;
    stk2.top=-1;
    struct StackC stkc;
    stkc.pushc=pushc;
    stkc.popc=popc;
    stkc.displayc=displayc;
    stkc.top=-1;
    while(t)
    {

                printf("*****************************\n");
                printf("Case 1 : Push Integer\n");
                printf("Case 2 : Push Character\n");
                printf("Case 3 : Pop Integer\n");
                printf("Case 4 : Pop character \n");
                printf("Case 5 : Display Integer stack \n");
                printf("Case 6 : Display character stack \n");
                printf("Case 7 : Exit\n");
                printf("*****************************\n");

                printf("Enter case number: ");
                scanf("%d",&choice);
                    switch(choice)
                        {
                        case 1:
                            printf("Enter number to be pushed: ");
                            scanf("%d",&num);
                            stk2.Push(num,&stk2);
                            break;
                        case 2:
                             printf("Enter character to be pushed: ");
                             scanf(" %c",&ch);
                             stkc.pushc(ch,&stkc);
                             break;
                        case 3:
                            popped=Pop(&stk2);
                            printf("%d is the popped value\n",popped);
                            break;
                        case 4:
                            ch=stkc.popc(&stkc);
                            printf("%c \n",ch);
                            break;
                        case 5:
                            stk2.Display(&stk2);break;
                        case 6:
                            stkc.displayc(&stkc);break;
                        case 7:
                        t=0;break;
                        }
    }
}
