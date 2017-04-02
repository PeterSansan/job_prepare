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


int main()
{
	string str;
	getline(cin, str);
	auto fi = str.find(' ', 0);
	while (fi != string::npos)
	{
		str.replace(fi, 1, "%20");
		fi = str.find(' ', fi + 1);
	}
	cout << str << endl;
	return 0;
}

