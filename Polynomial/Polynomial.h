#pragma once
#ifndef _POLYNOMIAL_H

#define MaxDegree 100

int Max(int x, int y);
void ZeroPolynomial(Polynomial Poly);
void AddPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolySum);
void MultPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolyProd);

#endif