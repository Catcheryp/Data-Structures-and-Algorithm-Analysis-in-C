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

void MultPolynomial(const Polynomial Poly1,const Polynomial Poly2,Polynomial PolyProd)
{
	int i,j;

	ZeroPolynomial(PolyProd);
	PolyProd->HighPower = Poly1->HighPower + Poly2->HighPower;

	if(PolyProd->HighPower > MaxDegree)
		printf("Exceeded array size\n");
	else
		for(i = 0;i <= Poly1->HighPower;i++)
			for(j = 0;j <= Poly2->HighPower;j++)
				PolyProd->CoeffArray[i + j] += Poly1->CoeffArray[i] * Poly2->CoeffArray[j];
}

int main()
{
	int i;

	Polynomial Poly1,Poly2,PolyProd;
	Poly1 = malloc(sizeof(struct PolyNode));
	Poly2 = malloc(sizeof(struct PolyNode));
	PolyProd = malloc(sizeof(struct PolyNode));

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
	MultPolynomial(Poly1,Poly2,PolyProd);
	printf("%d\n",PolyProd->HighPower);
	for(i = PolyProd->HighPower;i >= 0;i--){
		printf("%d ",PolyProd->CoeffArray[i]);
	}
	return 0;
}