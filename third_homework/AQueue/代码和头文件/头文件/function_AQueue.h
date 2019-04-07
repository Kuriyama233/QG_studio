#ifndef FUNCTION_AQUEUE_H_INCLUDED
#define FUNCTION_AQUEUE_H_INCLUDED

Status save_EnAQueue(AQueue *Q);		//插入一个数据
void initial_interface();				//界面
void operate_interface();				//界面
void input_data(AQueue *Q);				//执行数据输入功能
void next_operate(AQueue *Q);			//执行数据处理功能


#endif // FUNCTION_AQUEUE_H_INCLUDED
