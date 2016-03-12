#include <stdio.h>
#include <stdlib.h>

#define MaxDegree 1000
struct PolyNode
{
	int CoeffArray[MaxDegree + 1];
	int HighPower;
};
typedef struct PolyNode *Polynomial;

void ZeroPolynomial(Polynomial Poly)
{
	int i;

	for(i = 0;i <= MaxDegree;i++)
		Poly->CoeffArray[i] = 0;
	Poly->HighPower = 0;
}

int Max(int x,int y)
{
	if(x >= y)
		return x;
	else
		return y;
}

void AddPolynomial(const Polynomial Poly1,const Polynomial Poly2,Polynomial PolySum)
{
	int i;

	ZeroPolynomial(PolySum);
	PolySum->HighPower = Max(Poly1->HighPower,Poly2->HighPower);

	for(i = PolySum->HighPower;i >= 0;i--)
		PolySum->CoeffArray[i] = Poly1->CoeffArray[i] + Poly2->CoeffArray[i];
}

int main()
{
	int i;

	Polynomial Poly1,Poly2,PolySum;
	Poly1 = malloc(sizeof(struct PolyNode));
	Poly2 = malloc(sizeof(struct PolyNode));
	PolySum = malloc(sizeof(struct PolyNode));

	scanf("%d",&Poly1->HighPower);
	for(i = Poly1->HighPower;i >= 0;i--)
	{
		scanf("%d",&Poly1->CoeffArray[i]);
	}
	scanf("%d",&Poly2->HighPower);
	for(i = Poly2->HighPower;i >= 0;i--)
	{
		scanf("%d",&Poly2->CoeffArray[i]);
	}
	AddPolynomial(Poly1,Poly2,PolySum);
	printf("%d\n",PolySum->HighPower);
	for(i = PolySum->HighPower;i >= 0;i--){
		printf("%d ",PolySum->CoeffArray[i]);
	}
	return 0;
}