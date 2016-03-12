#include <stdio.h>
#include <stdlib.h>

typedef struct node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
struct node
{
	int item;
	PtrToNode next;
};

void Insert(int x, Position p)
{
	Position temp;
	temp = (struct node*)malloc(sizeof(struct node));
	if(temp == NULL)
		printf("Out of space!\n");
	temp->item = x;
	temp->next = p->next;
	p->next = temp;
}

int main()
{
	List L;
	Position head;
	head = (struct node*)malloc(sizeof(struct node));
	head->next = NULL;
	L = head;
	int find;
	scanf("%d", &find);
	head->item = -1;
	for(int i = 0; i < 100; ++i)
	{
		Insert(i, head);
	}
	
	while(find != L->item)
	{
		if(L->next == NULL)
		{
			printf("This list don't have this element!!!\n");
			goto x;
		}
		L = L->next;
	}
	printf("This list have this element!!!\n");
	x:
	return 0;
}