#include "../ͷ�ļ�/AQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include "../ͷ�ļ�/function_AQueue.h"
#include <string.h>
/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitAQueue(AQueue *Q)
{
	for(int i=0; i<MAXQUEUE; i++)			//Ϊÿһ���±�����ռ�
		Q->data[i] = (void*)malloc(Q->length);
	Q->front = 0;							//��ͷ��βָ��0
	Q->rear = 0;
}


/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q)
{
	for(int i=0; i<MAXQUEUE; i++)			//free��
		free(Q->data[i]);
	Q->front = Q->rear = 0;
}


/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : �������Ƿ�����
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q)
{
	if ((Q->rear+1)%MAXQUEUE == Q->front)		//�ж���һ��Ԫ���Ƿ�Ϊfront��ָԪ��
		return TRUE;
	else
		return FALSE;
}


/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q)
{
	if (Q->front == Q->rear)					//ֻ���ڿ�ʱfront��rearָ��0
		return TRUE;
	else
		return FALSE;
}


/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q ����ָ��Q�����Ԫ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadAQueue(AQueue *Q, void *e)
{
	if (Q->front == Q->rear)
		return FALSE;
	else{								//����ͷԪ��memcpy��e��
		memcpy(e, Q->data[(Q->front+1)%MAXQUEUE], Q->length);
		return TRUE;
	}
}


/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : ���г���count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q)
{
	return (Q->rear - Q->front + MAXQUEUE) % MAXQUEUE;
}


/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ����˻�Ϊ��
 */
Status EnAQueue(AQueue *Q, void *data)
{
	if((Q->rear+1)%MAXQUEUE == Q->front){			//�ж�IsEmptyAQueue
		return FALSE;
	}
	else{
		Q->rear = (Q->rear + 1) % MAXQUEUE;			//rear����
		memcpy(Q->data[Q->rear], data, Q->length);		//��data  mencpy��rear��ָ�Ŀռ�
		return TRUE;
	}
}


/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q)
{
	if(Q->front == Q->rear)
		return FALSE;
	else{
		Q->front = (Q->front + 1) % MAXQUEUE;		//front����
		return TRUE;
	}
}


/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q)
{
	Q->front = 0;
	Q->rear = 0;
}

int flag;				//��ȫ�ֱ���flag����Q->length��ָ��������
/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
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
		int i = Q->front + 1;				//������ӡ����
		while(i <= (Q->rear - Q->front + MAXQUEUE) % MAXQUEUE){
			foo(Q->data[i]);
			i = (i + 1) % MAXQUEUE;			//i����front+1����
		}
		printf("\n");
		return TRUE;
	}
}


/**
 *  @name        : void APrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q
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



