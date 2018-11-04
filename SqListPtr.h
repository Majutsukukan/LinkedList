#pragma once


#define ElemType int
#include <stdbool.h>
typedef enum Status {
	success, fail, fatal, range_error
}Status;
typedef struct Node
{
	ElemType elem;
	struct Node *next;

}Node, *Ptr; typedef Ptr *SqListPtr;
Status List_Init(SqListPtr L);
void List_Destoy(SqListPtr L);
void List_Clear(SqListPtr L);
bool List_Empty(SqListPtr L);
int List_Size(SqListPtr L);
Status List_Retrival(SqListPtr L, int Pos, ElemType *elem);
Status List_Locate(SqListPtr L, ElemType elem, int *Pos);
Status List_Insert(SqListPtr L, ElemType elem, int Pos);
Status List_Delete(SqListPtr L, int Pos);
Status List_Prior(SqListPtr L, int Pos, ElemType *elem);
Status List_Next(SqListPtr L, int Pos, ElemType *elem);
void List_Print(SqListPtr L);
