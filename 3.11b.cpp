#include <stdio.h>
#include <stdlib.h>

typedef struct node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

struct node
{
	int item;
	Position next;
};

void Insert(int x, Position p)
{
	Position temp;
	temp = (node *)malloc(sizeof(struct node));
	if(temp == NULL)
		printf("Out of space!\n");
	temp->item = x;
	temp->next = p->next;
	p->next = temp;
}

Position Find(int m, List head)
{
	Position p;
	p = head->next;
	if(p == NULL || p->item == m)
		return p;
	return Find(m, p);//有人给出的是Find(m, p->next),我是觉得应该是p
}

int main()
{
	Position head;
	Position temp;
	List L;
	head = (node *)malloc(sizeof(struct node));
	L = head;
	head->next = NULL;
	int m;
	scanf("%d", &m);
	head->item = -1;
	for(int i = 0; i < 100; ++i)
	{
		Insert(i, L);
	}
	temp = Find(m, L);
	if(temp != NULL)
	{
		printf("We find this element!\n");
	}
	else
	{
		printf("We don't find this element!\n");
	}
	return 0;
}