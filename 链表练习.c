#include<stdio.h>
#include<stdlib.h>
#include"SqListPtr.h"//L是指向指针的指针
Status List_Init(SqListPtr L) {
	Ptr p; Status s = fail;
	if (*L==NULL)
	{
		p = (Ptr)malloc(sizeof(Node));
		if (p != NULL) {
			s = success; *L = p; (*L)->next = NULL;
		}

	}return s;
}
void List_Destoy(SqListPtr L) {
	Ptr p;
	if (*L) {
		p = (*L)->next;
		while (p) {
			(*L)->next = p->next; free(p); p->next = (*L)->next;
		}free(*L); *L = NULL;
	}
}
void List_Clear(SqListPtr L) {
	Ptr p;
	if (*L) {
		p = (*L)->next;
		while (p) {
			(*L)->next = p->next; free(p); p->next = (*L)->next;
		}
	}
}

bool List_Empty(SqListPtr L) {
	return ((*L)->next == NULL);

}
int List_Size(SqListPtr L) {
	int len = 0;
	Ptr p = (*L)->next;
	while (p)
	{
		len++; p = p->next;
	}return len;
}
Status List_Retrival(SqListPtr L, int Pos, ElemType *elem) {
	Status s = range_error;
	int i = 0; Ptr p = (*L)->next;
	if (*L)
	{
		while (p&&i<Pos)
		{
			++i;
			p = p->next;
		}if (p&&i == Pos) {
			*elem = p->elem; s = success;
		}
	}return s;
}
Status List_Locate(SqListPtr L, ElemType elem, int *Pos) {
	Status s = range_error; Ptr p = (*L)->next; int i = 1; while (p)
	{
		if (p->elem==elem)
		{
			*Pos = i;
			s = success; break;
		}i++; p = p->next;
	}if (p==NULL)
	{
		s = fail;
	}return s;
}
Status List_Insert(SqListPtr L, ElemType elem, int Pos) {
	Status s = fail; int i = 1; Ptr p = (*L)->next,q = (*L); while (i<=Pos-1&&p)
	{
		q = p; p = p->next; ++i;

	}if (i=Pos-1)
	{
		p = (Ptr)malloc(sizeof(Node));
		if (p) {
			p->elem = elem; p->next = q->next; q->next = p; s = success;
		}
	}return s;
}
Status List_Find(SqListPtr L, int Pos, Ptr pAddr)
{
	Status s = fail; int i = 1; Ptr p = (*L)->next, q = (*L); while (i <= Pos - 1 && p)
	{
		q = p; p = p->next; ++i;

	}if (i == Pos && p)
	{
		pAddr = p; s = success;
		;
	}return s;
}  //查找pos位置的元素并返回地址到PAddr中
Status List_Delete(SqListPtr L, int Pos)//P是待删除的节点，q是p的直接前驱
{
	Status s = fail; Ptr p = (*L)->next, q = (*L); int i = 1; while (i < Pos  && p) {
		++i; q = p; p = p->next;
	}//使用函数版本 s=List_Find(L,Pos-1,q);if (s==success){p=q->next;if(p){q->next = p->next; free(p); p = NULL;
	if (i==Pos&&p)
	{
		q->next = p->next; free(p); p = NULL;
	}
	return s;
}
Status List_Prior(SqListPtr L, int Pos, ElemType *elem) {
	Status s = fail;
	Ptr q=(*L); s = List_Find(L, Pos - 1, q); if (s==success)
	{
		*elem = q->elem; s = success;
	}return s;
}
Status List_Next(SqListPtr L, int Pos, ElemType *elem) {
	Status s = fail;
	Ptr  q=(*L); s = List_Find(L, Pos, q);if (s==success)
	{
		if (q->next)
		{
			*elem = q->elem; s = success;
		}
		else
		{
			s = range_error;
		}
	}return s;
}
void List_Print(SqListPtr L) {
	Ptr p = (*L)->next; int i = 1; while (p)
	{
		printf("%d", p->elem);
		p = p->next;
		i++;
	}
}
int main() {

}
