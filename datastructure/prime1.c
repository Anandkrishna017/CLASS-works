#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
  int ch,flag=0;
  char s1[20],s2[20];
  int x,k,y;
  printf("\n1.Prime factor\n2.Sum of digit\n3.Compare String\n4.exit\n");
  while(1)
  {
    printf("\nEnter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:   printf("\nPRIME FACTORS:\n");
                printf("\n---------------------\n");
               int i,j,num;
               printf("\nEnter a number:");
               scanf("%d",&num);
               printf("\nPrime factors are:");
               flag=-1;
               for(i=2;i<=num;i++)
               {
                 if(num%i==0)
                 {
                   flag=1;
                   for(j=2;j<=i/2;j++)
                   {
                    if(i%j==0)
                    {
                      flag=0;
                      break;
                    }
                  }
                  if(flag==1)
                  {
                    printf("%d\t",i);
                  }
                }
               }
               if(flag==-1)
               {
                  printf("\nNo prime factor");
               }
               
               break;
        case 2: printf("\nSUM OF DIGITS\n");
                printf("\n---------------------\n");
                int d,sum=0,n;
                printf("Enter a number:");
                scanf("%d",&n);
                while(n!=0)
                {
                  d=n%10;
                  sum=sum+d;
                   n=n/10;
                  }
                 printf("\nSUM=%d",sum);
                 break;
        case 3:printf("\nString compare\n");
               printf("\n---------------------\n");
               printf("\nenter first string:");
               scanf("%s",s1);
               printf("\nenter second string:");
               scanf("%s",s2);
               x=strlen(s1);
               y=strlen(s2);
               if(x==y)
               {
               for(k=0;k<x;k++)
               {
                 if(s1[k]==s2[k])
                    flag=1;
                 else
                 {
                    flag=0;
                     break;
                  }
                }
                if(flag==1)
                   printf("\nStrings are same");
                else
                   printf("\nStrings are not same");
                }
                else
                   printf("\nStrings are not same");
                 break;
       case 4:exit(0);
       default:printf("\nInvalid choice");
      }
      }
      
 }
                
