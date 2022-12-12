#include<stdio.h>
void main()
{
 int i,j,m,n,a[100],b[100],c[200],k,temp=0;
 printf("Enter the size of 1st array:");
 scanf("%d",&m);
 printf("enter the elements of 1st array:");
 for(i=0;i<m;i++)
 {
  scanf("%d",&a[i]); 
 }
 for(i=0;i<m;i++)
 {
   for(j=i+1;j<m;j++)
   {
    if(a[i]>a[j])
    {
     temp=a[i];
     a[i]=a[j];
     a[j]=temp;
    }
   }
 }

 printf("Enter the size of 2nd array:");
 scanf("%d",&n);
 printf("enter the elements of 2nd array:");
 for(j=0;j<n;j++)
 {
 scanf("%d",&b[j]);
 }
  


 for(i=0;i<n;i++)
 {
  for(j=i+1;j<n;j++)
  {
   if(b[i]>b[j])
   {
   temp=b[i];
   b[i]=b[j];
   b[j]=temp;
   }
  }
 }


i=j=0;
for(k=0;k<m+n;k++)
{
  if(i<m && j<n)
  {
   if(a[i]<b[j])
   {
     c[k]=a[i];
     i++;
   }
  else
    {
     c[k]=b[j];
     j++;
    }
   }
  else if(i<m)
  {
    c[k]=a[i];
    i++;
  }
 else 
  {
   c[k]=b[j];
   j++;
  }
}

  printf("The merged array is :\n");
  for(k=0;k<m+n;k++)
  {
    printf("%d\t",c[k]);
  }
}
