#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

struct node
{
	int *keys, n;	//n => current no. of keys
	char leaf;
	struct node **c;
} *root = NULL;

typedef struct node node;
int m, t;

void rem(node *x, int k);	//don't change rem to remove because of inbuilt remove function

node *create(char leaf, int n)
{
	node *z = (node *)malloc(sizeof(node));
	z->keys = (int *)calloc(2*t-1, sizeof(int));
	z->c = (node **)calloc(2*t, sizeof(node *));
	z->leaf = leaf;
	z->n = n;
	return z;
}
void traverse(node *x)
{
	int i;
	for(i = 0; i < x->n; i++)
	{
		if(x->leaf == FALSE)
			traverse(x->c[i]);
		printf("%d ", x->keys[i]);	
	}
	if(x->leaf == FALSE)
		traverse(x->c[i]);
}
/* below 3 functions for insertion */
void split(node *x, node *y, int i)
{
	int j;
	node *z = create(y->leaf, t-1);
	
	for(j = 0; j < t-1; j++)
		z->keys[j] = y->keys[j+t];
	
	if(y->leaf == FALSE)
		for(j = 0; j < t; j++)
			z->c[j] = y->c[j+t];
	
	y->n = t-1;
	
	for(j = x->n; j >= i+1; j--)
		x->c[j+1] = x->c[j];
	x->c[i+1] = z;
	
	for(j = x->n - 1; j >= i; j--)
		x->keys[j+1] = x->keys[j];
	x->keys[i] = y->keys[t-1];
	
	x->n++;			
}
void ins_non_full(node *x, int k)
{
	int i;
	if(x->leaf == TRUE)
	{
		for(i = x->n - 1; i >= 0 && x->keys[i] > k; i--)
			x->keys[i+1] = x->keys[i];
		x->keys[i+1] = k;
		x->n = x->n + 1;	
	}
	else
	{
		i = x->n - 1;
		while(i >= 0 && x->keys[i] > k)
			i--;
		
		if(x->c[i+1]->n == 2*t-1)
		{
			split(x, x->c[i+1], i+1);
			if(x->keys[i+1] < k)
				i++;
		}
		
		ins_non_full(x->c[i+1], k);
	}
}
void ins(int k)
{
	int i = 0;
	node *s;
	if(root == NULL)
	{
		root = create(TRUE, 1);
		root->keys[0] = k;
		return;
	}
	if(root->n == 2*t-1)
	{
		s = create(FALSE, 0);
		s->c[0] = root;
		split(s, root, 0);
		if(s->keys[0] < k)
			i++;
		ins_non_full(s->c[i], k);
		root = s;	
	}
	else
		ins_non_full(root, k);
}
/* below 8 functions for deletion */
void borrow_from_prev(node *x, int i)
{
	int p;
	node *child = x->c[i], *sibling = x->c[i-1];
	
	for(p = child->n-1; p >= 0; p--)
		child->keys[p+1] = child->keys[p];
		
	if(child->leaf == FALSE)
	{
		for(p = child->n; p >= 0; p--)
			child->c[p+1] = child->c[p];
		child->c[0] = sibling->c[sibling->n];	
	}
			
	child->keys[0] = x->keys[i-1];
	x->keys[i-1] = sibling->keys[sibling->n-1];
	
	child->n += 1;
	sibling->n -= 1;			
}
void borrow_from_next(node *x, int i)
{
	int p;
	node *child = x->c[i], *sibling = x->c[i+1];
	child->keys[child->n] = x->keys[i];
	
	if(child->leaf == FALSE)
		child->c[child->n + 1] = sibling->c[0];
		
	x->keys[i] = sibling->keys[0];	
	
	for(p = 1; p < sibling->n; p++)
		sibling->keys[p-1] = sibling->keys[p];
		
	if(sibling->leaf == FALSE)
		for(p = 1; p <= sibling->n; p++)
			sibling->c[p-1] = sibling->c[p];
	
	child->n += 1;
	sibling->n -= 1;			
}
void merge(node *x, int i)
{
	int p;
	node *child = x->c[i], *sibling = x->c[i+1];
	child->keys[t-1] = x->keys[i];
	
	for(p = 0; p < sibling->n; p++)
		child->keys[p+t] = sibling->keys[p];
		
	if(child->leaf == FALSE)
		for(p = 0; p <= sibling->n; p++)
			child->c[p+t] = sibling->c[p];
	
	for(p = i+1; p < x->n; p++)
		x->keys[p-1] = x->keys[p];
	for(p = i+2; p <= x->n; p++)
		x->c[p-1] = x->c[p];
		
	child->n = child->n + sibling->n +1;
	x->n--;
	
	free(sibling);					
}
void fill(node *x, int i)
{
	if(i != 0 && x->c[i-1]->n >= t)
		borrow_from_prev(x, i);
	else if(i != x->n && x->c[i+1]->n >= t)
		borrow_from_next(x, i);
	else if(i != x->n)
		merge(x, i);
	else
		merge(x, i-1);	
}
void rem_from_leaf(node *x, int i)
{
	int p;
	for(p = i+1; p < x->n; p++)
		x->keys[p-1] = x->keys[p];
	x->n--;	
}
void rem_from_nonleaf(node *x, int i)
{
	int k = x->keys[i], pred, succ;
	node *cur;
	
	if(x->c[i]->n >= t)
	{
		for(cur = x->c[i]; cur->leaf != TRUE; cur = cur->c[cur->n]);
		pred = cur->keys[cur->n-1];
		x->keys[i] = pred;
		rem(x->c[i], pred);
	}
	else if(x->c[i+1]->n >= t)
	{
		for(cur = x->c[i+1]; cur->leaf != TRUE; cur = cur->c[0]);
		succ = cur->keys[0];
		x->keys[i] = succ;
		rem(x->c[i+1], succ);
	}
	else
	{
		merge(x, i);
		rem(x->c[i], k);
	}
}
void rem(node *x, int k)
{
	int i=0, flag;
	while(i < x->n && x->keys[i] < k)
		++i;
	
	if(i < x->n && x->keys[i] == k)
	{
		if(x->leaf == TRUE)
			rem_from_leaf(x, i);
		else
			rem_from_nonleaf(x, i);
	}
	else if(x->leaf == TRUE)
		printf("\nThe key %d does not exist in the tree\n", k);
	else
	{
		flag = (i == x->n)? TRUE : FALSE;
		
		if(x->c[i]->n < t)
			fill(x, i);
			
		if(flag && i > x->n)
			rem(x->c[i-1], k);
		else
			rem(x->c[i], k);		
	}		
}
void del(int k)
{
	node *tmp;
	if(root == NULL)
	{
		printf("The tree is empty\n");
		return;
	}
	
	rem(root, k);
	
	if(root->n == 0)
	{
		tmp = root;
		if(root->leaf == TRUE)
			root = NULL;
		else
			root = root->c[0];
		free(tmp);		
	}
}
int search(node *x, int k)
{
	int i = 0;
	if(x == NULL)
		return -1;
	while(i < x->n && k > x->keys[i])
		i++;
	if(x->keys[i] == k)
		return 1;
	if(x->leaf == TRUE)
		return -1;
	return search(x->c[i], k);			
}
void main()
{
	int n, i, data;
	printf("Enter the order of B-Tree:	");
	scanf("%d", &t);
	//t = m/2;
	
	do
	{
		printf("1.Insert\t 2.Delete\t 3.Search\t (Input any other no. to exit):\t");
		scanf("%d", &i);
		switch(i)
		{
			case 1: printf("Enter no. of values to insert:	");
					scanf("%d", &n);
					printf("Enter %d values:\n", n);
					for(; n > 0; n--)
					{
						scanf("%d", &data);
						ins(data);
					}	
					printf("The tree now is:\t");
					traverse(root);
					printf("\n");
					break;
			case 2: printf("Enter the data to be deleted:\t");
					scanf("%d", &data);
					del(data);
					printf("The tree now is:\t");
					traverse(root);
					printf("\n");
					break;
			case 3: printf("Enter the number to search:\t");
					scanf("%d", &data);
					n = search(root, data);
					if(n == -1)
						printf("%d is not present in this tree\n", data);
					else
						printf("%d is present in this tree\n", data);
					break;
			default: exit(0);				
		}
	} while(i >= 1 && i <= 3);		
}
