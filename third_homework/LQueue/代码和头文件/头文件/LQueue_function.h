#ifndef LQUEUE_FUNCTION_H_INCLUDED
#define LQUEUE_FUNCTION_H_INCLUDED

Status save_EnLQueue(LQueue *Q);		//����һ������
void initial_interface();				//����
void operate_interface();				//����
void input_data(LQueue *Q);				//ִ���������빦��
void next_operate(LQueue *Q);			//ִ�����ݴ�����

#endif // LQUEUE_FUNCTION_H_INCLUDED
