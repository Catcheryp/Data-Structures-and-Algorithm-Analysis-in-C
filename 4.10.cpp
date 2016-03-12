#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode;
typedef TreeNode *Position;
typedef TreeNode *SearchTree;

struct TreeNode
{
	int Element;
	SearchTree Right;
	SearchTree Left;
};

SearchTree MakeEmpty(SearchTree T)
{
	if(T != NULL)
	{
		MakeEmpty(T->Right);
		MakeEmpty(T->Left);
		free(T);
	}
	else
		return NULL;
}

Position Find(int X, SearchTree T)
{
	if(T == NULL)
		return NULL;
	else if(X > T->Element)
		return Find(X, T->Right);
	else if(X < T->Element)
		return Find(X, T->Left);
	return T;
}

Position FindMin(SearchTree T)
{
	if(T == NULL)
		return NULL;
	else if(T->Left == NULL)
		return T;
	else
		return FindMin(T->Left);
}

Position FindMax(SearchTree T)
{
	if(T != NULL)
		while(T->Right != NULL)
			T = T->Right;
	return T;
}

SearchTree Insert(int X, SearchTree T)
{
	if(T == NULL)
	{
		T = (TreeNode *)malloc(sizeof(struct TreeNode));
		if(T == NULL)
			printf("Out of space!\n");
		else
		{
			T->Element = X;
			T->Right = T->Left = NULL;
		}
	}
	else if(X > T->Element)
	{
		T->Right = Insert(X, T->Right);
	}
	else if(X < T->Element)
	{
		T->Left = Insert(X, T->Left);
	}
	return T;
}

SearchTree Delete(int X, SearchTree T)
{
	Position temp;
	if(T == NULL)
		printf("The Element not found!\n");
	else if(X < T->Element)
		T->Left = Delete(X, T->Left);
	else if(X > T->Element)
		T->Right = Delete(X, T->Right);
	else if(T->Right && T->Left)
	{
		temp = FindMin(T->Right);
		T->Element = temp->Element;
		T->Right = Delete(T->Element, T->Right);
	}
	else
	{
		temp = T;
		if(T->Left != NULL)
		{
			T = T->Left;
		}
		else if(T->Right != NULL)
		{
			T = T->Right;
		}
		free(temp);
	}
	return T;
}

int main()
{
	SearchTree T = (TreeNode *)malloc(sizeof(struct TreeNode));
	SearchTree temp = (TreeNode *)malloc(sizeof(struct TreeNode));
	T->Left = NULL;
	T->Right = NULL;
	T->Element = 32;
	for(int i = 0; i < 20; ++i)
	{
		T = Insert(i, T);
	}
	T = Delete(32, T);
	temp = FindMax(T);
	printf("%d\n", temp->Element);
	return 0;
}