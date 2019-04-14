#include <stdio.h>
#include <stdlib.h>
#include "../inc/qgsort.h"
#include "../inc/SqStack.h"

/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : ��������
 *  @param       : ����ָ�� a, ���鳤�� n
 */
void insertSort(int *a,int n)
{
	int i, j, temp;
	for(i=1; i<n; i++){			//����������
		temp = *(a+i);			//temp���ڼ������������
		for(j=i; j>0; j--){		//��ǰ�Ƚ�
			if(temp<*(a+j-1))	//��ǰ�����С��ǰ����������ƣ�
				*(a+j) = *(a+j-1);
			else				//��ǰ��������˳�ѭ�������뵽���λ��
				break;
		}
		*(a+j) = temp;
	}
}


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : �鲢���򣨺ϲ����飩
 *  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
 */
void MergeArray(int *a,int begin,int mid,int end,int *temp)
{
	int i = begin, j = mid + 1, k = begin;
	while (i != mid + 1 && j != end + 1){		//��i,jΪͷ����������Ƚϣ�����Ǹ��ŵ�temp����
		if(a[i]>a[j])
			temp[k++] = a[j++];
		else
			temp[k++] = a[i++];
	}
	while(i != mid + 1)							//�������һ�����������ȫ���Ž�temp
		temp[k++] = a[i++];						//����һ��ȫ������ŵ�temp
	while(j != end + 1)
		temp[k++] = a[j++];
	for(i=begin; i<end+1; i++)					//temp���ݸ�a
		a[i] = temp[i];
}


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : �鲢����
 *  @param       : ����ָ��a���������begin�������յ�end����������ָ��temp
 */
void MergeSort(int *a,int begin,int end,int *temp)
{
	int mid;
	if(begin != end){						//begin = endʱ�����±궼ָ��ͬһ�����ݣ������ٶ���
		mid = begin + (end - begin) / 2;		//midΪ���ֵ��е㡣
		MergeSort(a, begin, mid, temp);			//���ֵ�һ���������
		MergeSort(a, mid+1, end, temp);			//���ֵ���һ���������
		MergeArray(a, begin, mid, end, temp);	//���ֽ��������ݺϲ�
	}
}


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : �������򣨵ݹ�棩
 *  @param       : ����ָ��a���������begin�������յ�end
 */
void QuickSort_Recursion(int *a, int begin, int end)
{
	if(begin <= end){
		int mid = Partition(a, begin, end);			//������
		QuickSort_Recursion(a, begin, mid-1);		//����ֿ�������һ�߼���������
		QuickSort_Recursion(a, mid+1, end);			//��һ�߼���������
	}
}


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : �������򣨷ǵݹ�棩
 *  @param       : ����ָ��a�����鳤��size
 */
void QuickSort(int *a,int size)
{
	SqStack s;						//����һ��ջ
	initStack(&s, size);			//��ʼ��
	int begin = 0;					//�����յ��±�
	int end = size - 1;
	pushStack(&s,begin);			//��ͷβ�±���ջ
	pushStack(&s,end);
    while(!isEmptyStack(&s))		//ջ��Ϊ��
    {
        getTopStack(&s, &end);		//������ջ�����ݣ���ջ
        popStack(&s);
        getTopStack(&s, &begin);
        popStack(&s);
        int mid = Partition(a, begin, end);
        if (mid - 1 < begin)		//ջ���������±��м�������ᣬ��������ͷ����������β��ջ
        {							//ѭ����������ȫ����ջ
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
 *  @description : �������������ţ�
 *  @param       : ����ָ��a���������begin�������յ�end
 */
int Partition(int *a, int begin, int end)
{
	int temp;
	int i = begin+1, mid = begin;
	while(i <= end){				//��һ��Ԫ�ص�����Ԫ�أ��ӵڶ���Ԫ�ؿ�ʼ����
		if(a[i]<a[begin]){			//������Ԫ��С�ķ�������Ԫ�غ���
			temp = a[mid+1];		//������Ԫ�ش�ķ���С�ĺ���
			a[mid+1] = a[i];
			a[i] = temp;
			mid++;
		}
		i++;
	}
	temp = a[mid];					//������Ԫ�ؽ�����СԪ��������Ԫ�ػ���λ��
	a[mid] = a[begin];
	a[begin] = temp;
	return mid;
}


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : ��������
 *  @param       : ����ָ��a�����鳤��size���������ֵmax
 */
void CountSort(int *a, int size , int max)
{
	int *s = (int*)malloc((max+1)*sizeof(int));		//�����±꺬�������ݵ�����
	for(int i=0; i<max+1; i++)						//�������飬����ĳ�����ݣ�������ĳ������Ϊ�±������Ԫ�ؼ�1
		s[i] = 0;									//��ʾ�������±�ֵ��ȵ����ݵĸ���
	for(int i=0; i<size; i++){
		int temp = a[i];
		s[temp]++;
	}
	int i=0;
//	for(int i=0; i<max+1; i++)
//		printf("%d ",s[i]);
//	printf("\n");
//	getchar();
	for(int temp=1; temp<max+1;){					//�������飬��ֵ��Ϊ��ʱ�����±���ΪԪ�ط���a
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
 *  @description : ������������
 *  @param       : ����ָ��a�����鳤��size
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
		int lose;				//cnt��¼ѭ��������lose���ڽ�λ����
		if(cnt == 0)
			lose = 1;
		else
			lose *= 10;
		for(int i=0;i<size;i++){
			int temp = (int)(a[i] / lose % 10);		//%10ȡ�����һλ
			int sum = ++s[temp][0];					//��¼ȡ��λ���ֵ��±�ָ����ָ���ݵĸ���
			s[temp][sum] = a[i];					//���ݷ�����±���ָ������s��
		}
		if(!(s[0][0]!=size))						//�����������浽s[0]�У�֤��������ɹ����˳�ѭ��
			break;
		int temp = 0;
		for(int i=0; i<10; i++){					//��s�е����ݰ���һ��˳������ŵ�a��ȥ
			for(int j=1; s[i][0]!=0; j++){
				a[temp++] = s[i][j];
//				printf("%d %d",temp-1,a[temp-1]);getchar();
				s[i][0]--;
			}
		}
		cnt++;										//��¼ѭ����������������
	}
	for(int i=0; i<10; i++){
		free(s[i]);
	}
}


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : ��ɫ����
 *  @param       : ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
 */
void ColorSort(int *a,int size)
{
	int begin = 0, end = size - 1, p = 0;
	while(p != end){					//p��endδ���ʱ��δ��������Ԫ��
//		printf("begin=%d end=%d p=%d",begin,end,p-1);getchar();
		if(a[p] == 1)					//����һʱp�ߵ���һ��
			p++;
		if(a[p] == 0){					//������ʱ��begin��λ��
			a[p] = a[begin];
			a[begin++] = 0;
		}
		if(a[p] == 2){					//���ڶ�ʱ��end��λ��
			a[p] = a[end];
			a[end--] = 2;
		}
	}
}

/**
 *  @name        : int Findnum(int *a, int size)
 *  @description : ��һ�������������ҵ���KС����
 *  @param       : ����ָ��a�����鳤��size
 */
int Findnum(int *a, int size)
{
	if( K > size )					//�ж�K�Ƿ񳬳������С
		return 0;
	int *temp = (int*)malloc(size*sizeof(int));
	for(int i=0;i<size; i++){
		temp[i] = a[i];				//����a��temp
	}
	insertSort(temp,size);			//��temp��������
	int KNum = temp[K-1];			//��Ŀ��������ȡ��
	free(temp);						//free temp
	return KNum;					//����Ŀ������
}

