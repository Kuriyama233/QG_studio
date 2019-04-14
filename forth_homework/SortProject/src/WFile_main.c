#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../inc/qgsort.h"
#include "../inc/SqStack.h"

#define NUM 20

int main()
{
	FILE *fp;
	fp = fopen("myrand.txt","w");		//打开TXT文件，若不存在创建TXT
	int a[NUM];
	srand( (unsigned)time( NULL ) );	//创建一个随机未排序数组
	for(int i = 0; i < NUM;i++ ){
		a[i] = rand()%100;
	}
	fwrite(a,sizeof(int),NUM,fp);		//写入TXT文件
	fclose(fp);							//关闭文件
	printf("成功写入20个随机数到myrand.txt\n");
	system("pause");
	return 0;
}
