#include "../ͷ�ļ�/AQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include "../ͷ�ļ�/function_AQueue.h"

//����һ������
Status save_EnAQueue(AQueue *Q)
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
			judge = EnAQueue(Q, &data);				//����
			break;
		}
		else if (Q->length == sizeof(int)){
			int data;
			if(scanf("%d",&data) != 1){				//�淶����
				printf("����������淶���룺");
				while(getchar()!='\n');
				continue;
			}
			judge = EnAQueue(Q, &data);			//����
			break;
		}
		else if (Q->length == sizeof(char)){
			char data;
			while(getchar()!='\n');
			scanf("%c",&data);					//��������
			judge = EnAQueue(Q, &data);			//����
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
	"\t\t\t|*    1���������Ƿ�����   *|\n"
	"\t\t\t|*    2���������Ƿ�Ϊ��   *|\n"
	"\t\t\t|*    3���鿴��ͷԪ��       *|\n"
	"\t\t\t|*    4���ݻٶ���           *|\n"
	"\t\t\t|*    5��ȷ�����г���       *|\n"
	"\t\t\t|*    6����Ӳ���           *|\n"
	"\t\t\t|*    7�����Ӳ���           *|\n"
	"\t\t\t|*    8����ն���           *|\n"
	"\t\t\t|*    9��������������       *|\n"
	"\t\t\t|****************************|\n"
	);
	printf("\n\t����������ѡ��1-9����");
}

//ִ���������빦��
void input_data(AQueue *Q)
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
void next_operate(AQueue *Q)
{
	//���봢�������
	InitAQueue(Q);
	printf("��������Ҫ�������ݵĸ�����");
	int num, i = 1;
	scanf("%d",&num);
	printf("��������Ҫ��������ݣ�");
	while(save_EnAQueue(Q) && IsFullAQueue(Q) == FALSE && i<num){
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
				if (IsFullAQueue(Q))				//�ж��Ƿ���
					printf("��������\n");
				else
					printf("����δ��\n");
				system("pause");
				break;
			case 2:
				if(IsEmptyAQueue(Q))				//�ж��Ƿ�Ϊ��
					printf("����Ϊ��\n");
				else
					printf("���в�Ϊ��\n");
				system("pause");
				break;
			case 3:									//�ж��������ͣ����ҳ���ͷԪ��
				if (Q->length == sizeof(double)){
					double data;
					if(GetHeadAQueue(Q, &data)){
						printf("��ͷԪ��Ϊ��%f\n",data);
					}
					else
						printf("�޶�ͷԪ��\n");
				}
				else if (Q->length == sizeof(int)){
					int data;
					if(GetHeadAQueue(Q, &data)){
						printf("��ͷԪ��Ϊ��%d\n",data);
					}
					else
						printf("�޶�ͷԪ��\n");
				}
				else if (Q->length == sizeof(char)){
					char data;
					if(GetHeadAQueue(Q, &data)){
						printf("��ͷԪ��Ϊ��%c\n",data);
					}
					else
						printf("�޶�ͷԪ��\n");
				}
				system("pause");
				break;
			case 4:
				DestoryAQueue(Q);			//�ݻٶ���
				printf("�ݻٳɹ�\n");
				printf("�����˳������ټ�\n");
				system("pause");
				exit(0);
				break;
			case 5:					//��ӡ���г���
				printf("���еĳ���Ϊ%d\n", LengthAQueue(Q));
				system("pause");
				break;
			case 6:
				printf("\t��������Ҫ��ӵ����ݣ�");
				if(save_EnAQueue(Q))				//���
					printf("��ӳɹ�\n");
				else
					printf("���ʧ�ܣ���������\n");
				system("pause");
				break;
			case 7:
				if (DeAQueue(Q))					//����
					printf("���ӳɹ�\n");
				else
					printf("����ʧ�ܣ������ѿ�\n");
				system("pause");
				break;
			case 8:
				ClearAQueue(Q);
				printf("��ճɹ�\n");
				system("pause");
				break;
			case 9:
				if(TraverseAQueue(Q, APrint) == FALSE)		//��ӡ����Ԫ��
					printf("����Ϊ��\n");
				system("pause");
				break;
			default:
				printf("\t��淶�������루1-9����");
				continue;
		}
		break;
	}
	system("cls");
	goto interface;
}


