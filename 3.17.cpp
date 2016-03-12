#include <stdio.h>
#include <stdlib.h>

typedef struct node *PtrToNode;
typedef PtrToNode Position;
typedef PtrToNode List;

typedef struct head *PtrToHead;
typedef PtrToHead Head;

struct head
{
	int holdnum;
	int cancelnum;
	Position next;
};

struct node
{
	int item;
	int flag;
	Position next;
};

Position FindPrevious(int x, List L)
{
	Position p;
	p = L;
	while(p->next != NULL && p->next->item != x)
		p = p->next;
	return p;
}

Position Find(int x, List L)
{
	Position p;
	p = L;
	while(p->next != NULL && p->item != x)
		p = p->next;
	return p;
}

void Insert(int x, Position p)
{
	Position temp = (node *)malloc(sizeof(struct node));
	if(temp == NULL)
		printf("Out of space!\n");
	temp->item = x;
	temp->flag = 1;
	temp->next = p->next;
	p->next = temp;
}

Position Delete(int x, List L)
{
	Position pre, cur;
	pre = FindPrevious(x, L);
	cur = pre->next;
	if(pre->next != NULL)
	{
		pre->next = cur->next;
		free(cur);
	}
	return pre->next;
}

void LazyDelete(int x, List L, Head hea)
{
	Position p = Find(x, L);
	Position temp = L;
	p->flag = 0;
	hea->holdnum--;
	hea->cancelnum++;
	if(hea->holdnum == hea->cancelnum)
	{
		while(temp->next != NULL)
		{
			if(temp->flag == 0)
			{
				temp = Delete(temp->item, L);
			}
			else
				temp = temp->next;
		}
	}
}

int main()
{
	List L = (node *)malloc(sizeof(struct node));
	Head hea = (head *)malloc(sizeof(struct head));
	hea->holdnum = 10;
	hea->cancelnum = 0;
	hea->next = L;
	L->next = NULL;
	L->item = 0;
	L->flag = 1;
	for(int i = 1; i < 10; ++i)
	{
		Insert(i, L);
	}
	LazyDelete(5, L, hea);
	LazyDelete(6, L, hea);
	LazyDelete(7, L, hea);
	LazyDelete(8, L, hea);
	LazyDelete(9, L, hea);
	while(L != NULL)
	{
		printf("%d %d\n", L->item, L->flag);
		L = L->next;
	}
	printf("%d     %d\n", hea->holdnum, hea->cancelnum);
	return 0;
}