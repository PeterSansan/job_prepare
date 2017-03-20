/*顺序表示例代码*/
#include<iostream>
#include <fstream>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include <stack>  
#include <queue> 
#include <vector>  
#include <string>  
#include <random>  
#include <algorithm>  
#include <cmath>
using namespace std;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;//函数结果状态代码，如OK等
typedef int ElemType;
typedef int SElemType;
typedef int QElemType;	
#define MAXSIZE 100

//常用到的交换函数
void swap(int &i,int &j)	//L为数组的坐标
{
	int temp = i;
	i = j;
	j = temp;
}
//0.冒泡排序,复杂度O(n2)
void BubbleSort(int a[], int n)
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n-1-i; j++)		//每次冒泡比较最大的数，放在高地址
			if (a[j]>a[j+1])
				swap(a[j], a[j + 1]);
}
//1.改进的冒泡排序
void BubbleSortA(int a[], int n)
{
	int i, j;
	Status flag = TRUE;
	for (i = 0; i < n && flag; i++)
	{
		flag = FALSE;	//初始为false
		for (j = 0; j < n - 1 - i; j++)
		{
			if (a[j]>a[j+1])
			{
				swap(a[j], a[j + 1]);
				flag = TRUE;
			}
		}
	}
}
//2.选择排序，逐次选择最小的值与下标序列交换，复杂度O(n2)
void SelectSort(int a[], int n)
{
	int i, j, min;
	for (i = 0; i<n - 1; i++)
	{
		min = i;//查找最小值
		for (j = i + 1; j<n; j++)
			if(a[min]>a[j])
				min = j;//交换
		if (min != i)
			swap(a[min], a[i]);
	}
}
//3.直接插入排序，时间复杂度为O(n2)
//这个代码我理解了好久
//思想是：
//第一轮：下标为1的数与坐标为0的数比较，如果下标为1的数小于下标为0的数，则交换两个数，进入下一循环；
//第二轮，下标为2的数与坐标为1的数比较，如果下标为2的数小于下标为1的数，则交换两个数；
//			交换后如果坐标为1的数小于坐标为0的数，则交换两个数,每一次插入后前面的序列都是排好的。
//...
void InsertSort(int a[], int n)
{
	for (int i = 1; i < n; i++) {
		int j = i;
		while (j > 0 && (a[j] < a[j - 1])) {
			swap(a[j],a[j-1]);
			j--;
		}
	}
}
//4.不用swap函数的插入排序，这种方法效率比上者高一点，因为真正交换值只用了一次
void InsertSortA(int a[], int n)
{
	int i, j, temp;
	for (i = 1; i<n; i++)
	{
		temp = a[i];
		j = i;
		while ((j>0) && (temp<a[j - 1]))
		{
			a[j] = a[j - 1];
			j--;
		}
		a[j] = temp;
	}
}
void insert_sort(int a[], int n)
{
	int i, j, temp;
	for (i = 1; i < n; i++)
	{
		//暂存下标为i的数。下标人1开始，因为开始时下标为0的数，前面没有可以比较的数，即为排好的数
		temp = a[i];
		for (j = i - 1; j >= 0&& temp < a[j]; j--)	//要插入的数比上一个数小，甚至比上上个数小
		{
			//如果满足条件就后往后退。最坏的情况就是temp比a[0]小，它要放在最前面。
			a[j + 1] = temp;	//后退一步
		}
		a[j + 1] = temp;//打到下标为i的数的放置数据，即插入成功。
	}
}
//5.希尔排序
void ShellSort(int a[], int n)
{
	int i, j, gp, temp;
	gp = n / 2;
	//分组进行插入排序，如数据是{3,6,2,9,1,7,8,4,5,0}
	//第一轮对5组进行插入排序：h = [3,7],[6,8],[2,4],[9,5],[1,0]
	//第二轮对2组进行插入排序：
	//第三轮对1组进行插入排序：
	for (gp = n / 2; gp > 0;gp = gp/2)	//增量(组)减半
	{
		for (i = gp; i < n; i++)
		{
			temp = a[i];
			j = i;
			while ((j - gp >= 0) && (temp < a[j - gp]))
			{
				a[j] = a[j - gp];
				j = j - gp;
			}
			a[j] = temp;
		}
	}
}
void ShellSortA(int a[], int n)
{
	int i, j, gp;
	gp = n / 2;
	for (gp = n / 2; gp > 0; gp = gp / 2)	//增量(组)减半
	{
		for (i = gp; i < n; i++)
		{
			j = i;
			while ((j - gp >= 0) && (a[j] < a[j - gp]))
			{
				swap(a[j], a[j - gp]);
				j = j - gp;
			}
		}
	}
}

//6.堆排序
//建立最大堆
void Heapfy(int A[], int idx, int len)      //建立最大堆
{
	int left = (idx<<1) + 1;//等于idx*2+1; //左子孩子
	int right = left + 1;					//右子孩子

	int largest = idx;

	if (left< len && A[left]>A[largest])//len是长度，所以不能用等号
		largest = left; 
	if (right< len && A[right]>A[largest])
		largest = right;			//最大值指向左右结点

	if (largest != idx)
	{
		swap(A[largest], A[idx]);
		//A[idx]现在是最大值，而largest还是左右结点
		Heapfy(A, largest, len); //递归遍历  
	}
}
void HeapSort(int A[], int n)
{
	int len = n;

	for (int i = len / 2 ; i >= 0; i--)
	{ 
		Heapfy(A, i, len);     //建立最大堆，将堆中最大的值交换到根节点  
	}

	for (int i = len - 1 ; i > 0; i--)
	{
		swap(A[0],A[i]);   //将当前堆的根节点交换到堆尾的指定位置  
		Heapfy(A, 0, i);   //建立下一次的最大堆  
	}
}
//7.归并排序
void Merge(int a[], int tmp[], int lPos, int rPos, int rEnd)
{
	int i, lEnd, NumElements, tmpPos;
	lEnd = rPos - 1;	
	tmpPos = lPos;			//从左端开始
	NumElements = rEnd - lPos + 1;	//从左端开始

	while (lPos <= lEnd && rPos <= rEnd)
	{
		if (a[lPos] <= a[rPos])
			tmp[tmpPos++] = a[lPos++];//比较两端的元素值
		else
			tmp[tmpPos++] = a[rPos++];
	}
	//到这里，左端或右端只能有一端还可能含有剩余元素
	while (lPos <= lEnd)	//把左端剩余的元素放入tmp
		tmp[tmpPos++] = a[lPos++];
	while (rPos <= rEnd)	//把右端剩余的元素放入tmp
		tmp[tmpPos++] = a[rPos++];	
	for (i = 0; i < NumElements; i++)	//把temp的数组拷到a
	{
		a[i] = tmp[i];
	}
}
void MSort(int a[], int tmp[], int left, int right)
{
	if (left >= right)		//结束条件，原子结点return 
		return;
	int middle = left - (left - right) / 2;
	MSort(a,  tmp, left, middle);
	MSort(a, tmp, middle+1, right);
	Merge(a, tmp, left, middle + 1, right);
}
void MergeSort(int a[], int len)
{
	int *tmp = NULL;	
	tmp = new int[len];	//分配临时数组空间
	if (tmp != NULL)
	{
		MSort(a, tmp, 0, len - 1);	//调用msort归并排序
		delete []tmp;
		tmp = NULL;
	}
}
//8.快速排序
void QSort(int a[], int left, int right)
{
	int l, r, pivot;
	if (left < right)
	{
		pivot = a[left];	//用子表的第一个记录作枢轴记录
		l = left;
		r = right;
		while (l < r)
		{
			while (l < r && a[r] >= pivot)
				r--;
			if (l < r)
				a[l++] = a[r];	//将比pivot小的元素移到低端

			while (l < r && a[l] <= pivot)
				l++;
			if (l < r)
				a[r--] = a[l];		//将比pivot大的元素移到高端
		}
		a[l] = pivot;
		QSort(a, left, l - 1);	//对左区间递归排序
		QSort(a, l + 1, right);//对右区间递归排序
	}
}
void QuickSort(int a[], int n)
{
	QSort(a,0,n-1);
}
int main()
{
	//冒泡算法
	int a[10] = {4,6,9,1,2,5,3,8,7};
	cout << "原始数据：";
	for(int i = 0; i < 9; i++)
		cout << a[i]<<" ";
	cout << endl;
	//ShellSortA(a, 9);
	//HeapSort(a, 9);
	QuickSort(a, 9);
	//MergeSort(a, 9);
	//打印数据
	cout << "排序后数据：";
	for(int i = 0; i < 9; i++)
		cout << a[i] << " ";
	cout << endl;

	return 0;
}


