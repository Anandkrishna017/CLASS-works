#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
  struct node *prev;
 
  struct node *next;
};
struct node *head;
void insertbegin();
void insertend();
void insertpos();
void deletebegin();
void deleteend();
  void deletepos();
  void display();
  void search();
void main()
{
  int ch=0;
  while(ch!=9)
  {
    printf("\n1.Insert in begining\n2.Insert at last\n3.insert at position\n.4.Delete from begining\n5.Delete from last\n6.delete at position\n7.display\n8.search\n9.exit\n");
    printf("\nEnter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
       case 1: insertbegin();
       
         	break;
       case 2: insertend();
               break;
        case 3:insertpos();
        
               break;
        case 4:deletebegin();
               break;
        case 5:deleteend();
               break;
        case 6:deletepos();
               break;
        case 7:display();
               break;
        case 8:search();
                break;
         case 9:exit(0);
         default:printf("Invalid choice");
       }
     }
  } 
  
  void insertbegin()
  {
               int item;
               struct node *ptr;
               ptr=(struct node *)malloc(sizeof(struct node));
               if(ptr==NULL)
                {
         	  printf("\nOverflow");
       	 }
       	else
       	{
        	 printf("\nEnter a value:");
         	scanf("%d",&item);
         	if(head==NULL)
         	{
           	ptr->next=NULL;
           	ptr->prev=NULL;
           	ptr->data=item;
           	head=ptr;
          	}
         	 else
         	 {
         	   ptr->data=item;
         	   ptr->prev=NULL;
         	   ptr->next=head;
         	   head->prev=ptr;
         	   head=ptr;
         	  }
         	}
  
  }  
  
  
  void insertend()
  {
      struct node *ptr,*temp;
              int item;
              ptr=(struct node *)malloc(sizeof(struct node));
              if(ptr==NULL)
              {
                printf("\nOverflow");
              }
              else
              {
                printf("\nEnter value:");
                scanf("%d",&item);
                ptr->data=item;
                if(head==NULL)
                {
                  ptr->next=NULL;
                  ptr->prev=NULL;
                  head=ptr;
                }
                else
                {
                  temp=head;
                  while(temp->next!=NULL);
                  {
                    temp=temp->next;
                  }
                  temp->next=ptr;
                  ptr->prev=temp;
                  ptr->next=NULL;
                }
               }
  
  }
  
  
  void insertpos()
  {
     struct node *ptr,*temp;
              int item,loc,i;
              ptr=(struct node *)malloc(sizeof(struct node));
              if(ptr==NULL)
              {
                printf("\nOverflow");
              }
              else
              {
                temp=head;
                printf("Enter the location:");
                scanf("%d",&loc);
                for(i=0;i<loc;i++)
                {
                  temp=temp->next;
                  if(temp==NULL)
                  {
                    printf("There is %d elements ",loc);
                    return;
                  }     
                }
                printf("\nEntervalue:");
                scanf("%d",&item);
                ptr->data=item;
                ptr->next=temp->next;
                ptr->prev=temp;
                temp->next=ptr;
                temp->next->prev=ptr;
               }  
  
  }
  
  void deletebegin()
  {
                struct node *ptr;
              if(head==NULL)
               {
                 printf( "\nunderflowflow");
               }
              else if(head->next==NULL) 
              { 
                head=NULL;
                free(head);
               }
               else
               {
               ptr=head;
               head=head->next;
               head->prev=NULL;
               free(ptr);
               }
  
  }
  void deleteend()
  {
    struct node *ptr;
               if(head==NULL)
               {
                 printf( "\nUnderflow");
               }
              else if(head->next==NULL) 
              { 
                head=NULL;
                free(head);
               }
               else
               {
               ptr=head;
               if(ptr->next!=NULL)
               {
                ptr=ptr->next;
               }
               ptr->prev->next=NULL;
               free(ptr);
               }
  }
  void deletepos()
  {
     struct node *ptr,*temp;
               int val;
               printf("Enter the data after which the node is to be deleted:");
               scanf("%d",&val);
               ptr=head;
               while(ptr->next==NULL)
                  ptr=ptr->next;
               if(ptr->next==NULL)
               {
                 printf("\nCan't Delete");
               }
               else if(ptr->next->next==NULL)
               {
                 ptr->next=NULL;
               }
               else
               {
                 temp=ptr->next;
                 ptr->next=temp->next;
                 temp->next->prev=ptr;
                 free(temp);
               }
  }
  void display()
  {
    struct node *ptr;
               printf("\nValues are :\n");
               ptr=head;
               while(ptr!=NULL)
               {
                 printf("%d\t",ptr->data);
                 ptr=ptr->next;
               }
  
  
  }
  void search()
  {
     struct node *ptr;
               int item,j=0,flag=0;
               ptr=head;
               if(ptr==NULL)
               {
                 printf("\nEmpty list");
               }
               else
               {
                 printf("Enter element to be Search:");
                 scanf("%d",&item);
                 while(ptr!=NULL)
                 {
                   if(ptr->data==item)
                   {
                     printf("item found at location %d",j+1);
                     flag=0;
                     break;
                   }
                   else
                   {
                     flag=1;
                   }
                   j++;
                   ptr=ptr->next;
                 }
                if(flag==1)
                {
                  printf("item not found");
                }
               }
  
  
  }
