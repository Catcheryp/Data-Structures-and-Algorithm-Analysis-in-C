//画个图，一步一步来，一点也不难

Position DubleRotateWithLeft(Position K3)
{
	Position K1;
	Position K2;

	K1 = K3->Left;
	K2 = K1->Right;

	K1->Right = K2->Left;
	K3->Left = K2->Right;

	K2->Left = K1;
	K2->Right = K3;

	K1->Height = Max(Height(K1->Right), Height(K1->Left)) + 1;
	K3->Height = Max(Height(K3->Right), Height(K3->Left)) + 1;

	K2->Height = Max(Height(K2->Right), Height(K2->Left)) + 1;

	return K2;//这里答案是K3，我觉得答案错了
}
 


Position DubleRotateWithRight(Position K3)
{
	Position K1;
	Position K2;

	K1 = K3->Right;
	K2 = K1->Left;

	K1->Left = K2->Right;
	K3->Right = K2->Left;

	K2->Right = K1;
	K2->Left = K3;

	K1->Height = Max(Height(K1->Right), Height(K1->Left)) + 1;
	K3->Height = Max(Height(K3->Right), Height(K3->Left)) + 1;

	K2->Height = Max(Height(K2->Right), Height(K2->Left)) + 1;

	return K2;
}
