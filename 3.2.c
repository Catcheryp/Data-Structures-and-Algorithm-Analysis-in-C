#include <stdio.h>
#include <stdlib.h>

#define ElementType int
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(List L);
Position Find(ElementType X,List L);
void Delete(ElementType X,List L);
Position FindPrevious(ElementType X,List L);
void Insert(ElementType X,List L,Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);

struct Node
{
	ElementType Element;
	Position Next;
};

int IsEmpty(List L)
{
	return L->Next == NULL;
}

int IsLast(Position P,List L)
{
	return P->Next == NULL;
}

Position Find(ElementType X,List L)
{
	Position P;

	P = L->Next;
	while(P != NULL && P->Element != X)
		P = P->Next;
	return P;
}

Position FindPrevious(ElementType X,List L)
{
	Position P;

	P =  L;
	while(P->Next != NULL && P->Next->Element != X)
		P = P->Next;

	return P;
}

void Delete(ElementType X,List L)
{
	Position P,TmpCell;
	P = FindPrevious(X,L);
	if(!IsLast(P,L))
	{
		TmpCell = P->Next;
		P->Next = TmpCell->Next;
		free(TmpCell);
	}
}

void Insert(ElementType X,List L,Position P)
{
	Position TmpCell;

	TmpCell = malloc(sizeof(struct Node));
	if(TmpCell == NULL)
		printf("Out of space!\n");

	TmpCell->Element = X;
	TmpCell->Next = P->Next;
	P->Next = TmpCell;
}

void DeleteList(List L)
{
	Position P,Tmp;

	P = L->Next;
	L->Next = NULL;
	while(P != NULL)
	{
		Tmp = P->Next;
		free(P);
		P = Tmp;
	}
}

List MakeEmpty(List L)
{	/*if(L != NULL)
		DeleteList(L);
	L = malloc(sizeof(struct Node));
	if(L == NULL)
		printf("Out of space!\n");
	L->Next = NULL;
	*/
	if(!(L = malloc(sizeof(struct Node))))//分配空间 
  		exit(EXIT_FAILURE);
 	L->Next = NULL;

	return L;
}


Position Header(List L)
{
	return L;
}

Position First(List L)
{
	return L->Next;
}

Position Advance(Position P)
{
	return P->Next;
}

ElementType Retrieve(Position P)
{
	return P->Element;
}

void PrintLots(List L,List P)
{
	int Counter;
	Position Lpos,Ppos;

	Lpos = First(L);
	Ppos = First(P);
	Counter = 1;
	while(Lpos != NULL && Ppos != NULL)
	{
		if (Ppos->Element == Counter++)
		{
			printf("%d ",Lpos->Element);
			//Ppos = Next(Ppos,P);
			Ppos = Ppos->Next;
		}
		//Lpos = Next(Lpos,L);
		Lpos = Lpos->Next;
	}
}


int main()
{
	int n,i,j;
	List L,P;
	Position lHead,pHead;
	L = MakeEmpty(L);
	P = MakeEmpty(P);
	lHead = L;
	pHead = P;
	scanf("%d",&n);
	for(i = 1;i <= n;++i)
	{
		Insert(i,L,L);
		if(L->Next != NULL)
			L = L->Next;
	}
	for(j = 1;j < 100;j = 2 * j)
	{
		Insert(j,P,P);
		if(P->Next != NULL)
			P = P->Next;
	}
	PrintLots(lHead,pHead);
	return 0;
}