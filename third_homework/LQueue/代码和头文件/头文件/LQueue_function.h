#ifndef LQUEUE_FUNCTION_H_INCLUDED
#define LQUEUE_FUNCTION_H_INCLUDED

Status save_EnLQueue(LQueue *Q);		//插入一个数据
void initial_interface();				//界面
void operate_interface();				//界面
void input_data(LQueue *Q);				//执行数据输入功能
void next_operate(LQueue *Q);			//执行数据处理功能

#endif // LQUEUE_FUNCTION_H_INCLUDED
