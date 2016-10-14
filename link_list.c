#include <stdio.h>
#include <stdlib.h>

typedef struct node
{ int data; struct node* next; }node;
typedef struct list
{ node *head,*tail; }list;

void ins_beg(list* l,int k) // O(1)
{
	node* temp=(node*)malloc(sizeof(node));
	temp->data=k; temp->next=l->head;
	if(l->tail==NULL) l->tail=temp;
	l->head=temp;
}

void ins_end(list* l,int k) // O(1)
{
	node* temp=(node*)malloc(sizeof(node));
	temp->data=k; temp->next=NULL;
	if(l->head==NULL) l->head=temp;
	else l->tail->next=temp;
	l->tail=temp;
}

void ins_pos(list* l,int k)
{
	node *temp=(node*)malloc(sizeof(node)),*pr=NULL,*i=l->head;
	temp->data=k;
	if(l->head==NULL||l->head->data>=k)
	{
		temp->next=l->head;
		l->head=temp;
		return;
	}
	while(i!=NULL && i->data<k)
	{	
		pr=i;
		i=i->next;
	}
	pr->next=temp;
	temp->next=i;
	if(i==NULL) l->tail=temp;
}

void del_duplicate(list* l)
{
	if(l->head==NULL) return;
	node *cur=l->head,*next;
	while(cur->next!=NULL)
	{ 
		next=cur->next;
		if(next->data==cur->data)
		{
			cur->next=next->next;
			free(next);
		}
		else cur=cur->next;
	}
}

void del(list* l,int k)
{
	if(l->head==NULL) return; // list empty
	node *pre=l->head,*cur=l->head->next;
	if(l->head!=NULL && l->head->data==k)
	{
		free(l->head);
		l->head=cur;
		return;
	}
	while(cur!=NULL && cur->data!=k)
	{
		pre=cur;
		cur=cur->next;
	}
	if(cur==NULL) return; // data not found
	if(cur->next==NULL) l->tail=pre; // del last element
	pre->next=cur->next;
	free(cur);
}

void print(list l)
{	
	while(l.head!=NULL)
	{
		printf("%d ",l.head->data);
		l.head=l.head->next;
	}
	printf("\n");
}

int main()
{
	list l1; 
	l1.head=NULL;
	l1.tail=NULL;

	ins_end(&l1,23);
	ins_beg(&l1,46);
	ins_end(&l1,53);
	
	print(l1);
	del(&l1,53);
	print(l1);
}