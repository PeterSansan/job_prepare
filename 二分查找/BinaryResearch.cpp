/*顺序表示例代码*/
#include<iostream>
#include <fstream>
#include<time.h>
#include<stdlib.h>
#include<math.h>

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

//二分查找，不检查输入的范围
int binary_research(int arr[], int left, int right, int element)
{
	int mid;
	while (left <= right)
	{
		
		mid = left - (left - right) / 2; //防止越界
		//int mid = (left + right) //这句会越界
		if (arr[mid] > element)
		{
			right = mid - 1;
		}
		else if (arr[mid] < element)
		{
			left = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

int main()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int right = 14;
	int left = 0;//定义右下标并初始化为0  
	int element = 0;//定义查找的元素并初始化为0  
	cout<<"请输入要查找的元素>";
	cin >> element;
	int location = binary_research(array, left, right, element);
	if (location >= 0)
		cout<<"The element's location is %d\n"<<location<<endl;
	else
		cout<<"Don't exit this element.\n"<<endl;
	return 0;
}