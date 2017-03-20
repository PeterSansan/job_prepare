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
#define MAXSIZE 100


int main()
{
	string str("Hello the world");
	cout << str << endl;

	//cnost的使用,引用篇
	const int a = 1024;
	const int &b = a; 
	//b = 4;	//错误
	//int &c = a;	//错误，无法从const int 转换为int &,限定符会被丢弃

	int d = 43;
	const int &e = d;//允许将const int 绑定到一个普通int对象上
	const int &f = 32;	//	是一个常量引用
	const int &g = d * 2; // 是常量引用 
	//int &h = d * 2;	//非常量引用,非常量引用的妆始值必须为左值

	double dval = 3.14;
	const int &ri = dval;
	cout << ri << endl;			//结果为3
	const int temp = dval;	//由双精度浮点数生成一个临时的整型常量
	const int &i = temp;   
	
	//const，指针篇
	const double  pi = 3.14;
	const double x = 3;
	//double *ptr = &pi; //错误:ptr是一个普通指针
	const double * cptr = &pi;
	cptr = &x;

	
	//所谓指向常量的指针或引用，不过是指针或引用“自以为是”罢了，它们觉得自己指向了常量，
	//所以自觉地不去改变所指对象的值
	//const 指针
	int errNumb = 0;
	int *const curErr = &errNumb;	//curErr将一直指向errNumb
	const double pii = 3.13159;
	const double * const pip = &pii;

	//顶层const与底层const的概念
	//顶层const表示指针本身是个常量，而底层const表示指针所指的对象是一个常量。
	
	int ii = 0;
	int *const p1 = &ii;	//不能改变p1的值，这是一个顶层const
	const int ci = 42;//不能改变ci的值，这是一个顶层const
	const int *p2 = &ci;	//允许改变p2的值，这是一个底层const
	const int *const p3 = p2;	//靠右的const是顶层cosnt,靠左的是底层const
	const int &r = ci;	//用于声明引用的const都是底层const
	
	return 0;
}


