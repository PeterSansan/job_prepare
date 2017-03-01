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
typedef int SElemType;

#define MAXSIZE 100 //栈的大小
//0.链栈的存储结构
typedef struct StackNode
{
	SElemType data;
	StackNode * next;
}StackNode, *LinkStackPtr;

typedef struct LinkStack
{
	LinkStackPtr top;
	int count;
	LinkStack(int n)	//类似于类中的构造函数
	{
		count = n;
	}
}LinkStack;
//链栈的操作绝大部分都和单链表类似，只是在插入和删除上，特殊一些。
//1.插入元素e为新的栈顶元素
Status Push(LinkStack *S, SElemType e)
{
	LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));//新建立一个结点
	s->data = e;
	s->next = S->top;//把当前的栈顶元素赋值给新结点的直接后继
	S->top = s;	//将新的结点s赋值给栈顶指针
	S->count++;
	return OK;
}
//2.链栈的出栈操作
Status Pop(LinkStack *S, SElemType *e)
{
	LinkStackPtr p;
	if (S->count == 0)
		return ERROR;//空栈
	*e = S->top->data;
	p = S->top;		//将栈顶结点赋值给p
	S->top = S->top->next; //使得栈顶指针下移一位，指向后一结点
	S->count--;		//释放结点p
	free(p);
	return OK;
}
//3.打印链栈的数据
void PrintLinkStack(LinkStack ls)
{
	LinkStackPtr lp;
	lp = ls.top;
	for (int i = 0; i < ls.count; i++)
	{
		cout << lp->data<<" ";
		lp = lp->next;
	}
	cout << endl;
}
// 主函数
int main()
{
	//顺序存储结构 
	LinkStack linkStack(0);
	//插入两个新的元素
	Push(&linkStack, 1);
	Push(&linkStack, 2);
	cout << linkStack.count << endl;
	//打印链栈的数据
	PrintLinkStack(linkStack);

	return 0;
}