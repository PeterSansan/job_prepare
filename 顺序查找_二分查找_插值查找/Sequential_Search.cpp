/*顺序表示例代码*/
#include<iostream>
#include <fstream>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include <stack>  
#include <queue> 

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

//顺序查找
//注意这里例子的数组开始是从下标1开始的。
int Sequential_Search(int *a, int n, int key)
{
	int i;
	for (i = 1; i <= n; i++)
	{
		if (a[i] == key)
			return i;
	}
	return 0;
}
//有哨兵顺序表查找
int Sequential_Search2(int *a, int n, int key)
{
	int i;
	a[0] = key;
	i = n;
	while (a[i]!=key)
	{
		i--;
	}
	return i;		//返回0则说明查找失败
}

int main()
{
	int a[] = {1,3,55,2,10,45};
	cout<<Sequential_Search(a, 6, 10);
	return 0;
}