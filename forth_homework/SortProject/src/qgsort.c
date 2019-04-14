#include <stdio.h>
#include <stdlib.h>
#include "../inc/qgsort.h"
#include "../inc/SqStack.h"

/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序
 *  @param       : 数组指针 a, 数组长度 n
 */
void insertSort(int *a,int n)
{
	int i, j, temp;
	for(i=1; i<n; i++){			//遍历所有项
		temp = *(a+i);			//temp等于即将插入的数据
		for(j=i; j>0; j--){		//往前比较
			if(temp<*(a+j-1))	//比前面的数小，前面这个数后移，
				*(a+j) = *(a+j-1);
			else				//比前面的数大，退出循环，插入到这个位置
				break;
		}
		*(a+j) = temp;
	}
}


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void MergeArray(int *a,int begin,int mid,int end,int *temp)
{
	int i = begin, j = mid + 1, k = begin;
	while (i != mid + 1 && j != end + 1){		//将i,j为头的数组逐个比较，大的那个放到temp数组
		if(a[i]>a[j])
			temp[k++] = a[j++];
		else
			temp[k++] = a[i++];
	}
	while(i != mid + 1)							//如果其中一个数组的数据全部放进temp
		temp[k++] = a[i++];						//则将另一个全部逐个放到temp
	while(j != end + 1)
		temp[k++] = a[j++];
	for(i=begin; i<end+1; i++)					//temp数据给a
		a[i] = temp[i];
}


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(int *a,int begin,int end,int *temp)
{
	int mid;
	if(begin != end){						//begin = end时两个下标都指向同一个数据，不能再二分
		mid = begin + (end - begin) / 2;		//mid为二分的中点。
		MergeSort(a, begin, mid, temp);			//二分的一侧继续二分
		MergeSort(a, mid+1, end, temp);			//二分的另一侧继续二分
		MergeArray(a, begin, mid, end, temp);	//二分结束后将数据合并
	}
}


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void QuickSort_Recursion(int *a, int begin, int end)
{
	if(begin <= end){
		int mid = Partition(a, begin, end);			//找枢轴
		QuickSort_Recursion(a, begin, mid-1);		//枢轴分开的其中一边继续找枢轴
		QuickSort_Recursion(a, mid+1, end);			//另一边继续找枢轴
	}
}


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */
void QuickSort(int *a,int size)
{
	SqStack s;						//创建一个栈
	initStack(&s, size);			//初始化
	int begin = 0;					//起点和终点下标
	int end = size - 1;
	pushStack(&s,begin);			//将头尾下标入栈
	pushStack(&s,end);
    while(!isEmptyStack(&s))		//栈不为空
    {
        getTopStack(&s, &end);		//得两个栈顶数据，出栈
        popStack(&s);
        getTopStack(&s, &begin);
        popStack(&s);
        int mid = Partition(a, begin, end);
        if (mid - 1 < begin)		//栈顶的两个下标中间存在枢轴，则将枢轴与头或者枢轴与尾入栈
        {							//循环至无枢轴全部出栈
            pushStack(&s, begin);
			pushStack(&s, mid - 1);
        }
        if(mid + 1 > end){
            pushStack(&s,mid + 1);
            pushStack(&s, end);
        }
    }
}


/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
int Partition(int *a, int begin, int end)
{
	int temp;
	int i = begin+1, mid = begin;
	while(i <= end){				//第一个元素当枢轴元素，从第二个元素开始遍历
		if(a[i]<a[begin]){			//比枢轴元素小的放在枢轴元素后面
			temp = a[mid+1];		//比枢轴元素大的放在小的后面
			a[mid+1] = a[i];
			a[i] = temp;
			mid++;
		}
		i++;
	}
	temp = a[mid];					//将与大的元素接壤的小元素与枢轴元素互换位置
	a[mid] = a[begin];
	a[begin] = temp;
	return mid;
}


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void CountSort(int *a, int size , int max)
{
	int *s = (int*)malloc((max+1)*sizeof(int));		//创建下标含所有数据的数组
	for(int i=0; i<max+1; i++)						//遍历数组，出现某个数据，就在以某个数据为下标的数组元素加1
		s[i] = 0;									//表示出现与下标值相等的数据的个数
	for(int i=0; i<size; i++){
		int temp = a[i];
		s[temp]++;
	}
	int i=0;
//	for(int i=0; i<max+1; i++)
//		printf("%d ",s[i]);
//	printf("\n");
//	getchar();
	for(int temp=1; temp<max+1;){					//遍历数组，当值不为零时，将下标作为元素放入a
//		printf("here\n");getchar();getchar();
		if(s[temp]!=0){
			s[temp]--;
			a[i++] = temp;
		}else
			temp++;
//	printf("i=%d a[i]=%d temp=%d\n",i,a[i-1],temp);getchar();
	}
	free(s);
}


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
void RadixCountSort(int *a,int size)
{
	int *s[10];
	for(int i=0; i<10; i++){
		s[i] = (int*)malloc((size + 1) * sizeof(int));
		s[i][0] = 0;
	}
	int cnt = 0;
	while(1){
		int lose;				//cnt记录循环次数，lose用于降位处理
		if(cnt == 0)
			lose = 1;
		else
			lose *= 10;
		for(int i=0;i<size;i++){
			int temp = (int)(a[i] / lose % 10);		//%10取出最后一位
			int sum = ++s[temp][0];					//记录取出位数字的下标指针所指数据的个数
			s[temp][sum] = a[i];					//数据放入该下标所指的数组s中
		}
		if(!(s[0][0]!=size))						//当所有数储存到s[0]中，证明已排序成功，退出循环
			break;
		int temp = 0;
		for(int i=0; i<10; i++){					//将s中的数据按照一定顺序输出放到a中去
			for(int j=1; s[i][0]!=0; j++){
				a[temp++] = s[i][j];
//				printf("%d %d",temp-1,a[temp-1]);getchar();
				s[i][0]--;
			}
		}
		cnt++;										//记录循环次数，继续排序
	}
	for(int i=0; i<10; i++){
		free(s[i]);
	}
}


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int *a,int size)
{
	int begin = 0, end = size - 1, p = 0;
	while(p != end){					//p与end未相等时，未遍历所有元素
//		printf("begin=%d end=%d p=%d",begin,end,p-1);getchar();
		if(a[p] == 1)					//等于一时p走到下一个
			p++;
		if(a[p] == 0){					//等于零时与begin换位置
			a[p] = a[begin];
			a[begin++] = 0;
		}
		if(a[p] == 2){					//等于二时与end换位置
			a[p] = a[end];
			a[end--] = 2;
		}
	}
}

/**
 *  @name        : int Findnum(int *a, int size)
 *  @description : 在一个无序序列中找到第K小的数
 *  @param       : 数组指针a，数组长度size
 */
int Findnum(int *a, int size)
{
	if( K > size )					//判断K是否超出数组大小
		return 0;
	int *temp = (int*)malloc(size*sizeof(int));
	for(int i=0;i<size; i++){
		temp[i] = a[i];				//复制a到temp
	}
	insertSort(temp,size);			//对temp插入排序
	int KNum = temp[K-1];			//将目标数据提取出
	free(temp);						//free temp
	return KNum;					//返回目标数据
}

