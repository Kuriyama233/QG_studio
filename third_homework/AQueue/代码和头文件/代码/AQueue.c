#include "../头文件/AQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include "../头文件/function_AQueue.h"
#include <string.h>
/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitAQueue(AQueue *Q)
{
	for(int i=0; i<MAXQUEUE; i++)			//为每一个下标申请空间
		Q->data[i] = (void*)malloc(Q->length);
	Q->front = 0;							//队头队尾指向0
	Q->rear = 0;
}


/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q)
{
	for(int i=0; i<MAXQUEUE; i++)			//free掉
		free(Q->data[i]);
	Q->front = Q->rear = 0;
}


/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : 检查队列是否已满
 *    @param         Q 队列指针Q
 *    @return         : 满-TRUE; 未满-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q)
{
	if ((Q->rear+1)%MAXQUEUE == Q->front)		//判断下一个元素是否为front所指元素
		return TRUE;
	else
		return FALSE;
}


/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q)
{
	if (Q->front == Q->rear)					//只有在空时front和rear指向0
		return TRUE;
	else
		return FALSE;
}


/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q 队列指针Q，存放元素e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadAQueue(AQueue *Q, void *e)
{
	if (Q->front == Q->rear)
		return FALSE;
	else{								//将队头元素memcpy到e上
		memcpy(e, Q->data[(Q->front+1)%MAXQUEUE], Q->length);
		return TRUE;
	}
}


/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 队列长度count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q)
{
	return (Q->rear - Q->front + MAXQUEUE) % MAXQUEUE;
}


/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否满了或为空
 */
Status EnAQueue(AQueue *Q, void *data)
{
	if((Q->rear+1)%MAXQUEUE == Q->front){			//判断IsEmptyAQueue
		return FALSE;
	}
	else{
		Q->rear = (Q->rear + 1) % MAXQUEUE;			//rear后移
		memcpy(Q->data[Q->rear], data, Q->length);		//将data  mencpy到rear所指的空间
		return TRUE;
	}
}


/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q)
{
	if(Q->front == Q->rear)
		return FALSE;
	else{
		Q->front = (Q->front + 1) % MAXQUEUE;		//front后移
		return TRUE;
	}
}


/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q)
{
	Q->front = 0;
	Q->rear = 0;
}

int flag;				//用全局变量flag导入Q->length所指数据类型
/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
{
	if (Q->length == sizeof(double))
		flag = sizeof(double);
	if (Q->length == sizeof(int))
		flag = sizeof(int);
	if (Q->length == sizeof(char))
		flag = sizeof(char);

	if(Q->front == Q->rear)
		return FALSE;
	else{
		int i = Q->front + 1;				//遍历打印数据
		while(i <= (Q->rear - Q->front + MAXQUEUE) % MAXQUEUE){
			foo(Q->data[i]);
			i = (i + 1) % MAXQUEUE;			//i，即front+1后移
		}
		printf("\n");
		return TRUE;
	}
}


/**
 *  @name        : void APrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 *  @notice      : None
 */

void APrint(void *q)
{
	if (flag == sizeof(double))
		printf("%lf ", *(double *)q);
	else if (flag == sizeof(int))
		printf("%d ", *(int *)q);
	else if (flag == sizeof(char))
		printf("%c ", *(char *)q);
}



