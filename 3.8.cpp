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

Polynomial MultPolynomial(Polynomial Poly1,Polynomial Poly2)
{
	int i,j;

	Polynomial PolyProd;
	PolyProd = malloc(sizeof(struct PolyNode));

	ZeroPolynomial(PolyProd);
	PolyProd->HighPower = Poly1->HighPower + Poly2->HighPower;

	if(PolyProd->HighPower > MaxDegree)
		printf("Exceeded array size\n");
	else
		for(i = 0;i <= Poly1->HighPower;i++)
			for(j = 0;j <= Poly2->HighPower;j++)
				PolyProd->CoeffArray[i + j] += Poly1->CoeffArray[i] * Poly2->CoeffArray[j];


	return PolyProd;
}

int IsEven(int x)
{
	if(x % 2 == 0)
		return 1;
	else 
		return NULL;
}

Polynomial Pow(Polynomial Poly,int P)
{
	if(P == 0)
	{
		Poly->HighPower = 0;
		Poly->CoeffArray[0] = 1;
		return Poly;
	}
	if(P == 1)
	{
		return Poly;
	}
	if(IsEven(P))
	{
		return Pow(MultPolynomial(Poly,Poly),P / 2);
	}
	else
	{
		return MultPolynomial(Pow(MultPolynomial(Poly,Poly),P / 2),Poly);
	}
}


int main()
{
	int i,P;

	Polynomial Poly;
	Poly = malloc(sizeof(struct PolyNode));

	scanf("%d",&Poly->HighPower);
	for(i = Poly->HighPower;i >= 0;i--)
	{
		scanf("%d",&Poly->CoeffArray[i]);
	}
	scanf("%d",&P);

	Poly = Pow(Poly,P);
	for(i = Poly->HighPower;i >= 0;i--)
	{
		printf("%d ",Poly->CoeffArray[i]);
	}
	return 0;
}
