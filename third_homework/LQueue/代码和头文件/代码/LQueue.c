#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../ͷ�ļ�/LQueue.h"
#include "../ͷ�ļ�/LQueue_function.h"

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q)
{
	Node *p;
	p = (Node*)malloc(sizeof(Node));
	p->next = NULL;
	Q->front = p;
	Q->rear = p;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q)
{
	Node *p;
	while(Q->front != NULL){
		p = Q->front;
		Q->front = Q->front->next;
		free(p);
	}
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q)
{
	if(Q->front == Q->rear)
		return TRUE;
	else
		return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue *Q, void *e)
{
	if(Q->front == Q->rear)
		return FALSE;
	else{
		Node *p;
		p = Q->front->next;
		memcpy(e, p->data, Q->length);
		return TRUE;
	}
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q)
{
	Node *p;
	int cnt = 0;
	p = Q->front;
	while(p != Q->rear){
		p = p->next;
		cnt++;
	}
	return cnt;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue *Q, void *data)
{
	Node *p;
	p = (Node*)malloc(sizeof(Node));
	if(p == NULL)
		return FALSE;
	p->data = (void*)malloc(sizeof(Q->length));
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	memcpy(p->data, data, Q->length);
	return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q)
{
	if(Q->front == Q->rear)
		return FALSE;
	Node *p;
	p = Q->front->next;
	Q->front->next = p->next;
	free(p);
	return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q)
{
	Node *p, *q;
	p = q = Q->front->next;
	while (p != NULL){
		p = p->next;
		free(q);
		q = p;
	}
	Q->rear = Q->front;
}


size_t flag;
/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
{
	if(Q->length == sizeof(double))
		flag = sizeof(double);
	if(Q->length == sizeof(int))
		flag = sizeof(int);
	if(Q->length == sizeof(char))
		flag = sizeof(char);

	if(Q->front == Q->rear)
		return FALSE;
	Node *p;
	p = Q->front;
	do{
		p = p->next;
		foo(p->data);
	}while(p != Q->rear);
	printf("\n");
	return TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q

 *  @notice      : None
 */
void LPrint(void *q)
{
	if(flag == sizeof(double))
		printf("%f ",*(double*)q);
	if(flag == sizeof(int))
		printf("%d ",*(int*)q);
	if(flag == sizeof(char))
		printf("%c ",*(char*)q);
}
