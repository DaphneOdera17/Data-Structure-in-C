#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"
#include <stdio.h>
#include <stdlib.h>

struct Node {
	ElementType Element;
	Position Next;
};

/* Return true if list is empty */
int IsEmpty( List L ) {
	return L->Next == NULL;
}

/* Return true is position p is the end of the list */
int IsLast( Position P, List L ) {
	return P->Next == NULL;
}

/* Return position of X in the list, if not found, return NULL */
Position Find(ElementType X, List L) {
	Position P = L->Next;

	while (P != NULL && P->Element != X) { /* If P is not empty and the element of P is not equal to X */
		P = P->Next;
	}

	return P;
}

/* Return the previous Node of X */
Position FindPrevious(ElementType X, List L) {
	Position P = L;

	while (P->Next != NULL && P->Next->Element != X) {
		P = P->Next;
	}
	
	return P;
}

/* Delete the first occurence of X from the list */
void Delete(ElementType X, List L) {
	Position P, Temp;
	P = FindPrevious( X, L );

	if (!IsLast(P, L)) {
		Temp = P->Next;
		P->Next = Temp->Next;
		free(Temp);
	}
}

void Insert(ElementType X, List L, Position P) {
	if (!IsLast(P, L)) {
		
		Position Temp;
		Temp = (Position)malloc(sizeof(struct Node));

		if (Temp == NULL) puts("OUT OF SPACE!");
		else {
			Temp->Element = X;
			Temp->Next = P->Next;
			P->Next = Temp;
		}
	}
}

void DeleteList(List L)
{
	Position P, Tmp;

	P = L->Next;
	L->Next = NULL;

	while (P != NULL)
	{
		Tmp = P->Next;
		free(P);
		P = Tmp;
	}
}