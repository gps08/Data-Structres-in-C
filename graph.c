#include <stdio.h>
#include <stdlib.h>

typedef struct node
{ int data; struct node* next; }node;
typedef struct list
{ node *head,*tail; }list;

void ins_end(list* l,int k)
{
	node* temp=(node*)malloc(sizeof(node));
	temp->data=k; temp->next=NULL;
	if(l->head==NULL) l->head=temp;
	else l->tail->next=temp;
	l->tail=temp;
}

typedef struct graph
{ list* array; int size; int* visited; int* dist; }graph;

graph* create_graph(int size)
{
	graph* te=(graph*)malloc(sizeof(graph));
	te->array=(list*)malloc(size*sizeof(list));
	te->visited=(int*)malloc(size*sizeof(int));
	te->dist=(int*)malloc(size*sizeof(int));
	te->size=size; int i=-1; 
	while(++i<size) 
		te->array[i].head=te->array[i].tail=NULL;
	return te;
}

graph g1;

void add_edge(int a,int b)
{
	if(a>=g1.size || b>=g1.size) return;
	ins_end(&(g1.array[a]),b);
	//ins_end(&(g1.array[b]),a);
}

void print()
{
	int i;
	for(i=0;i<g1.size;i++)
	{
		printf("%d: ",i);
		node *te=g1.array[i].head;
		for(te=g1.array[i].head;te!=NULL;te=te->next)
			printf("%d ",te->data);
		printf("\n");
	}
}

void dfs_visit(int i)
{
	node* te;
	//g1.visited[i]=1;	
	for(te=g1.array[i].head;te!=NULL;te=te->next)
		if(g1.visited[te->data]==0)
			dfs_visit(te->data);
	printf("-%d-",i);
	g1.visited[i]=2;	
}

void dfs()
{
	int i;
	
	for(i=0;i<g1.size;i++)
		g1.visited[i]=0;
	
	for(i=0;i<g1.size;i++)
		if(g1.visited[i]==0)
			dfs_visit(i);

	printf("\n");
}

list queue;

int dequeue()
{
	int ret=queue.head->data;
	if(queue.head==queue.tail) 
		queue.head=queue.tail=NULL;
	else queue.head=queue.head->next;
	return ret;
}

void bfs()
{
	int i; 	node* v;
	for(i=0;i<g1.size;i++)
		g1.dist[i]=-1;

	ins_end(&queue,0);
	g1.dist[0]=0;
	while(queue.head!=NULL)
	{
		int u=dequeue();
		for(v=g1.array[u].head;v!=NULL;v=v->next)
			if(g1.dist[v->data]==-1)
			{
				printf("VISIT:%d-%d\n",u+1,v->data+1);
				g1.dist[v->data]=g1.dist[u]+1;
				ins_end(&queue,v->data);
			}
	}
}


int main()
{
	g1=*create_graph(10);
	add_edge(1,3);
	add_edge(2,3);
	add_edge(1,2);
	add_edge(3,5);
	add_edge(6,5);
	add_edge(2,7);
	add_edge(8,2);
	add_edge(8,7);
	add_edge(8,9);
	dfs();
	queue.head=queue.tail=NULL;
	bfs();
	print();
}