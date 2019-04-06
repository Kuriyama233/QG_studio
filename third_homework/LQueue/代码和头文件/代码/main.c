#include <stdio.h>
#include "../头文件/LQueue.h"
#include "../头文件/LQueue_function.h"

int main()
{
	int choice;
	initial_interface();
	while (1){
		while (scanf("%d",&choice) != 1)		//选择输入数据还是退出程序
			printf("输入有误，请再输入您的选择（1 or 2）：");
		switch (choice){
		case 1:				//执行输入数据功能
			system("cls");
			LQueue *Q;
			input_data(Q);		//下一步操作
			getchar();
			exit(0);
		case 2:			//退出程序
			printf("\n\n\t程序已退出，再见！\n");
			system("pause");
			exit(0);
		default:		/*无效输入*/
			printf("输入有误，请再输入您的选择（1 or 2）：");
			continue;
		}
	}
	return 0;
}
