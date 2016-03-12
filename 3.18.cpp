#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node *PtrToNode;
typedef PtrToNode stack;
typedef PtrToNode Position;

struct node
{
	char symbol;
	Position next;
};

int Isempty(stack s)
{
	return s->next == NULL;
}

void Pop(stack s)
{
	Position first;
	if(Isempty(s))
		printf("Empty stack!\n");
	else
	{
		first = s->next;
		s->next = s->next->next;
		free(first);
	}
}

void MakeEmpty(stack s)
{
	if(s == NULL)
		printf("Must use CreatStack first!\n");
	else
		while(!Isempty(s))
			Pop(s);
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

void Push(char sign, stack s)
{
	Position temp = (node *)malloc(sizeof(struct node));

	if(temp == NULL)
		printf("Out of space!\n");
	else
	{
		temp->symbol = sign;
		temp->next = s->next;
		s->next = temp;
	}
}

char Top(stack s)
{
	if(!Isempty(s))
		return s->next->symbol;
	printf("Empty stack!\n");
	return 0;
}


int main()
{
	char sign1;

	char sign[10];

	stack s = CreatStack();

	while(scanf("%s", sign) == 1)
	{
		sign1 = sign[0];

		if(sign1 == '\n')
			break;
		if(Isempty(s))
		{
			if(sign1 == '(' || sign1 == '[' || sign1 == '{' || sign1 == 'b')
			{
				Push(sign1, s);
			}
			else 
			{
				printf("AWrong!!!\n");
				break;
			}
		
		}
		else
		{
			if(sign1 == '(' || sign1 == '[' || sign1 == '{' || sign1 == 'b')
			{
				Push(sign1, s);
			}
			else if(sign1 == ')' || sign1 == ']' || sign1 == '}' || sign1 == 'e')
			{
				if((Top(s) == '(' && sign1 == ')') || (Top(s) == '[' && sign1 == ']')||
				   (Top(s) == '{' && sign1 == '}') || (Top(s) == 'b' && sign1 == 'e'))
				{
					Pop(s);
				}
				else
				{
					printf("BWrong!!!\n");
					break;
				}
			}
		}
    }

		if(Isempty(s))
			printf("You are right!\n");
		else
			printf("CWrong!!!\n");
	return 0;
}

//应该是对的了，不知道有没有问题，有时间回头再看看！