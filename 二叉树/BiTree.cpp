/*顺序表示例代码*/
#include<iostream>
#include <fstream>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include <stack>  
#include <queue> 

using namespace std;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;//函数结果状态代码，如OK等
typedef int ElemType;
typedef int SElemType;
typedef int QElemType;	
#define MAXSIZE 100

//0、定义二叉树节点与树的数据结构
typedef struct BiTNode    
{
char   data;
struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

//1.递归创建二叉树
//先序递归创建二叉树  
void CreateBiTree(BiTree &T)
{
	char ch;
	cin >> ch;
	if (ch == '#')
		T = NULL;			
	else
	{
		T = new BiTNode;//如果用malloc的话，T = (BiTree)malloc(sizeof(BiTNode);	
		T->data = ch;				//生成根结点
		CreateBiTree(T->lchild);    //递归创建左子树  
		CreateBiTree(T->rchild);    //递归创建右子树  
	}
}

//2.递归销毁二叉树  
void DestroyBiTree(BiTNode* &T)
{
	if (T)
	{
		DestroyBiTree(T->lchild);
		DestroyBiTree(T->rchild);
		delete T;
		T = NULL;	//必须的
	}
}
//3.前序遍历递归算法
void PreOrder(BiTree T)
{
	if (T)
	{
		cout << T->data << " ";	//显示结点数据 ，可以更改为其他对结点操作
		PreOrder(T->lchild);	//再先序遍历左子树；
		PreOrder(T->rchild);	//最后先序遍历右子树；
	}
}
//4.中序遍历二叉树---递归
void InOrder(BiTree T)
{
	if (T)
	{
		InOrder(T->lchild);
		cout << T->data << " ";
		InOrder(T->rchild);
	}
}
//5.后序遍历二叉树---递归  
void PostOrder(BiTree T)
{
	if (T)
	{
		PostOrder(T->lchild);   //遍历左子树  
		PostOrder(T->rchild);   //遍历右子树  
		cout << T->data << " ";       //访问参数  
	}
}

//6.先序遍历二叉树---非递归  
void PreOrder1(BiTree T)
{
	stack<BiTree> s;
	BiTree p = T;
	while (p || !s.empty())     //结点p非空，或栈非空  
	{
		if (p)
		{
			cout << p->data << " ";
			s.push(p);            //根指针进栈 
			p = p->lchild;        //遍历左子树   
		}
		else
		{
			p = s.top();          //访问根结点
			s.pop();              //根指针退栈
			p = p->rchild;        //遍历右子树
		}
	}
}

//先序遍历二叉树---非递归  
void PreOrder2(BiTree T)
{
	stack<BiTree> s;
	BiTree p;
	if (T)
		s.push(T);                //根指针进栈
	while (!s.empty())
	{
		p = s.top();              //访问根结点
		cout << p->data << " ";
		s.pop();                  //根指针退栈
		if (p->rchild)
			s.push(p->rchild);    //遍历右子树
		if (p->lchild)
			s.push(p->lchild);    //遍历左子树 
	}
}
//中序遍历二叉树---非递归  
void InOrderUnrec1(BiTNode* &T)
{
	stack<BiTNode*> s;
	BiTNode* p = T;
	while (p || !s.empty())     //p非空，或栈非空  
	{
		if (p)
		{
			s.push(p);          //根指针进栈 
			p = p->lchild;        //遍历左子树   
		}
		else
		{
			p = s.top();          //访问根结点
			cout << p->data << " ";
			s.pop();              //根指针退栈
			p = p->rchild;        //遍历右子树
		}
	}
}

//中序遍历二叉树---非递归  
void InOrder2(BiTree T)
{
	stack<BiTree> s;
	BiTree p = T;
	while (p || !s.empty())     //p非空，或栈非空  
	{
		while (p)
		{
			s.push(p);          //根指针进栈 
			p = p->lchild;        //遍历左子树   
		}
		if (!s.empty())		//栈非空
		{
			p = s.top();          //访问根结点
			cout << p->data << " ";
			s.pop();              //根指针退栈
			p = p->rchild;        //遍历右子树
		}
	}
}
//后序遍历二叉树---非递归  
void PostOrderUnrec1(BiTree T)
{
	stack<pair<BiTree, bool>> s;
	BiTree p = T;
	while (p || !s.empty())
	{
		if (p)
		{
			s.push(make_pair(p, false));		//false表示根结点p的右子树未访问   
			p = p->lchild;
		}
		else
		{
			if (s.top().second == false)		//根结点的右子树未访问   
			{
				s.top().second = true;			//标志右子树为已访问   
				p = s.top().first->rchild;		//遍历右子树   
			}
			else								//右子树已访问   
			{
				cout << s.top().first->data << " ";	//输出根结点值   
				s.pop();						//根结点出栈   
			}
		}
	}
}

//后序遍历二叉树---非递归
void PostOrderUnrec2(BiTree T)
{
	stack<BiTree> s1, s2;         //双栈法
	BiTNode* p;
	if (T)
		s1.push(T);                //根指针进栈
	while (!s1.empty())            //栈空时结束      
	{
		p = s1.top();                //访问根结点
		s1.pop();                    //根指针退栈
		s2.push(p);                //根指针进2栈
		if (p->lchild)
			s1.push(p->lchild);    //遍历左子树
		if (p->rchild)
			s1.push(p->rchild);    //遍历右子树
	}
	while (!s2.empty())            //输出栈2
	{
		cout << s2.top()->data << " ";
		s2.pop();
	}
}

//后序遍历二叉树---非递归
void PostOrderUnrec3(BiTNode* &T)
{
	stack<BiTNode*> s;
	BiTNode *p = T, *pre = NULL;         //pre是指向前一个出栈结点
	while (p || !s.empty())
	{
		if (p)
		{
			s.push(p);
			p = p->lchild;               //遍历左子树
		}
		else
		{
			if (s.top()->rchild && pre != s.top()->rchild)  //栈顶结点的右子树非空或者未出栈
			{
				p = s.top()->rchild;     //遍历右子树
			}
			else
			{
				pre = s.top();
				cout << pre->data << " ";
				s.pop();
			}
		}
	}
}
//层次遍历二叉树
void LevelOrder(BiTNode* &T)
{
	queue< BiTNode*> q;
	BiTNode* p = T;
	if (p)
		q.push(p);
	while (!q.empty())            //队列非空   
	{
		p = q.front();
		cout << p->data << " ";
		q.pop();
		if (p->lchild)            //左孩子不空，入队列    
			q.push(p->lchild);
		if (p->rchild)            //右孩子不空，入队列   
			q.push(p->rchild);
	}
}

//求树的深度
int Depth(BiTNode* &T)
{
	if (!T)
		return 0;
	int d1, d2;
	d1 = Depth(T->lchild);
	d2 = Depth(T->rchild);
	return (d1 > d2 ? d1 : d2) + 1;
}

//求二叉树的结点的个数
int CountNode(BiTNode* &T)
{
	if (T == NULL)
		return 0;
	return 1 + CountNode(T->lchild) + CountNode(T->rchild);
}

//求二叉树的叶子结点的个数
int CountLeaf(BiTNode* &T)
{
	if (!T)
		return 0;
	else if (!T->lchild && !T->rchild)
		return 1;
	else
		return CountLeaf(T->lchild) + CountLeaf(T->rchild);
}

//求二叉树的度为1的结点的个数
int CountOne(BiTNode* &T)
{
	if (!T)
		return 0;
	else if ((T->lchild && !T->rchild) || (!T->lchild && T->rchild))
		return 1 + CountOne(T->lchild) + CountOne(T->rchild);
	else
		return CountOne(T->lchild) + CountOne(T->rchild);
}

//求二叉树的度为2的结点的个数
int CountTwo(BiTNode* &T)
{
	if (!T)
		return 0;
	else if ((T->lchild && T->rchild))
		return 1 + CountTwo(T->lchild) + CountTwo(T->rchild);
	else
		return CountTwo(T->lchild) + CountTwo(T->rchild);
}

int main()
{
	//创建二叉树
	BiTree tree;
	CreateBiTree(tree); //如输入：E A # C B # # D # # G F # # #
	//三种前序遍历二叉树
	PreOrder(tree);
	PreOrder1(tree);
	PreOrder2(tree);
	//中序遍历二叉树
	InOrder(tree);
	//销毁二叉树

	return 0;
}