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

//0.二叉树排树结点结构定义
typedef struct BiTNode
{
	int data;//	结点结构
	BiTNode *lchild, *rchild;
}BSTNode, *BiTree;

//1.二叉排序树中序遍历
void inOrder(BiTree T)
{
	if (T)
	{
		inOrder(T->lchild);
		cout << T->data << " ";
		inOrder(T->rchild);
	}
}
//2.二叉排序树的插入,递归算法
Status BSTInsert(BiTree &T, int key)
{
	if (!T)
	{
		T = new BSTNode;
		T->data = key;
		T->lchild = T->rchild = NULL;
		return TRUE;
	}
	else if (key < T->data)
		return BSTInsert(T->lchild, key);
	else if (key > T->data)
		return BSTInsert(T->rchild, key);
	else if (key == T->data)
		return FALSE;
	return FALSE;
}
//3.二叉排序树的查找——非递归
BiTree BSTSearch(BiTree T, int key, BiTree &parent)
{
	parent = NULL;		//parent指向被查找结点的双亲，用于插入和删除操作
	while (T && T->data != key)		//T为NULL，相当于没找到，没找到之前是不会出现NULL情况
	{
		parent = T;
		if (key < T->data)  
			T = T->lchild;
		else  
			T = T->rchild;
	}
	return T;
}
//4.二叉排序树的插入——非递归
Status BSTInsert1(BiTree &T, int key)
{
	BiTree p, s;
	if (!BSTSearch(T, key, p))
	{
		s = new BiTNode;
		s->data = key;
		s->lchild = s->rchild = NULL;
		if (!p)				//这种情况为创建根结点
			T = s;	//插入s为新的要结点
		else if (key < p->data)
			p->lchild = s;	//插入s为左孩子
		else
			p->rchild = s;//插入s为右孩子
		return TRUE;
	}
	else
		return FALSE;		//树中已有关键字相同的结点，不再插入
}
//5.二叉排序树的查找——递归 ,查到的话返回结点的地址，查不到返回NULL
BiTree BSTSearch2(BiTree T, int key, BiTree &parent)
{
	if (T && T->data != key)
	{
		parent = T;
		if (key < T->data)
			return BSTSearch2(T->lchild, key, parent);
		else
		{
			return BSTSearch2(T->rchild, key, parent);
		}
	}
	else
		return T;
}
//6.查找最小关键字,空树时返回NULL
BiTree searchMin(BSTNode *T)
{
	if (!T)
		return NULL;
	if (!T->lchild)		//直到找到左子树为空为止
		return T;
	else
		return searchMin(T->lchild);  //一直往左孩子找
}
//7.查找最大关键字，空树时返回NULL 
BiTree searchMax(BiTree T)
{
	if (!T)
		return NULL;
	if (!T->rchild)
		return T;
	else
		return searchMax(T->rchild);  //一直往右孩子找
}
//8.删除二叉排序树元素
Status Delete(BiTree &p)
{
	BiTree q, s;
	if (p->rchild == NULL)	//删除结点只有左子树的情况，删除后，则只需重接它的左子树
	{						//没两种情况包含了叶子结点的情况
		q = p;
		p = p->lchild;
		delete q;
		q = NULL;
	}
	else if (p->lchild == NULL) //删除结点只有右子树的情况，删除后，则只需重接它的右子树
	{
		q = p;
		p = p->rchild;//删除的结点指向下一个结点
		delete q;
		q = NULL;
	}
	else	//左右子树不空
	{
		q = p;
		s = p->lchild;
		while (s->rchild)	//转左，然后向右到尽头（找待测结点的前驱)
		{
			q = s;			//q是选出来的前驱的父母结点，前驱被删后，它的左孩子接到这里
			s = s->rchild;	
		}
		p->data = s->data;   //s指向被删结点的直接前驱
		if (q != p)
			q->rchild = s->lchild;//重接q的右子树
		else
			q->lchild = s->lchild;//重接q的左子树；
		delete s;
		s = NULL;
	}
	return TRUE;
}

//9.删除二叉排序树元素
Status DeleteBST(BiTree &T, int key)
{
	if (!T)
		return FALSE;	//不存在关键字等于 key的数据元素
	else
	{
		if (key == T->data)	//找到关键字等于key的数据元素
			return Delete(T);
		else if (key < T->data)
			return DeleteBST(T->lchild, key);
		else
			return DeleteBST(T->rchild, key);
	}
}
int main()
{
	BiTree tree = NULL, parent = NULL;
	int n[10] = { 4, 2, 1, 0, 3, 5, 9, 7, 6, 8 };
	for (int i = 0; i < 10; i++)
	{
		BSTInsert1(tree, n[i]);
	}
	//中序查看
	inOrder(tree);  
	cout << endl;
	//删除二叉树
	DeleteBST(tree, 1);
	inOrder(tree);
	return 0;
}


