#include <stdio.h>
#include <stdlib.h>
#include "../inc/qgsort.h"
#include "../inc/SqStack.h"

#define NUM 20

int main()
{
	FILE *fp;
	int a[NUM];
	if( ( fp = fopen("myrand.txt","r") ) == NULL){             		//打开文件，若不存在退出程序
		printf("error: failed to open the file \"myrand.txt\"\n");
		system("pause");
		exit(0);
	}
	if(fread(a,sizeof(int),NUM,fp) != NUM){							//读取文件，若文件数据缺失，退出程序
		printf("error:the file is broken\n");
		system("pause");
		exit(0);
	}
	int temp[NUM];
	int max = a[0];							//找出程序中数据最大值
	for(int i=1; i<NUM; i++){
		if(max<a[i])
			max = a[i];
	}
//	printf("max=%d\n",max);
	printf("文件数据已收录，数据如下：\n");
	for(int i=0; i<NUM; i++)				//遍历未排序数组
		printf("%d ",a[i]);
	printf("\n\n");
	printf("1-插入，2-归并，3-快速，4基数，5-计数\n请输入：");
	int choice;
	scanf("%d",&choice);					//选择排序方式
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
	default:								//不规范输入退出程序
		printf("please enter the true choice\nbye\n");
		system("pause");
		exit(0);
	}

	for(int i=0; i<NUM; i++)				//遍历以排序数据
		printf("%d ",a[i]);
	return 0;
}
