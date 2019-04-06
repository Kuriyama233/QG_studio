#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../头文件/LQueue.h"
#include "../头文件/LQueue_function.h"

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
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
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
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
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
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
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
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
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
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
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
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
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
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
 *    @description : 清空队列
 *    @param         Q 队列指针Q
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
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
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
 *    @description : 操作函数
 *    @param         q 指针q

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
