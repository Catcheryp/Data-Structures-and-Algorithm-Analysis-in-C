#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node *PtrToNode;
typedef PtrToNode stack;
typedef PtrToNode Position;

struct node
{
	char *symbol;
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

void Push(char *sign, stack s)
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

char* Top(stack s)
{
	if(!Isempty(s))
		return s->next->symbol;
	printf("Empty stack!\n");
	return 0;
}


int main()
{
	char *sign1 = (char*)malloc(sizeof(char)* 10);
	char *sign2 = (char*)malloc(sizeof(char)* 10);

	stack s = CreatStack();

	while(scanf("%s", sign1) == 1)
	{
	
		printf("7%s7\n", Top(s));

		printf("1%s1\n", sign1);

		if(Isempty(s))
		{
			if(strcmp(sign1, "(") == 0 || strcmp(sign1, "[") == 0 || strcmp(sign1, "{") == 0 || strcmp(sign1, "begin") == 0)
			{
				printf("AAAAAAAAAAA\n");
				Push(sign1, s);

				printf("3%s3\n", Top(s));
			}
			else 
			{
				printf("AWrong!!!\n");
				break;
			}
		
		}
		else
		{
			printf("6%s6\n", Top(s));
			if(strcmp(sign1, "(") == 0 || strcmp(sign1, "[") == 0 || strcmp(sign1, "{") == 0 || strcmp(sign1, "begin") == 0)
			{
				printf("BBBBBBBBBB\n");
				Push(sign1, s);
				printf("4%s4\n", Top(s));
			}
			else if(strcmp(sign1, ")") == 0 || strcmp(sign1, "]") == 0 || strcmp(sign1, "}") == 0 || strcmp(sign1, "end") == 0)
			{
				
				printf("2%s2\n", Top(s));
				
				if((strcmp(Top(s), "(") == 0 && strcmp(sign1, ")") == 0) || (strcmp(Top(s), "[") == 0 && strcmp(sign1, "]") == 0)||
				   (strcmp(Top(s), "{") == 0 && strcmp(sign1, "}") == 0) || (strcmp(Top(s), "begin") == 0 && strcmp(sign1, "end") == 0))
				{
					printf("CCCCCCCCCCCCCCCC\n");
					Pop(s);
				}
				else
				{
					printf("BWrong!!!\n");
					printf("5%s5\n", Top(s));
					break;
				}
			}
		}
    }

		if(Isempty(s))
			printf("You are right!\n");
		else
			printf("CWrong!!!\n");
		while(!Isempty(s))
		{
			printf("%s\n", Top(s));
			Pop(s);
		}
	return 0;
}

//这道题感觉只能曲线救国了，一开始是动态内存分配问题，后来是指针的绑定问题
//所以最终我决定从新来写改变节点的结构