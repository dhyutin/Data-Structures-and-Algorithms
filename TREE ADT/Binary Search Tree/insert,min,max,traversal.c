#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* left_child;
    struct node* right_child;
};
struct node* root=NULL,*temp,*child,*p,*q=NULL; //STRUCTURE NODE POINTERS//

void insert(struct node* temp,int value) //Insert value in BST//
{
    child=(struct node*)(malloc(sizeof(struct node)));
    child->left_child=NULL; child->right_child=NULL;

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
    else
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
    return;
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

int min_value(struct node*temp) //Finds the minimum value present in BST//
{
    if(temp->left_child!=NULL)
    {
        min_value(temp->left_child);
    }
    else return temp->data;
}

int max_value(struct node*temp)
{
    if(temp->right_child!=NULL)
    {
        max_value(temp->right_child);
    }
    else return temp->data;
}

int main()
{
    int value,choice,key;
    printf("Binary Search Tree\n");
    while(1)
    {
        printf("\n1.Insert value\n2. Minimum Term\n3.Maximum Term\n4.Search a value\n5.Preorder,Postorder and Inorder Traversal\n6.Exit Program\n");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            {
                printf("Enter Value: \n");
                scanf("%d",&value);
                insert(root,value);
                break;
            }
        case 2:
            {
                temp=root;
                if(root!=NULL)
                    printf("Minimum Value in this BST is %d\n",min_value(temp));
                else
                    printf("Given BST is empty\n");
                break;
            }
        case 3:
            {
                temp=root;
                if(root!=NULL)
                {
                    printf("Maximum Value in this BST is %d\n",max_value(temp));
                }
                else
                {
                    printf("Given BST is empty\n");
                }
                break;
            }
        case 4:
            {
                printf("Enter the value you want to search :");
                scanf("%d",&key);
                temp=root;
                search(key,temp);
                if( q == NULL)
                    printf("\nGiven element is not present in the BST\n ");
                else
                    printf("\nGiven element is present in the BST\n");
                q=NULL;
                break;
            }
        case 5:
            {
                temp=root;
                printf("Preorder :\n");
                preorder(temp); printf("\n");
                temp=root;
                printf("Postoder :\n");
                postorder(temp); printf("\n");
                temp=root;
                printf("Inorder : \n");
                inorder(temp); printf("\n");
                break;
            }
        case 6:
            {
                printf("Exiting Program\n");
                return 0;
            }
        default:
            {
                printf("Invalid Input.Try again.\n");
                break;
            }
        }
    }
    return 0;
}

