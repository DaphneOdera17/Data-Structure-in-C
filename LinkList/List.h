#pragma once
#ifndef _List_H_

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;

List MakeEmpty( List L );
int IsEmpty( List L );
int IsLast( Position P, List L );
Position Find( ElementType X, List L );
void Delete( ElementType X, List L );
Position FindPrevious(ElementType X, List L); /* 返回表头的位置 */
void Insert(ElementType X, List L, Position P);
void DeleteList( List L );
Position Header( List L );
Position First( List L );
Position Advance(Position P);

#endif