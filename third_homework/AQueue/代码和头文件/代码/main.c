#include "../ͷ�ļ�/AQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include "../ͷ�ļ�/function_AQueue.h"
int main()
{
	int choice;
	initial_interface();
	while (1){
		while (scanf("%d",&choice) != 1)		//ѡ���������ݻ����˳�����
			printf("��������������������ѡ��1 or 2����");
		switch (choice){
		case 1:				//ִ���������ݹ���
			system("cls");
			AQueue *Q;
			input_data(Q);		//��һ������
			getchar();
			exit(0);
		case 2:			//�˳�����
			printf("\n\n\t�������˳����ټ���\n");
			system("pause");
			exit(0);
		default:		/*��Ч����*/
			printf("��������������������ѡ��1 or 2����");
			continue;
		}
	}
	return 0;
}
