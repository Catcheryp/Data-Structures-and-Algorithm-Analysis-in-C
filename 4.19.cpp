//先把书上的avl插入函数手打一遍
AvlTree Insert(ElementType X, AvlTree T)
{
	if(T == NULL)
	{
		T = (AvlTree*)malloc(sizeof(struct AvlTree));
		if(T == NULL)
			printf("Out of space!\n");
		else
		{
			T->Height = 0;
			T->Right = NULL;
			T->Left = NULL;
			T->Element = X;
		}
	}
	else if(X < T->Element)
	{
		T->Left = Insert(X, T->Left);
		if(Height(T->Left) - Height(T->Right) == 2)
			if(X < T->Left->Element)
				SingleRotateWithLeft(T->Left);
			else
				DoubleRotateWithLeft(T->Left);
	}
	else if(X > T->Element)
	{
		T->Right = Insert(X, T->Right);
		if(Height(T->Right) - Height(T->Left) == 2)
			if(X > T->Right->Element)
				SingleRotateWithRight(T->Right);
			else
				DoubleRotateWithRight(T->Right);
	}

	T->Height = Max(Height(T->Left), Height(T->Right)) + 1;

	return T;
}

//讲真，我感觉这里并没有用什么递归，难道是
//T->Left = Insert(X, T->Left);那我就改成这样不就好了：

/*Position temp;
temp = T;
if(T == NULL)
	return NULL:
while(1)
{
	if(X < T->Element && T->Left != NULL)
		T = T->Left;
	else if(X < T->Element && T->Left == NULL)
	{
		T->Left->Element = X;
		break;
	}	
	else if(X > T->Element && T->Right != NULL)
		T = T->Right;
	else
	{
		T->Right->Element = X;
		break;
	}
	return temp;
}*/
