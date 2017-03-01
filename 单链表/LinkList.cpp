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


//0.定义单链表节点
typedef struct Node
{
	ElemType data;
	Node *next;
}Node;

typedef Node *LinkList;//LinkList是链表头地址或节点的首地址，链接与节点索引都只是一个地址，这个结构很神奇

//1.从链表中获取一个元素
Status GetElem(LinkList L, int i,ElemType *e)
{
	int j;
	LinkList p;	//声明一结点
	p = L->next;	//让p指向链表L的第一个结点（非头结点）
	j = 1; //j为计数器
	while (p && j < i)  //p不为空或者计数器j还没有等于i时，循环继续
	{
		p = p->next;
		++j;
	}
	if (!p || j>i) //p为空是查找过头了，j>i是避免索引i为负
		return ERROR;	//第i个元素不存在
	*e = p->data;//取第i个元素的数据
	return OK;
}
//2.单链表的插入
Status ListInsert(LinkList *L, int i, ElemType e)
{
	int j;
	LinkList p, s;
	p = *L;
	j = 1;
	while (p&&j < i)//寻找第i个结点
	{
		p = p->next;
		++j;
	}
	if (!p || j>i)
		return ERROR;	//第i个元素不存在
	s = (LinkList)malloc(sizeof(Node));//生成新结点（C标准函数）
	s->data = e;
	s->next = p->next; //将p的后继结点赋值给s的后继
	p->next = s;	//将s赋值给P的后继
	return OK;
}
//3.删除节点,类似上面，不过把地址传递，改为引用
Status ListDelete(LinkList &L, int i, ElemType *e)
{
	int j;
	LinkList p, q;
	p = L;
	j = 1;
	while (p->next &&j < i)	//遍历寻找第i个元素
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j>i)
		return ERROR;
	q = p->next;			
	p->next = q->next;		//将q的后继赋值给p的后继
	*e = q->data;			//将q站点中的数据给e
	free(q);				//让系统回收此结点，释放内存
	return OK;
}
//4.单链表的整表创建（头插法）
/*随机产生n个元素的值，建立带表头结点的单链性表L(头插法)*/
//随机产生n个元素的值，建立单链线性表，如要带空表头，把for中的n-1改为n（头插法）
LinkList CreateListHead(int n)
{
	LinkList pLinkList, p;
	int i;
	srand(time(0));        //初始化随机数种子
	pLinkList = (LinkList)malloc(sizeof(Node));    //
	pLinkList->data = 0;
	pLinkList->next = NULL;    //先建立一个带头的单链表

	for (i = 0; i<n - 1; i++)
	{
		p = (LinkList)malloc(sizeof(Node));    //生成新结点
		p->data = rand() % 100 + 1;    //随机生成100以内的数字
		p->next = pLinkList->next;
		pLinkList->next = p;    //插入列表头 
	}
	return pLinkList;
}
//5.单链表的整表创建，尾插法
//随机产生n个元素的值，建立单链表，如要带空表头，把for中的n-1改为n（尾插法）
LinkList CreateListTail(int n)
{
	LinkList pLinkList, r, p;
	int i;
	srand(time(0));        //初始化随机数种子
	pLinkList = (LinkList)malloc(sizeof(Node));    //为整个线性表
	pLinkList->data = 0;                        //为整个
	pLinkList->next = NULL;    //先建立一个带头的单链表 

	r = pLinkList;
	for (i = 0; i<n - 1; i++)
	{
		p = (Node*)malloc(sizeof(Node));    //生成新结点
		p->data = rand() % 100 + 1;    //随机生成100以内的数字
		r->next = p;
		r = p;                //将生成的新结点定义为表尾终端结点 
	}
	r->next = NULL;            //表示当前链表结束 
	return pLinkList;
}
//6.手动建立单链表,尾插法 
LinkList ManCreList()
{
	LinkList head, p, s;
	int x= 1;
	head = (Node*)malloc(sizeof(Node));    //建立头节点
	p = head;
	cout << "Please input the data or press (CTRL+C):" << endl;
	while (1)
	{
		if (cin >> x)//输入EOF结束，win平台是Ctrl+z
		{
			s = (Node*)malloc(sizeof(Node));    //第次新建一个节点
			s->data = x;                        //新结点赋值 
			p->next = s;                        //链表指向新节点 
			p = s;                             //新节点成链表最后一个元素 
		}
		else
			break;
	}
	head = head->next;
	p->next = NULL;
	return head;
}
//7.打印链表
//单链表打印,一般方法 
void PrintList(LinkList head)
{
	LinkList p;
	printf("\nNow,These data are :\n");
	p = head;
	while (p != NULL)
	{
		cout << p->data<<" ";
		p = p->next;
	}
	cout << endl;
}
//递归方法的打印链表
//单链表打印，递归方法 
void PrintNode(const LinkList pLinkNode)
{
	if (pLinkNode)
	{
		cout<<pLinkNode->data<<" ";
		PrintNode(pLinkNode->next);
	}
	cout << endl;
}
//8.整表删除
Status ClearList(LinkList &L)
{
	LinkList p, q;
	p = L->next;	//p指向第一个结点
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;	//头结点指针域为空
	return OK;
}

// 主函数
int main()
{
	int num = 0;
	//随机链表生成，头插法
	LinkList ll = CreateListHead(10); 
	PrintList(ll);
	//随机链表生成，尾插法
	LinkList lt = CreateListTail(10);
	PrintNode(lt);
	//获取链表中一个元素
	if (GetElem(lt, 1, &num))
		cout << num << endl;
	else
		cout << "ERROR" << endl;
	//插入一个元素
	if (ListInsert(&ll, 1, 43))
		PrintList(ll);
	//删除一个元素
	if (ListDelete(ll, 5, &num))
		PrintList(ll);
	//删除整个链表
	if (ClearList(ll))
		cout << "Delete Success." << endl;
	Print(lt);
	return 0;
}