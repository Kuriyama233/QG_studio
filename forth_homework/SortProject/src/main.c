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
	int *a=(int*)malloc(SIZE*sizeof(int));			//申请内存
	int *b=(int*)malloc(SIZE*sizeof(int));
	int *c=(int*)malloc(SIZE*sizeof(int));
	int *d=(int*)malloc(SIZE*sizeof(int));
	int *e=(int*)malloc(SIZE*sizeof(int));

	clock_t start, end;						//时间的起点与终点
    int i;
	srand( (unsigned)time( NULL ) );		//时间为种子
	for( i = 0; i < SIZE;i++ ){				//随机数储存到数组abcde中
		a[i] = b[i] = c[i] = d[i] = e[i] = rand()%100;
	}
	printf("排序%d个数字所需要的时间：\n",SIZE);
	printf("插入排序用时：");
	start = clock();
	insertSort(a, SIZE);
	end = clock();
	printf("%f\n",(double)(end - start) / CLOCKS_PER_SEC);		//记录时间起点终点的差值，做函数运行时间

	printf("归并排序用时：");
	start = clock();
	int temp[SIZE];
	MergeSort(b,0,SIZE,temp);
	end = clock();
	printf("%f\n",(double)(end - start) / CLOCKS_PER_SEC);

	printf("快速排序用时：");
	start = clock();
	QuickSort_Recursion(c,0,SIZE-1);
	end = clock();
	printf("%f\n",(double)(end - start) / CLOCKS_PER_SEC);

	printf("基数排序用时：");
	start = clock();
	RadixCountSort(d,SIZE);
	end = clock();
	printf("%f\n",(double)(end - start) / CLOCKS_PER_SEC);


	printf("计数排序用时：");
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
	printf("排序%d个数字100K次所需要的时间：\n",SIZE);

	start = clock();
	for(int j=0; j<100000; j++){				//调用100k次函数赋值
		srand( (unsigned)time( NULL ) );
		for(int i = 0; i < SIZE;i++ ){
			a[i] = rand()%100;
		}
		insertSort(a, SIZE);
	}
	end = clock();
	printf("插入排序用时：");
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
	printf("归并排序用时：");
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
	printf("快速排序用时：");
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
	printf("基数排序用时：");
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
	printf("计数排序用时：");
	printf("%f\n",(double)(end - start) / CLOCKS_PER_SEC);
}
