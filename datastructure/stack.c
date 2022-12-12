#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node *next;
}*newnode;
//void push();
//void pop();
//void search();
//void traverse();
struct node *top,*temp,*i,*head;
//head=NULL;
//top=NULL;
int ele;
void main()
{
   int ch;
   while(1)
   {
     printf("\n1.PUSH\n2.POP\n3.SEARCH\n4.TRAVERSE\n5.EXIT\nEnter your choice:");
     scanf("%d",&ch);
     switch(ch)
     {
        case 1:
              newnode=(struct node *)malloc(sizeof(struct node));
              
              printf("Enter a element:");
              scanf("%d",&ele);
              newnode->data=ele;
              newnode->next=NULL;
              if(head==NULL)
               {
                head=top=newnode;
               }
             else
               {
               top->next=newnode;
               top=newnode;
               }
              break;
       case 2://pop();
                  if(head==NULL)
                  {
                  printf("\nStack is empty\n");
                  }
                  else
                  {
                  i=head;
                 while(i->next->next!=NULL)
                   {
                  i=i->next;
                   }
                 i->next=NULL;
                 top=i;
                 }
              break;
       case 3://search();
               if(head==NULL)
  {
    printf("\nStack is empty\n");
  }
  else
  {
    int a,j,flag=0;
    printf("\nEnter element to be search:");
    scanf("%d",&a);
    for(temp=head,j=1;temp!=NULL;temp=temp->next,j++)
    {
      if(temp->data==a)
      {
        printf("Element found at position %d",j);
        flag=1;
        break;
       }
     }
     if(flag==0)
     {
       printf("Element not found");
     }
  }
              break;
       case 4://traverse();
                   if(head==NULL)
  {
    printf("\nStack is empty\n");
  }
  else
  {
    for(temp=head;temp!=NULL;temp=temp->next)
    {
      {
        printf("%d\t",temp->data);
       
      }
    }
     
  }
              break;
       case 5:exit(0);
       default:printf("\nInvalid choice");
      }
    }
}
  
  
  
  
  
  
  
  
