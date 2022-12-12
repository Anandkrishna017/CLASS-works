#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *left,*right;
 };
struct node *root;
struct node *create(int data)
{
  struct node *newnode=(struct node *)malloc(sizeof(struct node));
  newnode->data=data;
  newnode->left=NULL;
  newnode->right=NULL;
  return newnode;
}
void insert(int data)
{
  struct node *new=create(data);
  if(root==NULL)
  {
     root=new;
     return;
  }
  else
  {
    struct node *current=root,*parent=NULL;
    while(1)
    {
       parent=current;
       if(data<current->data)
       {
         current=current->left;
         if(current==NULL)
         {
           parent->left=new;
           return;
         }
        }
       else
       {
        current=current->right;
        if(current==NULL)
         {
           parent->right=new;
           return;
         }
        }
     }
    }
 }
 struct node *min(struct node *root)
 {
   if(root->left!=NULL)
      return min(root->left);
   else
      return root;
 }
 
struct node *delete(struct node *node, int value)
{
  if(node==NULL)
  {
     return node;
  }
  else
  {
    if(value<node->data)
      node->left=delete(node->left,value);
    else if(value>node->data)
      node->right=delete(node->right,value);
    else
    {
       if(node->left==NULL && node->right==NULL)
          node=NULL;
       else if(node->left==NULL)
       {
         node=node->right;
       }
       else if(node->right==NULL)
       {
         node=node->left;
       }
       else
       {
         struct node *temp=min(node->right);
         node->data=temp->data;
         node->right=delete(node->right,temp->data);
       }
    }
    return node;
   }
 }
 
 struct node *search(struct node *root,int data)
 {
   if(root)
   {
     if(root->data==data)
        return root;
     else if(data>root->data)
        return search(root->right,data);
     else
        return search(root->left,data);
   }
   else
      return 0;
 }
 void inorder(struct node *root)
 {
   if(root!=NULL)
   {
     inorder(root->left);
     printf("%d\t",root->data);
     inorder(root->right);
    }
  }
  void main()
  {
    int ch,val,ele;
    struct node *flag;
    printf("1 Insert\n 2 Delete\n3 search\n 4 Traverse\n 5 Exit");
    while(1)
    {
    printf("\n Enter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
     case 1: printf("Enter a value:");
             scanf("%d",&val);
             insert(val);
             break;
     case 2:if(root==NULL)
               printf("empty tree:");
            else
              {
                printf("Enter the item:");
                scanf("%d",&ele);
                root=delete(root,ele);
              }
             break;
     case 3:if(root==NULL)
               printf("Empty tree");
            else
            {
                printf("Enter the item:");
                scanf("%d",&val);
                flag=search(root,val);
                if(!flag)
                   printf("element not found");
                else
                   printf("element found");
            }
            break;
    case 4:if(root==NULL)
              printf("Empty tree");
           else
                  inorder(root);
           break;
    case 5:exit(0);
    default:printf("Invalid choicce");
    }
    }
 }  
              
  
                    
          
