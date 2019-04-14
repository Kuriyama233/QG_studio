#include <stdio.h>
#include <stdlib.h>
#include "../inc/qgsort.h"
#include "../inc/SqStack.h"
//˳��ջ(���������)
Status initStack(SqStack *s,int sizes)  //��ʼ��ջ
{
	s-> elem = (int*)malloc(sizes * sizeof(int));
	if (s-> elem == NULL)
		return ERROR;
	s-> top = -1;
	s-> size = sizes;
	return SUCCESS;
}

Status isEmptyStack(SqStack *s)   //�ж�ջ�Ƿ�Ϊ��
{
	if (s-> top == -1)
		return SUCCESS;
	else
		return ERROR;
}

Status getTopStack(SqStack *s,int *e)   //�õ�ջ��Ԫ��
{
	if (s-> top == -1)
		return ERROR;
	*e = s-> elem[s-> top];
	return SUCCESS;
}

Status clearStack(SqStack *s)   //���ջ
{
	if (s == NULL)
		return ERROR;
	for (int i=0; i<s-> top; i++)
		s-> elem[i] = 0;
	s-> top = -1;
	return SUCCESS;
}

Status destroyStack(SqStack *s)  //����ջ
{
	if (s == NULL)
		return ERROR;
	free(s->elem);
	return SUCCESS;
}

Status stackLength(SqStack *s,int *length)   //���ջ����
{
	if (s == NULL)
		return ERROR;
	*length = s-> top+1;
	return SUCCESS;
}

Status pushStack(SqStack *s,int data)  //��ջ
{
	if (s == NULL || s-> top == s-> size - 1)
		return ERROR;
	s-> top++;
	s-> elem[s-> top] = data;
	return SUCCESS;
}

Status popStack(SqStack *s)   //��ջ
{
	if (s == NULL || s->top == -1)
		return ERROR;
	s-> top--;
	return SUCCESS;
}


