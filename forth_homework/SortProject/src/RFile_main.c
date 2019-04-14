#include <stdio.h>
#include <stdlib.h>
#include "../inc/qgsort.h"
#include "../inc/SqStack.h"

#define NUM 20

int main()
{
	FILE *fp;
	int a[NUM];
	if( ( fp = fopen("myrand.txt","r") ) == NULL){             		//���ļ������������˳�����
		printf("error: failed to open the file \"myrand.txt\"\n");
		system("pause");
		exit(0);
	}
	if(fread(a,sizeof(int),NUM,fp) != NUM){							//��ȡ�ļ������ļ�����ȱʧ���˳�����
		printf("error:the file is broken\n");
		system("pause");
		exit(0);
	}
	int temp[NUM];
	int max = a[0];							//�ҳ��������������ֵ
	for(int i=1; i<NUM; i++){
		if(max<a[i])
			max = a[i];
	}
//	printf("max=%d\n",max);
	printf("�ļ���������¼���������£�\n");
	for(int i=0; i<NUM; i++)				//����δ��������
		printf("%d ",a[i]);
	printf("\n\n");
	printf("1-���룬2-�鲢��3-���٣�4������5-����\n�����룺");
	int choice;
	scanf("%d",&choice);					//ѡ������ʽ
	switch (choice){
	case 1:
		insertSort(a, NUM);
		break;
	case 2:
		MergeSort(a,0,NUM-1,temp);
		break;
	case 3:
		QuickSort_Recursion(a,0,NUM-1);
		break;
	case 4:
		RadixCountSort(a,NUM);
		break;
	case 5:
		CountSort(a,NUM,max);
		break;
	default:								//���淶�����˳�����
		printf("please enter the true choice\nbye\n");
		system("pause");
		exit(0);
	}

	for(int i=0; i<NUM; i++)				//��������������
		printf("%d ",a[i]);
	return 0;
}
