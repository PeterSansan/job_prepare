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
#define MAXSIZE 100
/*
首先选取数组中右上角的数字。如果该数字竺要查找的数字，查找过程结束；如果该数字大于要查找的数字，剔除这个数字所在的列；
如果该数字小于要查找的数字，剔除这个数字所在的行。这就是说如果要查找的数字不在数组的右上角，则每一次都在数组的查找范围中剔除
一行或者一列，这样每一步都可以缩小查找的范围，直到找到要查找的数字，或者查找范围为空。
*/
bool Find(vector<vector<int>> v,int r,int c,int number)
{
	int row = 0;
	int column = c - 1;
	while (row < r && column >= 0)
	{
		if (v[row][column] == number)
			return TRUE;
		else if (v[row][column] > number)
			column--;
		else
			row++;
	}
	return FALSE;
}

int main()
{
	int row,column;
	int number;
	cin >> row >> column;
	vector<vector<int> > v(row, vector<int>(column));
	//输入数据
	for (auto &l : v)
		for (auto &r : l)
			cin >> r;
	cin >> number;
	if (Find(v, row, column, number))
		cout << "T";
	else
		cout << "F";

	return 0;
}

