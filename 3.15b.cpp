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
	Position temp = (node *)malloc(sizeof(struct node));
	if(temp == NULL)
		printf("Out of space!\n");
	temp->item = x;
	temp->next = p->next;
	p->next = temp;
}

Position FindPrevious(int x, List L)
{
	Position temp;
	temp = L;
	while(temp->next != NULL && temp->next->item != x)
		temp = temp->next;
	return temp;
}

Position Find(int x, List L)
{
	Position pre = FindPrevious(x, L);
	Position cur;
	if(pre->next != NULL)
	{
		cur = pre->next;
		pre->next = cur->next;
		cur->next = L;
		return cur;
	}
	else
		return NULL;
}
int main()
{
	Position head = (node *)malloc(sizeof(struct node));
	head->next = NULL;
	List L = head;
	head->item = -1;
	for(int i = 0; i < 20; ++i)
	{
		Insert(i, head);
	}
	while(head != NULL)
	{
		printf("%d ", head->item);
		head = head->next;
	}
	printf("\n");
	int m;
	scanf("%d", &m);
	Position cur = Find(m, L);
	while(cur != NULL)
	{
		printf("%d ", cur->item);
		cur = cur->next;
	}
	if(cur == NULL)
	{
		printf("This list don't have this element!\n");
	}
	return 0;
}