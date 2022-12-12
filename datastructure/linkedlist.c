#include<stdlib.h>
#include<stdio.h>
void main()
{
  struct node
  {
   int data;
   struct node *next;
  };

struct node *head,*newnode,*current;
head=NULL;


//creation
printf("Enter no. of nodes:");
int n;
scanf("%d",&n);

for(int i=0;i<n;i++)
{
printf("Enter data:");
  newnode=(struct node *)malloc(sizeof(struct node));
  scanf("%d",&newnode->data);
  newnode->next=NULL;
  if(head==NULL)
  {
    head=newnode;
    current=newnode;
  }
  else
  {
    current->next=newnode;
    current=newnode;
  }
}
//traverse
for(current=head;current!=NULL;current=current->next)
{
printf("%d\t",current->data);
}

//insertion


}
