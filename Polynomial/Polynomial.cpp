#define _CRT_SECURE_NO_WARNINGS 1
#include "Polynomial.h"
#include <stdio.h>

typedef struct
{
	int CoeffArray[MaxDegree + 1];
	int HighPower;
} * Polynomial;

int Max(int x, int y)
{
	if (x > y)
		return x;
	else
		return y;
}

/* 初始化多项式为 0 */
void ZeroPolynomial(Polynomial Poly)
{
	for (int i = 0; i <= MaxDegree; i++)
		Poly->CoeffArray[i] = 0;
	Poly->HighPower = 0;
}

void AddPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolySum)
{
	ZeroPolynomial(PolySum);

	PolySum->HighPower = Max(Poly1->HighPower, Poly2->HighPower);

	for (int i = PolySum->HighPower; i; i--)
		PolySum->CoeffArray[i] = Poly1->CoeffArray[i] + Poly2->CoeffArray[i];
}

void MultPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolyProd)
{
	ZeroPolynomial(PolyProd);
	PolyProd->HighPower = Poly1->HighPower + Poly2->HighPower;

	if (PolyProd->HighPower > MaxDegree)
		puts("Exceed array size");
	else
	{
		for (int i = 0; i <= Poly1->HighPower; i++)
		{
			for (int j = 0; j <= Poly2->HighPower; j++)
			{
				PolyProd->CoeffArray[i + j] += Poly1->CoeffArray[i] * Poly2->CoeffArray[j];
			}
		}
	}
}