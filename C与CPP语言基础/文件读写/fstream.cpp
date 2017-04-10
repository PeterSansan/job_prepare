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
#define MAXSIZE 1000

int main() 
{
	int n;
	string buff;
	ofstream outfile("stringout.txt",ios::app);
	ifstream intfile("string.txt", ios::in);
	
	if (outfile.is_open())
	{
		outfile << "This is a line.\n";
		outfile << "This is another line.\n";
		outfile.close();
	}
	while (getline(intfile, buff))
		cout << buff << endl;
	return 0;
}


