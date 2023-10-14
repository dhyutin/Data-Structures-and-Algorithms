struct char_stack //struct definition//
 {
     int top;
     char arr[10];
     void(*push)(char,struct char_stack*);//function to push into stack//
     int (*pop)(struct char_stack*);     //function to pop out from stack//
     int (*isfilled)(struct char_stack*);//function to check if stack is filled or empty//
 };
 void push1(char,struct char_stack *);
 int pop1(struct char_stack *);       //structure variables//
 int isfilled1(struct char_stack*);

 void push1(char c,struct char_stack * stk) //push1 function definition//
{
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

int pop1(struct char_stack * stk) //pop1 function definition//
{

    if(stk->top==-1) //when the stack is empty//
    {
        return -1;
    }
    else
    {
        stk->top=stk->top-1;
          return stk->arr[stk->top+1];
    }
}
int isfilled1(struct char_stack *stk)
{
  if (stk->top == 0)
    return 1;
  else
    return 0;
}
