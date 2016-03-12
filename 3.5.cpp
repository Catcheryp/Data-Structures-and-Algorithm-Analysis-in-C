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

List Union(List L1,List L2)
{
	List Result;
	Position L1Pos,L2Pos,ResultPos,ResultHead;

	L1Pos = First(L1);L2Pos = First(L2);
	Result = MakeEmpty(Result);
	//ResultPos = First(Result);
	ResultHead = Result;

	while(L1Pos != NULL && L2Pos != NULL)
	{
		if(L1Pos->Element < L2Pos->Element)
		{
			Insert(L1Pos->Element,Result,Result);
			L1Pos = L1Pos->Next;
			Result = Result->Next;
		}
		else if(L1Pos->Element > L2Pos->Element)
		{
			Insert(L2Pos->Element,Result,Result);
			L2Pos = L2Pos->Next;
			Result = Result->Next;
		}
		else
		{
			Insert(L1Pos->Element,Result,Result);
			L1Pos = L1Pos->Next;L2Pos = L2Pos->Next;
			Result = Result->Next;
		}
	}
	while(L1Pos != NULL)
	{
		Insert(L1Pos->Element,Result,Result);
		L1Pos = L1Pos->Next;
		Result = Result->Next;
	}
	while(L2Pos != NULL)
	{
		Insert(L2Pos->Element,Result,Result);
		L2Pos = L2Pos->Next;
		Result = Result->Next;
	}
	return ResultHead;
}

int main()
{
	int n,i,j;
	List L1,L2,ResultHead;
	Position L1Head,L2Head;
	L1 = MakeEmpty(L1);
	L2 = MakeEmpty(L2);
	L1Head = L1;
	L2Head = L2;
	for(i = 1;i <= 1000;++i)
	{
		Insert(i,L1,L1);
		if(L1->Next != NULL)
			L1 = L1->Next;
	}
	for(j = 1;j < 2000;j = 2 * j + 1)
	{
		Insert(j,L2,L2);
		if(L2->Next != NULL)
			L2 = L2->Next;
	}
	
	ResultHead = Union(L1Head,L2Head);

	while(ResultHead->Next != NULL)
	{
		ResultHead = ResultHead->Next;
		printf("%d ",ResultHead->Element);
	}

	return 0;
}
