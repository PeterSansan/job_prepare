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


int main()
{
	stack<int> mystack;
	for (int i = 0; i < 5; i++)
		mystack.push(i);	//压入栈
	std:cout << "Popping out elements...";
	while (!mystack.empty())
	{
		cout << " " << mystack.top();
		mystack.pop();//出栈
	}


	//两端队列
	int e, n, m;
	queue<int> q1;  //队列的初始化
	for (int i = 0; i<10; i++)
		q1.push(i);  //从后压入队列
	if (!q1.empty())
		cout << "the queue isn't empty" << endl;

	n = q1.size();    //输出队列的大小
	cout << n << endl;

	m = q1.back();
	cout << m << endl;   //读取队列最一个元素

	for (int j = 0; j<n; j++)
	{
		e = q1.front();    //读取第一个元素
		cout << e << " ";
		q1.pop();        //移除第一个元素
	}
	cout << endl;
	if (q1.empty())
		cout << "the queue is empty\n";


	const int len = 5;
	int i;
	int a[len] = { 3, 5, 9, 6, 2 };

	//优先队列
	priority_queue<int> qi;
	for (i = 0; i < len; i++)
		qi.push(a[i]);
	for (i = 0; i < len; i++)
	{
		cout << qi.top() << " ";    //自动排序,大的数在顶层,优先弹出
		qi.pop();
	}
	cout << endl;
	return 0;
}

