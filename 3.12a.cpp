#include <stdio.h>
#include <stdlib.h>

typedef struct node *PtrToNode;
typedef PtrToNode Position;
typedef PtrToNode List;

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

Position reverse(List head)
{
	Position cur = head->next;
	head->next = NULL;
	while(cur != NULL)
	{
		Position temp = cur->next;
		cur->next = head;
		head = cur;
		cur = temp;
	}
	return head;
}

int main()
{
	Position head;
	Position L;
	head = (node *)malloc(sizeof(struct node));
	L = head;
	head->next = NULL;
	head->item = -1;
	for(int i = 4; i < 10; ++i)
	{
		Insert(i, L);
	}
	while(L != NULL)
	{
		printf("%d ", L->item);
		L = L->next;
	}
	printf("\n");
	L = head;
	Position root = reverse(L);
	while(root != NULL)
	{
		printf("%d ", root->item);
		root = root->next;
	}
	return 0;
}