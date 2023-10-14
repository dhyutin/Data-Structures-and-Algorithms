#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* left_child;
    struct node* right_child;
    int rl; //To determine if it is right child or left child(1 for right ,0 for left)//
};
struct node* root=NULL,*temp,*child,*p,*q=NULL; //sTRUCTURE NODE POINTERS//
void create_bt(struct node* temp,int b) //Creating a binary tree//
{
    int a;
    child=(struct node*)(malloc(sizeof(struct node)));
    if(root==NULL)
       {
           printf("Enter Root Node Value(-1 for no value): ");
       }
    else
        {
            printf("Enter Data (-1 for no value): ");
        }

    scanf("%d",&a);
    if(a!=-1)
    {
        child->data=a;
        if(root==NULL)
        {
            root=child;
            b=0;
        }
        if(b==0)
        {
            temp=root;
            temp->rl=1;
            temp->left_child=NULL;
            temp->right_child=NULL;
        }
        else if(b==1)
        {
                temp->left_child=child;
                temp=temp->left_child;
                temp->rl=0;
                temp->left_child=NULL;
                temp->right_child=NULL;
        }
        else
        {
            temp->right_child=child;
            temp=temp->right_child;
            temp->rl=1;
            temp->left_child=NULL;
            temp->right_child=NULL;
        }
        printf("For left child of %d ," ,a);
        create_bt(temp,1);
        printf("For right child of %d ,",a);
        create_bt(temp,2);
    }
}

void preorder(struct node* temp) //Prints parent->left_child->right_child//
{
    if(temp!=NULL)
    {
        printf("%d ",temp->data);
        preorder(temp->left_child);
        preorder(temp->right_child);
    }
    return;
}

void postorder(struct node* temp) //Prints left_child->right_child->parent//
{
    if(temp!=NULL)
    {
        postorder(temp->left_child);
        postorder(temp->right_child);
        printf("%d ",temp->data);
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

void search(int c,struct node* temp) //Searches the element in the tree and pointer 'q' will point to the node whose height is to be determined//
{
    if(temp==NULL)
        return;
    if(temp->data==c)
    {
        q=temp;
        return;
    }
    search(c,temp->left_child);
    search(c,temp->right_child);
}
int flag=0;
int height_node_left(struct node* p,int c) //Determines height of node//
{
   if(p==NULL)
    return 0;
   if(p==q||flag==1)
   {
       flag=1;
       return 0;
   }
    int lDepth = height_node_left(p->left_child,c);
    int rDepth = height_node_left(p->right_child,c);
    if (lDepth > rDepth)
        return(lDepth+1);
    else
        return(rDepth+1);
}

int height_node_right(struct node* p,int c) //Determines height of node//
{
   if(p==NULL)
    return 0;
   if(p==q||flag==1)
   {
       flag=1;
       return 0;
   }
    int lDepth = height_node_right(p->right_child,c);
    int rDepth = height_node_right(p->left_child,c);
    if (lDepth > rDepth)
        return(lDepth+1);
    else
        return(rDepth+1);
}
int height(struct node* p) //determines height of tree//
{
   if (p==NULL)
       return 0;
    int lDepth = height(p->left_child);
    int rDepth = height(p->right_child);
    if (lDepth > rDepth)
        return(lDepth+1);
    else
        return(rDepth+1);
}
int main()
{
    int c,d;
    printf("Binary Tree\n");
    printf("Height of root is NOT 0\n");
    create_bt(root,0);
    while(1)
    {
        printf("\n\nPress 1 for Preorder,Postorder and Inorder\nPress 2 for Height of node\nPress 3 for Height of tree\nPress 4 to Exit Program\n");
        scanf("%d",&d);
        switch(d)
        {
            case 1:
            {
                temp=root;
                printf("Preorder : \n");
                preorder(temp); printf("\n");
                temp=root;
                printf("Postorder : \n");
                postorder(temp); printf("\n");
                temp=root;
                printf("Inorder : \n");
                inorder(temp); printf("\n");
                break;
            }
            case 2:
            {
                if(root==NULL)
                {
                    printf("Tree is empty\n");
                    break;
                }
                while(1)
                  {
                      printf("Enter the value of node whose height is to be found(-1 to stop):\n");
                      scanf("%d",&c);
                      if(c!=-1)
                       {
                         search(c,root);
                         if(q!=NULL&&q->rl==0)
                            {
                              printf("(Height of leaves is 0)\n");
                              printf("Height of the node with value %d is %d\n",c,height(root)-height_node_left(root,c)-1);
                            }
                         else if(q!=NULL&&q->rl==1)
                           {
                              printf("(Height of leaves is 0)\n");
                              printf("Height of the node with value %d is %d\n",c,height(root)-height_node_right(root,c)-1);
                           }
                         else
                           {
                              printf("(Height of leaves is 0)\n");
                              printf("Given value is not present in the tree\n");
                           }
                         q=NULL;
                         flag=0;
                       }
                       else
                          break;
                      break;
                   }
            }
            case 3:
            {
                if(root==NULL)
                {
                    printf("Tree is empty\n");
                    break;
                }
                printf(" Height of the tree is %d\n",height(root)-1);
                break;
            }
            case 4:
            {
                return 0;
            }
            default:
            {
                printf("\n\nInvalid input by user.Try again\n\n");
                break;
            }
        }
    }
    return 0;
}
