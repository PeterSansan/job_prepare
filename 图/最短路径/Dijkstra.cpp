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
using namespace std;


/*总结Dijkstra基本思想：
1、把顶点分为已知最短路径和未知最短路径的集合P与Q
2、每次找到离源点最近的一个顶点u，把这个源点归入集合P
3、以该顶点u进行扩展，比较与u有相接的下一个点与源点的最短距离，更新
4、重复2，直到n-1个点都进行这样的操作终止。*/
int main()
{
	int e[10][10], dis[10], book[10], i, j, n, m, t1, t2, t3, u, v, min;
	int inf = 99999999;	//表示无穷大的值
	
	cin >> n >> m;
	//初始化
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (i == j)
				e[i][j] = 0;
			else
				e[i][j] = inf;
	//读入边
	for (i = 1; i <= m; i++)
	{
		cin >> t1 >> t2 >> t3;
		e[t1][t2] = t3;
	}
	//初始化dis数组，这里是1号顶点到其余各个顶点的初始路程 
	for (i = 1; i <= n; i++)
		dis[i] = e[1][i];


	//book数组初始化
	for (i = 1; i <= n; i++)
		book[i] = 0;

	book[1] = 1;//起源点加入集合P
	//Dijkstra算法核心语句
	//分为两个集合，已知最智囊路径的点P，未知最短路径的点Q
	for (i = 1; i <= n - 1; i++)	//要判断n-1次，即去掉源结点
	{
		//找到离1号顶点最近的顶点
		min = inf;
		for (j = 1; j <= n; j++)
		{
			if (book[j] == 0 && dis[j] < min)
			{
				min = dis[j];
				u = j;
			}
		}
		book[u] = 1;//最近的那个顶点，放入集合P，这句很关键
		for (v = 1; v <= n;v++)	//判断源点与u点指向所有下个节点的最短距离
		{ 
			if (e[u][v] < inf)	//如果u点与其他点没有连接则跳过
			{
				if (dis[v] > dis[u] + e[u][v])	//判断源点到u下一个点的距离是否为最小，更新
					dis[v] = dis[u] + e[u][v];
			}
		}
	}
	//输出最终的结果
	for (i = 1; i <= n; i++)
		cout << dis[i]<<" ";

	return 0;
}


