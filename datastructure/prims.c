#include<stdio.h>
#include<stdlib.h>
struct edge{
	int v1,v2,w;
}*edges;
int num,no,sum=0,*vjk;

void sort_by_weight()
{ struct edge e;
  int i,j,min_idx;
  for(i=0;i<no;i++)
  { min_idx=i;
    for(j=i+1;j<no;j++)
       if(edges[j].w<edges[min_idx].w)
          min_idx=j;
    e=edges[i];
    edges[i]=edges[min_idx];
    edges[min_idx]=e;
    }
}

int is_in(int v)
{ if(vjk[v]==v)
    return 1;
  return 0;
}

void output()
{ int i,vj,vk;
  for(i=0;i<no;i++)
  { vj=edges[i].v1;
    vk=edges[i].v2;
    if((is_in(vj)&&!is_in(vk))||(is_in(vk)&&!is_in(vj)))
    { (is_in(vj)&&!is_in(vk))? printf("%d-%d\t%d\n",vj,vk,edges[i].w): printf("%d-%d\t%d\n",vk,vj,edges[i].w);
      vjk[vj]=vj;
      vjk[vk]=vk;
      sum+=edges[i].w;
      num--;
      break;
      }
    }
  if(num==1)
     return;
  output();
}

void main()
{ int i,v1,v2,w;
  printf("Enter no.of vertices:\t");
  scanf("%d",&num);
  vjk=(int *)malloc(num *sizeof(int));
  edges=(struct edge *)calloc(num * (num-1),sizeof(struct edge));
  for(i=0;i<num;i++)
     vjk[i]=-1;
  printf("Enter edges in the following format to create a graph: SOURCE_VERTEX, DESTINATION_VERTEX, EDGE_WEIGHT:\nEnter -1 to stop:\n");
  no=0;
  do
  { printf("Edge %d:\t",no);
    scanf("%d",&v1);
    if(v1==-1)
       break;
    scanf("%d",&v2);
    scanf("%d",&w);
    edges[no].v1=v1;
    edges[no].v2=v2;
    edges[no].w=w;
    no++;
    }
  while(v1!=-1);
  edges=(struct edge *)realloc(edges,no*sizeof(struct edge));
  
  sort_by_weight();
  printf("Edges\tWeight\n");
  vjk[0]=0;
  output();
  printf("Minimum Cost Spanning Tree:%d\n",sum);
 } 
