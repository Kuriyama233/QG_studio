#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../inc/qgsort.h"
#include "../inc/SqStack.h"

#define NUM 20

int main()
{
	FILE *fp;
	fp = fopen("myrand.txt","w");		//��TXT�ļ����������ڴ���TXT
	int a[NUM];
	srand( (unsigned)time( NULL ) );	//����һ�����δ��������
	for(int i = 0; i < NUM;i++ ){
		a[i] = rand()%100;
	}
	fwrite(a,sizeof(int),NUM,fp);		//д��TXT�ļ�
	fclose(fp);							//�ر��ļ�
	printf("�ɹ�д��20���������myrand.txt\n");
	system("pause");
	return 0;
}
