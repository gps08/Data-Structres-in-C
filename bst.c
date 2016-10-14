#include <stdio.h>
#include <stdlib.h>

typedef struct node
{ struct node *r,*l; int data; }node;

void insert(node** root,int data)
{
	if(*root==NULL)
	{
		*root=(node*)malloc(sizeof(node));
		(*root)->data=data;
		(*root)->l=(*root)->r=NULL;
	} 
	else if(data<=(*root)->data)
		insert(&((*root)->l),data);
	else if(data>(*root)->data)
		insert(&((*root)->r),data);
}

node* findmin(node* root)
{
	while(root->l!=NULL) root=root->l;
	return root;
}

void del(int data,node** root)
{
	if(*root==NULL) return;
	else if((*root)->data<data)
		del(data,&((*root)->r));
	else if((*root)->data>data)
		del(data,&((*root)->l));
	else
	{
		if((*root)->l==NULL)
		{
			node* te=(*root)->r;
			free(*root);
			*root=te;
		}
		else if((*root)->r==NULL)
		{
			node* te=(*root)->l;
			free(*root);
			*root=te;
		}
		else
		{
			node* min=findmin((*root)->r);
			(*root)->data=min->data;
			del(min->data,&((*root)->r));
		}
	}
}

void inorder(node* root)
{
	if(root->l) inorder(root->l);
	printf("%d ",root->data);
	if(root->r) inorder(root->r);
}

void preorder(node* root)
{
	printf("%d ",root->data);
	if(root->l) preorder(root->l);
	if(root->r) preorder(root->r);
}

void postorder(node* root)
{
	if(root->l) postorder(root->l);
	if(root->r) postorder(root->r);
	printf("%d ",root->data);
}

void print(node* root,int lev=1)
{
	printf("%d",root->data);
	if(root->l) 
	{
		printf("-");
		print(root->l,lev+1);
	}
	if(root->r) 
	{
		printf("\n%*s",3*lev+4,"└─");
		print(root->r,lev+1);
	}
}

int min(int a,int b)
{
	if(a==0) return b;
	if(b==0) return a;
	return a<b ? a:b;
}

int min_depth(node* root)
{
	if(root==NULL) return 0;
	return 1+min(min_depth(root->r),min_depth(root->l));
}

int lca(int a,int b,node* root)
{
	//if(root==NULL) return -1;
	if(root->data>a && root->data>b)
		return lca(a,b,root->l);
	if(root->data<a && root->data<b)
		return lca(a,b,root->r);
	return root->data;
}


int main()
{
	node *root=NULL;
	insert(&root,4);
	insert(&root,5);
	insert(&root,6);
	insert(&root,2);
	print(root); printf("\n\n");
	del(4,&root);
	print(root); printf("\n\n");
}