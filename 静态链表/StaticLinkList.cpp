/*顺序表示例代码*/
#include<iostream>
#include <fstream>
#include<time.h>
#include<stdlib.h>

using namespace std;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;//函数结果状态代码，如OK等
typedef int ElemType;


//1.线性表的静态链表存储结构
#define MAXSIZE 1000	//假设链表的最大长度是1000
typedef struct
{
	ElemType data;
	int cur;	//游标，为0进表示无指向
}Component, StaticLinkList[MAXSIZE];

//2.将一维数据space中各分量链成一备用链表
Status InitList(StaticLinkList space) //数据名为地址
{
	int i;
	for (i = 0; i < MAXSIZE - 1; i++)
		space[i].cur = i + 1;
	space[MAXSIZE - 1].cur = 0;//目前静态链表为空，最后一个元素为cur为0
	return OK;
}
//3.当链表链接使用一个时，把备用链表索引到下一个
int Malloc_SSL(StaticLinkList space)
{
	int i = space[0].cur; //当前数组第一个元素的cur存的值

	if (space[0].cur)
		space[0].cur = space[i].cur; //由于要拿出一个分量来使用了，所以我们就得把它的下一个分量用来做备用
	return i;
}
//4.静态链表L元素的个数
int ListLength(StaticLinkList L)
{
	int j = 0;
	int i = L[MAXSIZE - 1].cur;			//i指向头结点
	while(i)
	{
		i = L[i].cur;
		j++;
	}
	return j;
}
//5、插入新元素e
Status ListInsert(StaticLinkList L, int i, ElemType e)
{
	int j, k, l;
	k = MAXSIZE - 1;	//注意k首先是最后一个元素的下标
	if (i<1 || i>ListLength(L) + 1)
		return ERROR;
	j = Malloc_SSL(L);	//获得空闲分量的下标,j是新结点的地址
	if (j)
	{
		L[j].data = e;	//将数据赋值给此分量的data
		for (l = 1; l <= i - 1; l++)	//找到第i个元素之前的位置
			k = L[k].cur;			//k是要插入元素的地方，即k的后面插入数据
		L[j].cur = L[k].cur;//把第i个元素之前的cur赋值给新元素的cur，数据最
		L[k].cur = j;//把新元素的下标赋值给第i个元素之前元素的cur
		return OK;
	}
	return ERROR;
}

//7.删除元素
Status ListDelete(StaticLinkList L, int i)
{
	int j, k;
	if (i<1 || i>ListLength(L))
		return ERROR;

	k = MAXSIZE - 1;
	for (j = 1; j <= i - 1; j++)
		k = L[k].cur;
	j = L[k].cur; //存储要删除的元素的地址
	L[k].cur = L[j].cur;
	//下面也可以调用Free_SSL()函数
	L[j].cur = L[0].cur;	//把第一个元素cur值赋给要删除的分量cur
	L[0].cur = j;			//把要删除的分量下标赋值给第一个元素的cur
	return OK;
}
//8、将下标为k的空闲结点回收到备用链表
void Free_SSL(StaticLinkList space, int k)
{
	space[k].cur = space[0].cur;
	space[0].cur = k;
}
//9.打印静态链表的数据
void PrintSList(StaticLinkList Slist)
{
	int k = Slist[MAXSIZE - 1].cur;	//k为第一个有数据的结点
	while (k)
	{
		cout << Slist[k].data << " ";
		k = Slist[k].cur;
	}
	cout << endl;
}
// 主函数
int main()
{
	StaticLinkList Slist;
	//初始化静态表
	InitList(Slist);
	//插入元素
	for (int i = 0; i < 10; i++)
		ListInsert(Slist, i + 1, i + 1);
	//静态链表的长度
	cout<<"静态链表的长度是："<<ListLength(Slist)<<endl;
	//打印静态链表的数据
	PrintSList(Slist);
	//删除第3个数据
	ListDelete(Slist, 3);
	PrintSList(Slist);

	return 0;
}