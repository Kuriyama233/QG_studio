#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef enum Status {
	ERROR = 0, SUCCESS = 1
} Status;

typedef struct SqStack {
	int *elem;
	int top;
	int size;
} SqStack;


//˳��ջ(���������)
Status initStack(SqStack *s,int sizes);//��ʼ��ջ
Status isEmptyStack(SqStack *s);//�ж�ջ�Ƿ�Ϊ��
Status getTopStack(SqStack *s,int *e); //�õ�ջ��Ԫ��
Status clearStack(SqStack *s);//���ջ
Status destroyStack(SqStack *s);//����ջ
Status stackLength(SqStack *s,int *length);//���ջ����
Status pushStack(SqStack *s,int data);//��ջ
Status popStack(SqStack *s);//��ջ


#endif // STACK_H_INCLUDED
