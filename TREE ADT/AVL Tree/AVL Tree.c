#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left_child;
    struct node* right_child;
    struct node* parent;
    int height; //Height of the node//
    int b_f;  //Integer to store the balance factor of that node//

}*root,*temp,*child,*q=NULL,*r=NULL;


int max(int a, int b) //Function to find the maximum value of 2 integers//
{
    return (a>b?a:b);
}

int height(struct node* temp) //Function to determine the height of a node//
{
    if(temp==NULL)
        return 0;
    return 1+max(height(temp->left_child),height(temp->right_child));
}

struct node* rotate_right_root(struct node* temp) //Function for rotating root node to the right//
{
    struct node* ptr1=temp->left_child;
    struct node* ptr2=ptr1->right_child;

    root=ptr1;
    ptr1->parent=NULL;
    ptr1->right_child=temp;
    temp->parent=ptr1;
    temp->left_child=ptr2;
    if(ptr2!=NULL)
        ptr2->parent=temp;
};

struct node* rotate_right(struct node* temp) //Function to rotate all nodes except root node to the right//
{
    if(temp==NULL || temp->left_child==NULL)
        return NULL;

    struct node* ptr1=temp->left_child;
    struct node* ptr2=ptr1-> right_child;
    struct node* ptr3= temp->parent;

    int rl=-1; //Determines if the node is a right child or left child//
    if(temp->parent->left_child==temp)
        rl=0; //for left child//
    else
        rl=1; //For right child//

    ptr1->right_child=temp;
    temp->parent=ptr1;
    temp->left_child=ptr2;
    if(ptr2!=NULL)
        ptr2->parent=temp;

    if(rl==0&ptr3!=NULL)
        ptr3->left_child=ptr1;
    else if(rl==1&&ptr3!=NULL)
        ptr3->right_child=ptr1;
    ptr1->parent=ptr3;
    if(temp==root)
        ptr1=root;
    rl=-1;

    return ptr1;
}

struct node* rotate_left_root(struct node*temp) //Function to rotate the root node to the left//
{
    struct node* ptr1=temp->right_child;
    struct node* ptr2=ptr1->left_child;

    root=ptr1;
    ptr1->parent=NULL;
    ptr1->left_child=temp;
    temp->parent=ptr1;
    temp->right_child=ptr2;
    if(ptr2!=NULL)
        ptr2->parent=temp;
};
struct node* rotate_left(struct node* temp) //Function to rotate any node except root to the left//
{
    if(temp==NULL || temp->right_child==NULL)
        return NULL;
    struct node* ptr1=temp->right_child;
    struct node* ptr2=ptr1->left_child;
    struct node* ptr3= temp->parent;

    int rl=-1; //To determine if it is a left child or right child//
    if(temp->parent->left_child==temp)
        rl=0; //left child//
    else
        rl=1; //right child//

    ptr1->left_child=temp;
    temp->parent=ptr1;
    temp->right_child=ptr2;
    if(ptr2!=NULL)
    ptr2->parent=temp;

    if(rl==0 && ptr3!=NULL)
        ptr3->left_child=ptr1;
    else if(rl==1 && ptr3!=NULL)
        ptr3->right_child=ptr1;
    else
    {
        if(temp==root)
            ptr1=root;
    }
    ptr1->parent=ptr3;
    rl=-1;
    return ptr1;
}

void AVLify_insert(struct node* temp,int value) //Function to convert any BT into AVL during insertion//
{
    if(temp==NULL)
        return;
    AVLify_insert(temp->left_child,value);
    temp->b_f=height(temp->left_child) - height(temp->right_child);
     if(temp->b_f!=1 || temp->b_f!=-1 || temp->b_f!=0)
        {
            if(temp->b_f > 1 && value < temp->left_child->data )
            {
               if(temp==root)
                   rotate_right_root(root);
                else
                   temp=rotate_right(temp);
                return;
            }

            else if(temp->b_f < -1 && value > temp->right_child->data)
              {
                  if(temp==root)
                      rotate_left_root(root);
                  else
                      temp=rotate_left(temp);
                  return;
              }

            else if(temp->b_f > 1 && value > temp->left_child->data)
            {
              temp->left_child=rotate_left(temp->left_child);
              if(temp==root)
                rotate_right_root(root);
              else
                temp=rotate_right(temp);
              return;
            }

           else if(temp->b_f < -1 && value < temp->right_child->data)
           {
              temp->right_child=rotate_right(temp->right_child);
              if(temp==root)
                rotate_left_root(root);
              else
                temp=rotate_left(temp);
              return;
           }

        }
    AVLify_insert(temp->right_child,value);
}
int getBalance(struct node *N) //gives the balance factor of nodes//
{
    if (N == NULL)
        return 0;
    return height(N->left_child) - height(N->right_child);
}

void AVLify_delete(struct node* temp) //Function to convert any BT to AVL tree//
{
    if(temp==NULL)
        return;
    temp->height = 1 + max(height(temp->left_child),height(temp->right_child));

    int balance = getBalance(temp);

    if (balance > 1 && getBalance(temp->left_child) >= 0)
        {
            if(temp==root)
                rotate_right_root(root);
            else
                rotate_right(temp);
           return;
        }
    if (balance > 1 && getBalance(temp->left_child) < 0)
    {
        temp->left_child =  rotate_left(temp->left_child);
        if(temp==root)
            rotate_right_root(root);
        else
            rotate_right(temp);
        return;
    }
    if (balance < -1 && getBalance(temp->right_child) <= 0)
        {
            if(temp==root)
                rotate_left_root(root);
            else
                rotate_left(temp);
            return;
        }
    if (balance < -1 && getBalance(temp->right_child) > 0)
    {
        temp->right_child = rotate_right(temp->right_child);
        if(temp==root)
            rotate_left_root(root);
        else
            rotate_left(temp);
        return;
    }

}

void insert(struct node* temp,int value) //Insert value in AVL Tree//
{
    child=(struct node*)(malloc(sizeof(struct node)));
    child->left_child=NULL; child->right_child=NULL;child->parent=NULL;

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
            child->parent=temp;
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
            child->parent=temp;
            temp=child;
        }
    }
    else
    {
        printf("Entered data is already present in AVL Tree. Try again\n");
    }
    return;
}

int min_value(struct node*temp) //Finds the minimum value present in BST//
{
    if(temp->left_child!=NULL)
    {
        min_value(temp->left_child);
    }
    else return temp->data;
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


struct node* delete_node(struct node* temp,int value)
{
    if(temp==NULL)
    {
        return temp;
    }
    if(value < temp->data)
        temp->left_child=delete_node(temp->left_child,value);
    else if(value > temp->data)
        temp->right_child=delete_node(temp->right_child,value);
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
        temp->right_child=delete_node(temp->right_child,tem);
        return temp;
    }
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

int main()
{
    printf("AVL TREE\n");
    root=NULL;
    while(1)
    {
        int choice,value;
        printf("\n\nEnter:\n 1.Insert\n 2.Delete\n 3.In-order Traversal\n 4.Pre-Order Traversal\n 5.Exit Program\n\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            {
                printf("Enter Value: ");
                scanf("%d",&value);
                insert(root,value);
                AVLify_insert(root,value);
                break;
            }
        case 2:
            {
                printf("Enter the value to be deleted : ");
                scanf("%d",&value);
                temp=root;
                search(value,temp);
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
                    delete_node(temp,q->data);
                    printf("%d has been deleted from the AVL Tree\n",value);

                }
                else
                    printf("Entered value is not present in the AVL\n");
                r=NULL; q=NULL;
                AVLify_delete(root);
                break;
            }
        case 3:
            {
                printf("Inorder traversal: \n");
                temp=root;
                if(root!=NULL)
                    inorder(temp);
                else
                    printf("Empty AVL Tree\n");
                break;
            }
        case 4:
            {
                printf("Preorder traversal: \n");
                temp=root;
                if(root!=NULL)
                    preorder(temp);
                else
                    printf("Empty AVL Tree\n");
                break;
            }
        case 5:
            {
                printf("Exiting Program\n");
                return 0;
            }
        default:
            {
                printf("Invalid input by user.Try again\n");
                break;
            }
        }
    }
    return 0;
}
