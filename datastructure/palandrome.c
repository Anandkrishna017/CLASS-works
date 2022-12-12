#include<stdio.h>
void main()
{
string s;
int flag=0,n,i
printf("enter a string");
scanf("%s",&s);
n=strlen(s);
for(i=0;i<n/2;i++)
{

if(s[i]==s[(n/2)+i+1])
 continue;
else 
  flag=1;
}
if(flag=1)
  printf("not palindrome");
else
  printf("palindrome");
}
