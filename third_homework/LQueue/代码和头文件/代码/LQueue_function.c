#include <stdio.h>
#include <stdlib.h>
#include "../ͷ�ļ�/LQueue.h"
#include "../ͷ�ļ�/LQueue_function.h"


//����һ������
Status save_EnLQueue(LQueue *Q)
{
	Status judge;
	while (1){				//�жϼ����������������
		if (Q->length == sizeof(double)){
			double data;
			if(scanf("%lf",&data) != 1){			//�淶����
				printf("����������淶���룺");
				while(getchar()!='\n');
				continue;
			}
			judge = EnLQueue(Q, &data);				//����
			break;
		}
		else if (Q->length == sizeof(int)){
			int data;
			if(scanf("%d",&data) != 1){				//�淶����
				printf("����������淶���룺");
				while(getchar()!='\n');
				continue;
			}
			judge = EnLQueue(Q, &data);			//����
			break;
		}
		else if (Q->length == sizeof(char)){
			char data;
			while(getchar()!='\n');
			scanf("%c",&data);					//��������
			judge = EnLQueue(Q, &data);			//����
			break;
		}
	}
	if (judge == TRUE)							//�жϲ����Ƿ�ɹ�
		return TRUE;
	else
		return FALSE;
}


//����
void initial_interface()
{
	printf("\n\n\n\n\n"
	"\t\t\t|*******************************|\n"
	"\t\t\t|*         ����һ������        *|\n"
	"\t\t\t|*      1����ʼ��һ������      *|\n"
	"\t\t\t|*      2���˳�����            *|\n"
	"\t\t\t|*******************************|\n"
	);
	printf("\n\t����������ѡ��1 or 2����");
}

//����
void operate_interface()
{
	printf("\n\n\n\n\n"
	"\t\t\t|****************************|\n"
	"\t\t\t|*    1���������Ƿ�Ϊ��   *|\n"
	"\t\t\t|*    2���鿴��ͷԪ��       *|\n"
	"\t\t\t|*    3���ݻٶ���           *|\n"
	"\t\t\t|*    4��ȷ�����г���       *|\n"
	"\t\t\t|*    5����Ӳ���           *|\n"
	"\t\t\t|*    6�����Ӳ���           *|\n"
	"\t\t\t|*    7����ն���           *|\n"
	"\t\t\t|*    8��������������       *|\n"
	"\t\t\t|****************************|\n"
	);
	printf("\n\t����������ѡ��1-8����");
}

//ִ���������빦��
void input_data(LQueue *Q)
{
	int choice;
	printf("��������Ҫ�������������(int 1 & double 2 & char 3)��");
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
				printf("������������Ҫ������������ͣ�");
				while(getchar()!='\n');
				goto again;
		}
	next_operate(Q);		//ת�� ���ݴ�����
}


//ִ�����ݴ�����
void next_operate(LQueue *Q)
{
	//���봢�������
	InitLQueue(Q);
	printf("��������Ҫ�������ݵĸ�����");
	int num, i = 1;
	scanf("%d",&num);
	printf("��������Ҫ��������ݣ�");
	while(save_EnLQueue(Q) && i<num){
		printf("����������Ҫ��������ݣ�");
		i++;
	}
	system("cls");

	//�Զ��н��в���
	int choice;
	interface:
	operate_interface();		//����
//	printf("R%d F%d",Q->rear,Q->front);		//���Դ���
	while (1){
		while(getchar() != '\n');
		while (scanf("%d",&choice) != 1 ){			//ѡ�������1-8��
			printf("\t��淶�������루1-8����");
		}
		switch (choice){
			case 1:
				if(IsEmptyLQueue(Q))				//�ж��Ƿ�Ϊ��
					printf("����Ϊ��\n");
				else
					printf("���в�Ϊ��\n");
				system("pause");
				break;
			case 2:									//�ж��������ͣ����ҳ���ͷԪ��
				if (Q->length == sizeof(double)){
					double data;
					if(GetHeadLQueue(Q, &data)){
						printf("��ͷԪ��Ϊ��%f\n",data);
					}
					else
						printf("�޶�ͷԪ��\n");
				}
				else if (Q->length == sizeof(int)){
					int data;
					if(GetHeadLQueue(Q, &data)){
						printf("��ͷԪ��Ϊ��%d\n",data);
					}
					else
						printf("�޶�ͷԪ��\n");
				}
				else if (Q->length == sizeof(char)){
					char data;
					if(GetHeadLQueue(Q, &data)){
						printf("��ͷԪ��Ϊ��%c\n",data);
					}
					else
						printf("�޶�ͷԪ��\n");
				}
				system("pause");
				break;
			case 3:
				DestoryLQueue(Q);			//�ݻٶ���
				printf("�ݻٳɹ�\n");
				printf("�����˳������ټ�\n");
				system("pause");
				exit(0);
				break;
			case 4:					//��ӡ���г���
				printf("���еĳ���Ϊ%d\n", LengthLQueue(Q));
				system("pause");
				break;
			case 5:
				printf("\t��������Ҫ��ӵ����ݣ�");
				if(save_EnLQueue(Q))				//���
					printf("��ӳɹ�\n");
				else
					printf("���ʧ�ܣ���������\n");
				system("pause");
				break;
			case 6:
				if (DeLQueue(Q))					//����
					printf("���ӳɹ�\n");
				else
					printf("����ʧ�ܣ������ѿ�\n");
				system("pause");
				break;
			case 7:
				ClearLQueue(Q);
				printf("��ճɹ�\n");
				system("pause");
				break;
			case 8:
				if(TraverseLQueue(Q, LPrint) == FALSE)		//��ӡ����Ԫ��
					printf("����Ϊ��\n");
				system("pause");
				break;
			default:
				printf("\t��淶�������루1-8����");
				continue;
		}
		break;
	}
	system("cls");
	goto interface;
}



