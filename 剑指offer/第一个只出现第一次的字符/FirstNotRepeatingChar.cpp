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
char FirstNotRepeatingChar(const char* pString)
{
	if (pString == NULL)
		return '\0';

	const int tableSize = 256;
	unsigned int hashTable[tableSize];
	for (unsigned int i = 0; i<tableSize; ++i)
		hashTable[i] = 0;

	const char* pHashKey = pString;
	while (*(pHashKey) != '\0')
		hashTable[*(pHashKey++)] ++;

	pHashKey = pString;
	while (*pHashKey != '\0')
	{
		if (hashTable[*pHashKey] == 1)
			return *pHashKey;

		pHashKey++;
	}

	return '\0';
}


int main()
{
	string str; //定义string变量作为输入
	cin >> str;
	const char *s = str.c_str();	//一种string转char *的方法，另一种是.data(),不过都是转为const
	//char *str = "google";
	cout << FirstNotRepeatingChar(s);
	return 0;
}

