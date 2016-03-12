#include <stdio.h>
#include <stdlib.h>

#define Maxsize 50

typedef struct node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

struct node
{
	int data[Maxsize];
	int length;
};

void Insert(int m, List L)
{
	L->data[L->length] = m;
	L->length++;
}

void Delete(int i, List L)
{
	for(int k = i; k < L->length; ++k)
	{
		L->data[k - 1] = L->data[k];
	}
	L->length--;
}

int main()
{
	List L = (node *)malloc(sizeof(struct node));
	L->length = 0;
	for(int i = 0; i < 10; ++i)
	{
		Insert(8, L);
	}
	for(int j = 11; j < 16; ++j)
	{
		Insert(j, L);
	}
	//AAAAAAAAAAAAAAAAA
	Insert(9, L);
	Insert(8, L);
	Insert(9, L);
	Insert(7, L);
	Insert(9, L);
	Insert(7, L);
	Insert(9, L);
	Insert(5, L);
	Insert(3, L);
	Insert(12, L);
	Insert(9, L);
	Insert(11, L);
	//AAAAAAAAAAAAAAAAAA

	int m = 0,len = L->length;
	while(len--)
	{
		printf("%d ", L->data[m]);
		m++;
	}
	printf("\n");
	for(int l = 0; l < L->length; ++l)
	{
		int temp = l + 1;
		while(temp < L->length)
		{
			if(L->data[l] == L->data[temp])
			{
				Delete(temp + 1, L);
			}
			else
				temp++;
		}
	}
	int k = 0;
	len = L->length;
	while(len--)
	{
		printf("%d ", L->data[k]);
		k++;
	}
	return 0;
}