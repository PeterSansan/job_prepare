#include<iostream>
#include <fstream>
using namespace std;

//O(n),来自《数据结构与算法分析——C语言描述》
//简要原理：在第n个正数上，前面累加的结果必须是正数才有意义，
//后面累加的结果必须大于前面累加之和才会更新
int MaxSubsequenceSum(const int A[], int N)
{
	int ThisSum, MaxSum, j;

	ThisSum = MaxSum = 0;
	for (j = 0; j < N; j++)
	{
		ThisSum += A[j];
		if (ThisSum >MaxSum)
			MaxSum = ThisSum;
		else if (ThisSum < 0)
			ThisSum = 0;
	}
	return MaxSum;
}
// 主函数
int main()
{
	int A[6] = { -2,11,-4,13,-5,-2};

	cout << MaxSubsequenceSum(A, 6)<<endl;
	//system("pause");
	return 0;
}