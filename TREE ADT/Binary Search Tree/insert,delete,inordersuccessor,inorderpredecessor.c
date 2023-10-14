#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* left_child;
    struct node* right_child;
    int position;
}*root=NULL,*temp,*child,*q=NULL,*r=NULL;


void insert(struct node* temp,int value) //Insert value in BST//
{
    child=(struct node*)(malloc(sizeof(struct node)));
    child->left_child=NULL; child->right_child=NULL; child->position =0;

    if(root==NULL)
    {
        child->data=value;
        root=child;
        temp=root;
    }
    else if((value) < (temp->data))
    {
        if(temp->left_child!=NULL)
            insert(temp->left_child,value);
        else
        {
            child->data=value;
            temp->left_child=child;
            temp=child;
        }
    }
    else if( (value) > (temp->data))
    {
        if(temp->right_child!=NULL)
            insert(temp->right_child,value);
        else
        {
            child->data=value;
            temp->right_child=child;
            temp=child;
        }
    }
    else
    {
        printf("Entered data is already present in BST. Try again\n");
    }
    return;
}

void inorder(struct node* temp) //prints left_child->parent->right_child//
{
    if(temp==NULL)
    {
        return;
    }
        inorder(temp->left_child);
        printf("%d ",temp->data);
        inorder(temp->right_child);
}

void search(int key,struct node* temp) //Searches the element in the tree and pointer 'q' will point to the node whose height is to be determined//
{
    if(temp==NULL)
        return;
    if(temp->data==key)
    {
        q=temp;
        return;
    }
    search(key,temp->left_child);
    search(key,temp->right_child);
}

int i=0;
void order(struct node* temp) //assigns position of each node while travelling in inorder//
{
    if(temp==NULL)
    {
        return;
    }
        order(temp->left_child);
        temp->position=i+1;
        i=i+1;
        order(temp->right_child);
}

void inorder_p(int predecessor_pos,struct node* temp) //Searches the element in the tree and pointer 'q' will point to the node whose height is to be determined//
{
    if(temp==NULL)
        return;
    if(temp->position==predecessor_pos)
    {
        r=temp;
        return;
    }
    inorder_p(predecessor_pos,temp->left_child);
    inorder_p(predecessor_pos,temp->right_child);
}

void inorder_s(int successor_pos,struct node* temp) //Searches the element in the tree and pointer 'q' will point to the node whose height is to be determined//
{
    if(temp==NULL)
        return;
    if(temp->position==successor_pos)
    {
        r=temp;
        return;
    }
    inorder_s(successor_pos,temp->left_child);
    inorder_s(successor_pos,temp->right_child);
}

int min_value(struct node*temp) //Finds the minimum value present in BST//
{
    if(temp->left_child!=NULL)
    {
        min_value(temp->left_child);
    }
    else return temp->data;
}

struct node* delete(struct node* temp,int del)
{
    if(temp==NULL)
    {
        return temp;
    }
    if(del < temp->data)
        temp->left_child=delete(temp->left_child,del);
    else if(del > temp->data)
        temp->right_child=delete(temp->right_child,del);
    else
    {
        if(temp->left_child==NULL)
        {
            struct node* ptr=temp->right_child;
            free(temp);
            return ptr;
        }
        else if(temp->right_child==NULL)
        {
            struct node* ptr=temp->left_child;
            free(temp);
            return ptr;
        }

        int tem=min_value(temp->right_child);
        temp->data=tem;
        temp->right_child=delete(temp->right_child,tem);
        return temp;
    }
}
int main()
{
    printf("Binary Search Tree \n");

    while(1)
    {
        int choice,value,del,key,predecessor_pos,successor_pos;
        printf("\n\nEnter:\n 1.Insert\n 2.Delete \n 3.Inorder Predecessor\n 4.Inorder successor\n 5.Inorder traversal\n 6.Exit Program\n\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            {
                printf("Enter Value: ");
                scanf("%d",&value);
                insert(root,value);
                break;
            }
        case 2:
            {
                printf("Enter the value to be deleted : ");
                scanf("%d",&del);
                temp=root;
                search(del,temp);
                if(q!=NULL)
                {
                     if(root==q)
                      {
                        if(root->left_child==NULL&&root->right_child!=NULL)
                           root=root->right_child;
                        else if(root->right_child==NULL&&root->left_child!=NULL)
                           root=root->left_child;
                        else
                           root=NULL;
                        free(q);
                      }
                    temp=root;
                    delete(temp,q->data);
                    printf("%d has been deleted from the BST\n",del);

                }
                else
                    printf("Entered value is not present in the BST\n");
                r=NULL; q=NULL; i=0;
                break;
            }
        case 3:
            {
                printf("Enter the value whose inorder predecessor is to be found: ");
                scanf("%d",&key);
                temp=root;
                search(key,temp);
                if(q!=NULL)
                {
                    temp=root;
                    order(temp);
                    predecessor_pos = q->position-1;
                    temp=root;
                    inorder_p(predecessor_pos,temp);
                    if(r==NULL)
                        printf("Inorder predecessor not present\n");
                    else
                        printf("Inorder predecessor of %d is %d\n",key,r->data);
                }
                else
                    printf("Given value not present in BST\n");
                r=NULL; q=NULL; i=0;
                break;
            }
        case 4:
            {
                printf("Enter the value whose inorder successor is to be found : ");
                scanf("%d",&key);
                temp=root;
                search(key,temp);
                if(q!=NULL)
                {
                    temp=root;
                    order(temp);
                    successor_pos=q->position+1;
                    temp=root;
                    inorder_s(successor_pos,temp);
                    if(r==NULL)
                        printf("Inorder successor not present\n");
                    else
                        printf("Inorder successor of %d is %d\n",key,r->data);
                }
                else
                    printf("Given value is not present in BST\n");
                r=NULL; q=NULL; i=0;
                break;
            }
        case 5:
            {
                printf("Inorder traversal: \n");
                temp=root;
                if(root!=NULL)
                    inorder(temp);
                else
                    printf("Empty BST\n");
                break;
            }
        case 6:
            {
                printf("Exiting Program");
                return 0;
            }
        default:
            {
                printf("Invalid input.Try again\n");
                break;
            }
        }
    }
    return 0;
}




