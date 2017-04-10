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
typedef struct
{
	QElemType data[MAXSIZE];
	int front;	//头指针
	int rear;	//尾指针，若队列不空，指向队列尾
}SqQueue;
//1.循环队列的初始化代码
Status InitQueus(SqQueue *Q)
{
	Q->front = 0;
	Q->rear = 0;
	return OK;
}
//2.循环队列求长度代码
int QueueLength(SqQueue Q)
{
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}
//3.循环队列入队操作
Status EnQueue(SqQueue *Q, QElemType e)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front)	//队列满的判断
		return ERROR;
	Q->data[Q->rear] = e;	//将元素e赋值给队尾
	Q->rear = (Q->rear + 1) % MAXSIZE;//rear指针向后移一位置，或到最后则转到数组头部
	return OK;
}
//4.循环队列出队操作
Status DeQueue(SqQueue *Q, QElemType *e)
{
	if (Q->front == Q->rear)	//队列空的判断
		return ERROR;
	*e = Q->data(Q->front);	//将队头元素赋值给e
	Q->front = (Q->front + 1) % MAXSIZE;	//front指针向后移一位置，若到最后则转到数组头部
	return OK;
}
// 主函数
int main()
{
	return 0;
}