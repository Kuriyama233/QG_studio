#include "../头文件/AQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include "../头文件/function_AQueue.h"

//插入一个数据
Status save_EnAQueue(AQueue *Q)
{
	Status judge;
	while (1){				//判断即将输入的数据类型
		if (Q->length == sizeof(double)){
			double data;
			if(scanf("%lf",&data) != 1){			//规范输入
				printf("输入有误，请规范输入：");
				while(getchar()!='\n');
				continue;
			}
			judge = EnAQueue(Q, &data);				//插入
			break;
		}
		else if (Q->length == sizeof(int)){
			int data;
			if(scanf("%d",&data) != 1){				//规范输入
				printf("输入有误，请规范输入：");
				while(getchar()!='\n');
				continue;
			}
			judge = EnAQueue(Q, &data);			//插入
			break;
		}
		else if (Q->length == sizeof(char)){
			char data;
			while(getchar()!='\n');
			scanf("%c",&data);					//输入数据
			judge = EnAQueue(Q, &data);			//插入
			break;
		}
	}
	if (judge == TRUE)							//判断插入是否成功
		return TRUE;
	else
		return FALSE;
}


//界面
void initial_interface()
{
	printf("\n\n\n\n\n"
	"\t\t\t|*******************************|\n"
	"\t\t\t|*         创建一个队列        *|\n"
	"\t\t\t|*      1、初始化一个队列      *|\n"
	"\t\t\t|*      2、退出程序            *|\n"
	"\t\t\t|*******************************|\n"
	);
	printf("\n\t请输入您的选择（1 or 2）：");
}

//界面
void operate_interface()
{
	printf("\n\n\n\n\n"
	"\t\t\t|****************************|\n"
	"\t\t\t|*    1、检查队列是否已满   *|\n"
	"\t\t\t|*    2、检查队列是否为空   *|\n"
	"\t\t\t|*    3、查看队头元素       *|\n"
	"\t\t\t|*    4、摧毁队列           *|\n"
	"\t\t\t|*    5、确定队列长度       *|\n"
	"\t\t\t|*    6、入队操作           *|\n"
	"\t\t\t|*    7、出队操作           *|\n"
	"\t\t\t|*    8、清空队列           *|\n"
	"\t\t\t|*    9、遍历函数操作       *|\n"
	"\t\t\t|****************************|\n"
	);
	printf("\n\t请输入您的选择（1-9）：");
}

//执行数据输入功能
void input_data(AQueue *Q)
{
	int choice;
	printf("请输入您要输入的数据类型(int 1 & double 2 & char 3)：");
	again:
	scanf("%d",&choice);
		switch (choice){

			case 1:{
				Q->length = sizeof(int);
				break;
			}
			case 2:{
				Q->length = sizeof(double);
				break;
			}
			case 3:{
				Q->length = sizeof(char);
				break;
			}
			default:
				printf("请重新输入您要输入的数据类型：");
				while(getchar()!='\n');
				goto again;
		}
	next_operate(Q);		//转到 数据处理函数
}


//执行数据处理功能
void next_operate(AQueue *Q)
{
	//输入储存的数据
	InitAQueue(Q);
	printf("请输入您要储存数据的个数：");
	int num, i = 1;
	scanf("%d",&num);
	printf("请输入您要储存的数据：");
	while(save_EnAQueue(Q) && IsFullAQueue(Q) == FALSE && i<num){
		printf("请再输入您要储存的数据：");
		i++;
	}
	system("cls");

	//对队列进行操作
	int choice;
	interface:
	operate_interface();		//界面
//	printf("R%d F%d",Q->rear,Q->front);		//测试代码
	while (1){
		while(getchar() != '\n');
		while (scanf("%d",&choice) != 1 ){			//选择操作（1-8）
			printf("\t请规范您的输入（1-8）：");
		}
		switch (choice){
			case 1:
				if (IsFullAQueue(Q))				//判断是否满
					printf("队列已满\n");
				else
					printf("队列未满\n");
				system("pause");
				break;
			case 2:
				if(IsEmptyAQueue(Q))				//判断是否为空
					printf("队列为空\n");
				else
					printf("队列不为空\n");
				system("pause");
				break;
			case 3:									//判断数据类型，并找出队头元素
				if (Q->length == sizeof(double)){
					double data;
					if(GetHeadAQueue(Q, &data)){
						printf("对头元素为：%f\n",data);
					}
					else
						printf("无队头元素\n");
				}
				else if (Q->length == sizeof(int)){
					int data;
					if(GetHeadAQueue(Q, &data)){
						printf("对头元素为：%d\n",data);
					}
					else
						printf("无队头元素\n");
				}
				else if (Q->length == sizeof(char)){
					char data;
					if(GetHeadAQueue(Q, &data)){
						printf("对头元素为：%c\n",data);
					}
					else
						printf("无队头元素\n");
				}
				system("pause");
				break;
			case 4:
				DestoryAQueue(Q);			//摧毁队列
				printf("摧毁成功\n");
				printf("您已退出程序，再见\n");
				system("pause");
				exit(0);
				break;
			case 5:					//打印队列长度
				printf("队列的长度为%d\n", LengthAQueue(Q));
				system("pause");
				break;
			case 6:
				printf("\t请输入您要入队的数据：");
				if(save_EnAQueue(Q))				//入队
					printf("入队成功\n");
				else
					printf("入队失败，队列已满\n");
				system("pause");
				break;
			case 7:
				if (DeAQueue(Q))					//出队
					printf("出队成功\n");
				else
					printf("出队失败，队列已空\n");
				system("pause");
				break;
			case 8:
				ClearAQueue(Q);
				printf("清空成功\n");
				system("pause");
				break;
			case 9:
				if(TraverseAQueue(Q, APrint) == FALSE)		//打印队列元素
					printf("队列为空\n");
				system("pause");
				break;
			default:
				printf("\t请规范您的输入（1-9）：");
				continue;
		}
		break;
	}
	system("cls");
	goto interface;
}


