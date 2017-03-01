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

//0.双向链表的结构
typedef struct DulNode
{
	ElemType data;
	DulNode *prior;	//直接前驱指针
	DulNode *next;  //直接后继指针
}DulNode, *DulinkList;

//1.初始化整表双向链表，尾插法
DulinkList InitDulList(int n)
{
	DulinkList Dul,r,p;	//只是地址
	Dul = (DulinkList)malloc(sizeof(DulNode));
	Dul->data = 0;
	Dul->prior = NULL;
	Dul->next = NULL;
	r = Dul;
	
	for (int i = 0; i < n; i++)
	{
		p = (DulinkList)malloc(sizeof(DulNode));
		p->data = i;
		r->next = p;
		p->prior = r;
		r = r->next;
	}
	r->next = NULL;
	return Dul;
}
//2.打印双向链表
void PrintDulinkList(DulinkList Dl)
{
	DulinkList dl = Dl->next;
	while (dl!=NULL)
	{
		cout << dl->data<<" ";
		dl = dl->next;
	}
	cout << endl;
}
//3.插入一个元素
Status DulListInsert(DulinkList &Dl,int n,int e)
{
	DulinkList p, r;
	int i=1;
	r = Dl->next;	//第一个结点；
	p = (DulinkList)malloc(sizeof(DulNode));
	p->data = e;
	while (r && i <= n - 1)
	{
		r = r->next;
		i++;
	}
	if (!r || i > n)
		return ERROR;
	p->next = r->next;
	p->prior = r;
	r->next->prior = p;
	r->next = p;

	return OK;
}
//4.删除一个元素
Status DuListDelete(DulinkList &Dl, int n, int *e)
{
	int j = 1;
	DulinkList p = Dl;
	p = p->next;
	while (p&&n >= j)
	{
		p = p->next;
		j++;
	}

	p->prior->next = p->next;
	p->next = p->prior;
	free(p);
	return OK;
}
// 主函数
int main()
{
	DulinkList Dull = InitDulList(10);
	PrintDulinkList(Dull);
	//插入一个元素
	DulListInsert(Dull, 3, 34);
	PrintDulinkList(Dull);
	//删除一个元素
	int e = 0;
	DuListDelete(Dull,3, &e);
	PrintDulinkList(Dull);
	return 0;
}