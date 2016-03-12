#include <stdio.h>
#include <stdlib.h>

#define Maxsize  20
typedef struct node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

struct node
{
	int data[Maxsize];
	int length;
};

Position Find(int m, List L)
{
	int where = 0;
	for(int i = 0; i < L->length; ++i)
	{
		if(m == L->data[i])
		{
			where = i;
			break;
		}
	}
	if(where)
	{
		for(int j = where; j > 0; --j)
			L->data[j] = L->data[j - 1];
		L->data[0] = m;
	}
	else
		return NULL;
	return L;
}

int main()
{
	List L;
	int j = 0;
	int m;
	scanf("%d", &m);
	L = (node *)malloc(sizeof(struct node));
	L->length = 16;
	for(int i = 0; i <= 15; ++i)
	{
		L->data[i] = i;
	}
	Position temp = Find(m, L);
	if(temp != NULL)
	{
		while(temp->length--)
		{
			printf("%d\n", temp->data[j]);
			j++;
		}
	}
	else
	{
		printf("This List don't have this element!!!\n");
	}
	return 0;
}