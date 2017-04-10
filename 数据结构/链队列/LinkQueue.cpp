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
typedef int QElemType;	
#define MAXSIZE 100


//循环队列的顺序存储结构
typedef struct	//结点结构
{
	QElemType data;
	QNode *next;
}QNode, *QueuePtr;

typedef struct	//队列的链表结构
{
	QueuePtr front, rear;	//队头，队尾指针
}LinkQueue;

//1.入队操作：就是在链表尾部插入结点
Status EnQueue(LinkQueue *Q, QElemType e)
{
	QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
	if (!s)
		exit(1);
	s->data = e;
	s->next = NULL;
	Q->rear->next = s;	//把拥有元素e新结点s赋值给原队尾结点的后继
	Q->rear = s;	//把当前的s设置为队尾结点，rear指向s
	return OK;
}
//3.出队操作：就是头结点的后继结点出队，将头结点的后继改为它后面的结点，若链表除头结点外只剩一个元素时，则需将rear指向头结点
//链队列是有头节点的，但栈队列没有
Status DeQueue(LinkQueue *Q, QElemType *e)
{
	QueuePtr p;
	if (Q->front = Q->rear)
		return ERROR;
	p = Q->front->next;	//将欲删除的队头结点暂存给p,见上图中
	*e = p->data;	//将欲删除的队头结点的值赋值给e
	Q->front->next = p->next;	//将原队头结点后继p->next赋值给头结点后继
	if (Q->rear == p)
		Q->rear = Q->front;
	free(p);
	return OK;
}
// 主函数
int main()
{
	return 0;
}