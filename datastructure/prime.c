#include<stdio.h>
void main()
{
int a,count=0,i;
printf("enter a number:");
scanf("%d",&a);
for(i=1;i<=a;i++)
{
  if(a%i==0)
     count++;
}
if(count==2)
  printf("prime");
else
  printf("not prime");
}
