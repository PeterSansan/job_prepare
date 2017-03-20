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
#include <vector>
#include <string>
#include <map>
#include <sstream>  //字符串调用读写
#include <fstream>  //文件调用读写
using namespace std;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;//函数结果状态代码，如OK等
typedef int ElemType;
typedef int SElemType;
typedef int QElemType;	
#define MAXSIZE 1000


int main()
{
	stack<string> ss;
	string s;
	while (cin >> s)
	{
		ss.push(s);
	}
	while (!ss.empty())
	{
		cout << ss.top();
		ss.pop();
		if (!ss.empty())
			cout << ' ';
	}
	cout << endl;
	
	return 0;
}


