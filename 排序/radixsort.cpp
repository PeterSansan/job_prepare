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
#include <vector>
#include <string>
#include <map>
#include<cctype>
#include <sstream>  //字符串调用读写
#include <fstream>  //文件调用读写
using namespace std;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;//函数结果状态代码，如OK等
typedef int ElemType;
#define MAXSIZE 1000

/*
* 打印数组
*/
void printArray(int array[], int length)
{
	for (int i = 0; i < length; ++i)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}
/*
*求数据的最大位数,决定排序次数
*/
int maxbit(int data[], int n)
{
	int d = 1; //保存最大的位数  
	int p = 10;
	for (int i = 0; i < n; ++i)
	{
		while (data[i] >= p)
		{
			p *= 10;
			++d;
		}
	}
	return d;
}
void radixsort(int data[], int n) //基数排序  
{
	int d = maxbit(data, n);
	int tmp[10];
	int count[10]; //计数器  
	int i, j, k;
	int radix = 1;
	for (i = 1; i <= d; i++) //进行d次排序  
	{
		for (j = 0; j < 10; j++)
			count[j] = 0; //每次分配前清空计数器  
		for (j = 0; j < n; j++)
		{
			k = (data[j] / radix) % 10; //统计每个桶中的记录数  
			count[k]++;	
		}
		for (j = 1; j < 10; j++)		//count变成累加的形式
			count[j] = count[j - 1] + count[j]; //将tmp中的位置依次分配给每个桶  

		for (j = n - 1; j >= 0; j--) //将所有桶中记录依次收集到tmp中  
		{
			k = (data[j] / radix) % 10;	//各个位数,count[k]的值都大于等于1
			tmp[count[k] - 1] = data[j]; 
			count[k]--;					//主要是为了相同的数着想，减一就是当出现相同的数把这个数存在下一位。
		}
		for (j = 0; j < n; j++) //将临时数组的内容复制到data中  
			data[j] = tmp[j];
		radix = radix * 10;
	}
}
int main() 
{
	int array[10] = { 73, 22, 93, 43, 55, 14, 28, 65, 39, 81 };
	radixsort(array, 10);
	printArray(array, 10);
	return 0;
}


