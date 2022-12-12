#include<stdio.h>
void main()
{
 int a,b,c=0,i;
a=0;
b=1;
printf("\n%d",a);
printf("\n%d",b);
while(c<=10)
{
  c=b+a;
  printf("\n%d",c);
 a=b;
 b=c;
}
}

