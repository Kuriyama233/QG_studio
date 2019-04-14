#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../inc/qgsort.h"
#include "../inc/SqStack.h"

void test(int SIZE);
void test2(int SIZE);

//int a3[200000], b3[200000], c3[200000], d3[200000], e3[200000];

int main()
{
//	int a1[10000], b1[10000], c1[10000], d1[10000], e1[10000];
	test(10000);
//	int a2[50000], b2[50000], c2[50000], d2[50000], e2[50000];
	test(50000);
	test(200000);
	test2(100);
}

void test(int SIZE)
{
	int *a=(int*)malloc(SIZE*sizeof(int));			//�����ڴ�
	int *b=(int*)malloc(SIZE*sizeof(int));
	int *c=(int*)malloc(SIZE*sizeof(int));
	int *d=(int*)malloc(SIZE*sizeof(int));
	int *e=(int*)malloc(SIZE*sizeof(int));

	clock_t start, end;						//ʱ���������յ�
    int i;
	srand( (unsigned)time( NULL ) );		//ʱ��Ϊ����
	for( i = 0; i < SIZE;i++ ){				//��������浽����abcde��
		a[i] = b[i] = c[i] = d[i] = e[i] = rand()%100;
	}
	printf("����%d����������Ҫ��ʱ�䣺\n",SIZE);
	printf("����������ʱ��");
	start = clock();
	insertSort(a, SIZE);
	end = clock();
	printf("%f\n",(double)(end - start) / CLOCKS_PER_SEC);		//��¼ʱ������յ�Ĳ�ֵ������������ʱ��

	printf("�鲢������ʱ��");
	start = clock();
	int temp[SIZE];
	MergeSort(b,0,SIZE,temp);
	end = clock();
	printf("%f\n",(double)(end - start) / CLOCKS_PER_SEC);

	printf("����������ʱ��");
	start = clock();
	QuickSort_Recursion(c,0,SIZE-1);
	end = clock();
	printf("%f\n",(double)(end - start) / CLOCKS_PER_SEC);

	printf("����������ʱ��");
	start = clock();
	RadixCountSort(d,SIZE);
	end = clock();
	printf("%f\n",(double)(end - start) / CLOCKS_PER_SEC);


	printf("����������ʱ��");
	start = clock();
	CountSort(e,SIZE,d[SIZE-1]);
	end = clock();
	printf("%f\n",(double)(end - start) / CLOCKS_PER_SEC);

	free(a);
	free(b);
	free(c);
	free(d);
	free(e);

//	for(i=0;i<SIZE;i++)
//		printf("%d ",d[i]);
}


void test2(int SIZE)
{
	int *a = (int*)malloc(SIZE*sizeof(int));
	clock_t start, end;
	printf("����%d������100K������Ҫ��ʱ�䣺\n",SIZE);

	start = clock();
	for(int j=0; j<100000; j++){				//����100k�κ�����ֵ
		srand( (unsigned)time( NULL ) );
		for(int i = 0; i < SIZE;i++ ){
			a[i] = rand()%100;
		}
		insertSort(a, SIZE);
	}
	end = clock();
	printf("����������ʱ��");
	printf("%f\n",(double)(end - start) / CLOCKS_PER_SEC);

	start = clock();
	for(int j=0; j<100000; j++){
		srand( (unsigned)time( NULL ) );
		for(int i = 0; i < SIZE;i++ ){
			a[i] = rand()%100;
		}
		int temp[SIZE];
		MergeSort(a,0,SIZE,temp);
	}
	end = clock();
	printf("�鲢������ʱ��");
	printf("%f\n",(double)(end - start) / CLOCKS_PER_SEC);

	start = clock();
	for(int j=0; j<100000; j++){
		srand( (unsigned)time( NULL ) );
		for(int i = 0; i < SIZE;i++ ){
			a[i] = rand()%100;
		}
		QuickSort_Recursion(a,0,SIZE-1);
	}
	end = clock();
	printf("����������ʱ��");
	printf("%f\n",(double)(end - start) / CLOCKS_PER_SEC);

	start = clock();
	for(int j=0; j<100000; j++){
		srand( (unsigned)time( NULL ) );
		for(int i = 0; i < SIZE;i++ ){
			a[i] = rand()%100;
		}
		RadixCountSort(a,SIZE);
	}
	end = clock();
	int max = a[SIZE-1];
	printf("����������ʱ��");
	printf("%f\n",(double)(end - start) / CLOCKS_PER_SEC);

	start = clock();
	for(int j=0; j<100000; j++){
		srand( (unsigned)time( NULL ) );
		for(int i = 0; i < SIZE;i++ ){
			a[i] = rand()%100;
		}
		CountSort(a,SIZE,max);
	}
	end = clock();
	printf("����������ʱ��");
	printf("%f\n",(double)(end - start) / CLOCKS_PER_SEC);
}
