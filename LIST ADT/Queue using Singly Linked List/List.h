struct node
{
    int data;
    struct node* next;
};
struct node *head,*newnode,*temp,*prev,*ptr;
int i=0;

void insertB()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value to be inserted at beginning:");
    scanf("%d",&newnode->data);
    newnode->next=0;
    if(head==0)
    {
        head=newnode;
        temp=newnode;
        i=1;
    }
    else
    {
       newnode->next=head;
       head=newnode;
       i=i+1;
    }
}
void insertE()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value to be inserted at the end: ");
    scanf("%d",&newnode->data);

    newnode->next=0;
    temp=head;
    while(temp->next!=0)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    i++;
}

void deleteB()
{
    if(head==0)
    {
        printf("No element to delete\n");
    }
    else
    {
        temp=head;
        head=head->next;
        free(temp);
        i=i-1;
    }
}

void deleteE()
{
    if(head==0)
    {
        printf("No element to delete\n");
    }
    else
    {
        temp=head;
        prev=temp;
        if(temp->next==0)
        {
            head=0;
            printf("Deleted element: %d\n",temp->data);
            free(temp);
            return;
        }
        while(temp->next!=0)
        {
           prev=temp;
           temp=temp->next;
        }
        printf("Deleted element: %d \n",temp->data);
        prev->next=0;
        free(temp);
        i=i-1;

    }
}

void display()
{
    temp=head;
    if(temp==0)
    {
        printf("No elements to display\n");
    }
    else
    {
        while(temp!=0)
        {
            printf(" %d ->",temp->data);
            temp=temp->next;
        }
        printf("END\n");
    }
}
