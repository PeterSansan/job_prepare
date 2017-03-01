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
#define MAXSIZE 100


//斐波那契数列的两种编程方法
//1.递归法
int Fbi(int n)
{
	if (n < 2)
		return n == 0 ? 0 : 1;
	return Fbi(n-1)+Fbi(n-2);
}
//2.迭代法
int Fbi_b(int n)
{
	int fbi[100] = {1,1};
	for (int i = 2; i < n; i++)
		fbi[i] = fbi[i - 1] + fbi[i - 2];
	return fbi[n-1];
}
// 主函数
int main()
{
	cout <<"递归法输出"<< Fbi(6) << endl;
	cout << "迭代法输出" << Fbi_b(6) << endl;
	return 0;
}