#include<stdio.h>

void main()
{
  int set[50],A[50],a[50],b[50],B[50],u[50],inter[50],diff[50],unio[50];
  int s,c,d;
  int i,j;
  printf("\nEnter the size of Universal set:");
  scanf("%d",&s);
  printf("\nEnter elements:");
  for(i=0;i<s;i++)
     scanf("%d",&set[i]);
  printf("\nEnter the size of  setA:");
  scanf("%d",&c);
  printf("\nEnter elements:");
  for(i=0;i<c;i++)
     scanf("%d",&A[i]);
  printf("\nEnter the size of  setB:");
  scanf("%d",&d);
  printf("\nEnter elements:");
  for(i=0;i<d;i++)
     scanf("%d",&B[i]);
  
  for(i=0;i<s;i++)
  {
  for(j=0;j<c;j++)
    {
   if(set[i]==A[j])
   {
     a[i]=1;
   }
   }
   if(a[i]!=1)
     a[i]=0;
   
   }
   
  for(i=0;i<s;i++)
  {
    for(j=0;j<d;j++)
    {
   if(set[i]==B[j])
     b[i]=1;
   
  }
  if(b[i]!=1)
     b[i]=0;
  }
  
  
   for(i=0;i<s;i++)
  {
    u[i]=a[i]|b[i];
    inter[i]=a[i]&b[i];
    diff[i]=a[i]&(!b[i]);
   }
   printf("\nUniversal set:");
    for(i=0;i<s;i++)
     printf("%d \t",set[i]);
   printf("\n setA:");
    for(i=0;i<c;i++)
     printf("%d\t",A[i]);
   printf("\nBitstring setA:");
    for(i=0;i<s;i++)
    printf("%d\t",a[i]);
    printf("\n setB:");
    for(i=0;i<d;i++)
     printf("%d\t",B[i]);
   printf("\nBitstring setB:");
    for(i=0;i<s;i++)
     printf("%d\t",b[i]);
   printf("\nunion:");   
    
     
     for(i=0;i<s;i++)
  {
   if(u[i]==1)
   {
     printf("%d\t",set[i]);
   }
   
   }
     
   //for(i=0;i<s;i++)
     //printf("%d\t",unio[i]);  
     
     
     
   printf("\nintersection:");
    //for(i=0;i<s;i++)
    // printf("%d\t",inter[i]);
    
     for(i=0;i<s;i++)
  {
   if(inter[i]==1)
   {
     printf("%d\t",set[i]);
   }
   
   }
    
    
   printf("\nDifference:");
    //for(i=0;i<s;i++)
  
      //printf("%d\t",diff[i]);
 for(i=0;i<s;i++)
  {
   if(diff[i]==1)
   {
     printf("%d\t",set[i]);
   }
   
   }

 }
   
