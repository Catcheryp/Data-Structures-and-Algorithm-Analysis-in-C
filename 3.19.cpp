#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node *PtrToNode;
typedef PtrToNode stack;
typedef PtrToNode Position;

struct node
{
	int num;
	Position next;
};

int IsEmpty(stack s);
stack CreatStack();
void MakeEmpty(stack s);
void Push(int x, stack s);
void Pop(stack s);
int Top(stack s);

int IsEmpty(stack s)
{
	return s->next == NULL;
}


stack CreatStack()
{
	stack s;
	s = (node*)malloc(sizeof(struct node));
	if(s == NULL)
		printf("Out of space!\n");
	s->next = NULL;
	MakeEmpty(s);
	return s;
}

void MakeEmpty(stack s)
{
	if(s == NULL)
		printf("Must creat stack first!\n");
	else
		while(!IsEmpty(s))
			Pop(s);
}

void Push(int x, stack s)
{
	Position temp = (node*)malloc(sizeof(struct node));
	if(temp == NULL)
		printf("Out of space!\n");
	else
	{
		temp->num = x;
		temp->next = s->next;
		s->next = temp;
	}
}

void Pop(stack s)
{
	Position first;
	if(IsEmpty(s))
		printf("Empty stack!\n");
	else
	{
		first = s->next;
		s->next = s->next->next;
		free(first);
	}
}

int Top(stack s)
{
	if(!IsEmpty(s))
		return s->next->num;
	printf("Empty stack!\n");
	return 0;
}

int main()
{
	stack s = CreatStack();
	char *ch;
	char cc;
	int x, y, z;
	while(scanf("%s", ch) == 1)
	{
		if((int)atoi(ch))
		{
			int m = (int)atoi(ch);
			Push(m, s);
		}
		else
		{
			cc = ch[0];
			if(cc == '+')
			{
				x = Top(s);
				Pop(s);
				y = Top(s);
				Pop(s);
				z = x + y;
				Push(z, s);
			}
			else if(cc == '-')
			{
				x = Top(s);
				Pop(s);
				y = Top(s);
				Pop(s);
				z = x - y;
				Push(z, s);
			}
			else if(cc == '*')
			{
				x = Top(s);
				Pop(s);
				y = Top(s);
				Pop(s);
				z = x * y;
				Push(z, s);
			}
			else if(cc == '/')
			{
				x = Top(s);
				Pop(s);
				y = Top(s);
				Pop(s);
				z = x / y;
				Push(z, s);
			}
		}
	}

	printf("%d\n", Top(s));
	return 0;
}