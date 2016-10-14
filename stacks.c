#include <stdio.h>
#include <stdlib.h>

struct stack
{ int top,*a; };
typedef struct stack stack;

stack* start(int size)
{
	stack *st=(stack*)malloc(sizeof(stack));
	st->a=(int*)malloc(sizeof(int)*size);
	st->top=-1;
	return st;
}

void push(stack *s,int k)
{ s->a[++s->top]=k; }

void pop(stack *s)
{   
	if(s->top==-1) return; 
	s->top--;
}

int peek(stack *s)
{ return s->a[s->top]; }

void print(stack *s)
{
	int i;
	if(s->top==-1)
		printf("--empty--");
	else
	for(i=0;i<=s->top;i++)
		printf("%d ",s->a[i]);
	printf("\n");
}

int main()
{
	stack *st=start(10);
	print(st);
	push(st,23);
	push(st,45);
	print(st);
	pop(st);
	print(st);
}