//不要强行记忆，画个图很好理解，更容易记忆

static Position SingleRotateWithLeft(Position K2)
{
	Position  K1;
	K1 = K2->Left;
	K2->Left = K1->Right;
	K1->Right = K2;

	K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
	K1->Height = Max(Height(K1->Left), Height(K1->Right)) + 1;

	return K1;
}

static Position SingleRotateWithRight(Position K2)
{
	Position K1;
	K1 = K2->Right;
	K2->Right = K1->Left;
	K1->Left = K2;

	K1->Height = Max(Height(K1->Left), Height(K1->Right)) + 1;
	K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;

	return K1;
}

static Position DoubleRotateWithLeft(Position K3)                       
{
	K3->Left = SingleRotateWithRight(K3->Left);

	return SingleRotateWithLeft(K3);
}

static Position DoubleRotateWithRight(Position K3)
{
	K3->Right = SingleRotateWithLeft(K3->Right);

	return SingleRotateWithRight(K3);
}
