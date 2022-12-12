#include<stdio.h>
void main()
{
int n,a[100],i;
 printf("enter the size of array:");
 scanf("%d",&n);
printf("enter the elements:");
 for(i=0;i<n;i++)
 {
  scanf("%d",&a[i]);

 }
printf("\n%d\n",a[1]);
for(i=1;i<n;i++)
{
 if(a[0]<a[i])
  {
    a[0]=a[i];
 }
}
printf("%d\n",a[0]);
}

