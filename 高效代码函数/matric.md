## 随意大小矩阵的输入

```
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
	int L , R  ;
	cin >> L>>R;
	vector<vector<int> > v(L, vector<int>(R));
	
	//输入矩阵数据
	for (auto &l : v)
		for (auto &r : l)
			cin >> r;

	//输出矩阵数据
	for (auto s : v)
	{
		for (auto r : s)
			cout << r << " ";
		cout << endl;
	}
	return 0;
}
```