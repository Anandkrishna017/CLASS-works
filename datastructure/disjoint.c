#include<stdio.h>
#include<stdlib.h>
int find(int val,int parentf[])
{
if(parentf[val]==-1)
   return -1;
if(parentf[val]==val)
   return val;
parentf[val]=find(parentf[val],parentf);
}

int unio(int x,int y, int parentu[],int ranku[])
{
  int xroot=find(x,parentu);
  int yroot=find(y,parentu);
  if(xroot==-1 || yroot==-1)
     return -1;
  if(x==y)
     return xroot;
  if(ranku[xroot]<ranku[yroot])
   {
      parentu[xroot]=yroot;
      return yroot;
   }
  else if(ranku[xroot]>ranku[yroot])
  {
    parentu[yroot]=xroot;
    return xroot;
  }
  else
  {
    parentu[yroot]=xroot;
    ranku[xroot]=ranku[xroot]+1;
    return xroot;
  }
  }
  int makeset(int a,int parentm[],int rankm[])
  {
    parentm[a]=a;
    rankm[a]=1;
    return parentm[a];
   }
   int main()
   {
   int sizeu,ch,value,root,r1,r2;
   printf("Enter Universal set:");
   scanf("%d",&sizeu);
   int parent[sizeu],rank[sizeu];
   for(int k=0;k<sizeu;k++)
   {
     parent[k]=-1;
     parent[k]=0;
   }
   printf("\n1.Make set\n2.Union\n3.Find\n4.exit\n");
   while(1)
   {
     printf("Enter choice:");
     scanf("%d",&ch);
     switch(ch)
     {
       case 1:printf("Enter rep:");
              scanf("%d",&r1);
              root=makeset(r1,parent,rank);
              printf("set created\n");
              break;
       case 2:printf("Enter 2 elements:");
              scanf("%d%d",&r1,&r2);
              int re1=parent[r1],re2=parent[r2];
              root=unio(r1,r2,parent,rank);
              printf("\nUnion set:");
              for(int i=0;i<sizeu && root!=-1;i++)
              {
                if(parent[i]==re1 || parent[i]==re2)
                {
                  parent[i]=root;
                  printf("%d",i);
                 }
               }
               printf("\n");
              break;
        case 3:printf("Enter a value to find:");
               scanf("%d",&value);
               if(parent[value]==-1 || value<0 || value>sizeu-1)
                   printf("Element not found\n");
               else
               {
                 root=find(value,parent);
                 printf("Element  found in %d\n",root);
                }
                break;
         case 4:exit(0);
         defaulf:printf("\nInvalid choice");
       }
       }
       }
