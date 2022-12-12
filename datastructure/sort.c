#include<stdio.h>
void main()
{
int a[100],i,j,temp,n;
printf("Enter the size of array:");
scanf("%d",&n);
printf("enter the elements:");
for(i=0;i<n;i++)
{
  scanf("%d",&a[i]);
}
for(i=0;i<n;i++)
{
 for(j=i+1;j<n;j++)
 {
  if(a[i]>a[j])
  {
    temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}
}
}
printf("Sorted array is:");
for(i=0;i<n;i++)
{
  printf("%d\t",a[i]);
}
}
