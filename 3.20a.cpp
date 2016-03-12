#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node *PtrToNode;
typedef PtrToNode stack;
typedef PtrToNode Position;

struct node
{
	char ch;
	Position next;
};

int IsEmpty(stack s);
stack CreatStack();
void MakeEmpty(stack s);
void Pop(stack s);
void Push(char cc, stack s);
char Top(stack s);


int IsEmpty(stack s)
{
	return s->next == NULL;
}

stack CreatStack()
{
	stack s = (node *)malloc(sizeof(struct node));
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

void Pop(stack s)
{
	Position first;
	if(IsEmpty(s))
	{
		printf("AEmpty stack!\n");
	}
	else
	{
		first = s->next;
		s->next = s->next->next;
		free(first);
	}
}

void Push(char cc, stack s)
{
	Position temp = (node*)malloc(sizeof(struct node));
	if(temp == NULL)
		printf("Out of space!\n");
	else
	{
		temp->ch = cc;
		temp->next = s->next;
		s->next = temp;
	}
}

char Top(stack s)
{
	if(!IsEmpty(s))
		return s->next->ch;
	//printf("BEmpty stack!\n");
	return 0;
}

int main()
{
	stack s = CreatStack();
	char c1[10];
	char c2[100];//最终输出的数组
	char cc;
	int i = 0;
	while(scanf("%s", c1) == 1)
	{
		cc = c1[0];
		if((int)atoi(c1))
		{//这里暂且只考虑数字为一位数的情况,多位数字只要稍作修改即可
			c2[i++] = c1[0];
		}
		else
		{
			if(cc == '*' || cc == '/' || cc == '(')
			{
				Push(cc, s);
				printf("Push:%c\n", cc);
			}
			else if(cc == '+' || cc == '-')
			{
				while(Top(s) == '*' || Top(s) == '/' || Top(s) == '+' || Top(s) == '-')
				{
					c2[i++] = Top(s);
					printf("Pop:%c\n", Top(s));
					Pop(s);
				}
				Push(cc, s);
				printf("Push:%c\n", cc);
			}
			else if(cc == ')')
			{
				while(Top(s) != '(')
				{
					c2[i++] = Top(s);
					printf("Pop:%c\n", Top(s));
					Pop(s);
				}
				printf("Pop:%c\n", Top(s));
				Pop(s);
			}
		}
	}

	while(!IsEmpty(s))
	{
		c2[i++] = Top(s);
		printf("Pop:%c\n", Top(s));
		Pop(s);
	}

	for(int l = 0; l < i; ++l)
		printf("%c ", c2[l]);
	return 0;
}