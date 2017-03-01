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
//0.栈的顺序存储结构
typedef struct
{
	SElemType data[MAXSIZE];
	int top;	//用于栈顶指针
}SqStack;
//1.插入元素e为新的栈顶元素
Status Push(SqStack *S, SElemType e)
{
	if (S->top == MAXSIZE - 1) //栈满
	{
		return ERROR;
	}
	S->top++;
	S->data[S->top] = e;	//将新插入元素赋值给栈顶空间
	return OK;
}
//2.栈的顺序存储结构——出栈操作
Status Pop(SqStack *S, SElemType *e)
{
	if (S->top == -1)
		return ERROR;
	*e = S->data[S->top];	//将要删除的栈顶元素赋值给e
	S->top--;	//栈项指针减一
	return OK;
}
//3.打印栈的元素,从栈顶到栈底
void PrintSqStack(SqStack S)
{
	for (int i = S.top; i >= 0; i--)
		cout << S.data[i] << " ";
	cout << endl;
}

//共享空间
//4.定义共享空间栈的数据结构 
typedef struct
{
	SElemType data[MAXSIZE];
	int top1;	//栈1栈顶指针
	int top2;	//栈2栈顶指针
}SqDoubleStack;
//5.插入元素e为新的栈顶元素
Status DouPush(SqDoubleStack *S, SElemType e, int stackNumber)
{
	if (S->top1 + 1 == S->top2)	//栈已满，不能再push新元素了
		return ERROR;
	if (stackNumber == 1)//栈1有元素进栈
		S->data[++S->top1] = e;//若栈1则先top+1后给数给元素赋值
	else if (stackNumber == 2)//栈2有元素进栈
		S->data[--S->top2] = e;//若栈2则先top2-1后给数线元素赋值
	return OK;
}
//6.共享空间栈出栈操作
Status DouPop(SqDoubleStack *S, SElemType *e, int stackNumber)
{
	if (stackNumber == 1)
	{
		if (S->top1 == -1)
			return ERROR;
		*e = S->data[S->top1--];	//将栈1的栈顶元素出栈
	}
	else if (stackNumber == 2)
	{
		if (S->top2 == MAXSIZE)
			return ERROR;
		*e = S->data[S->top2++];
	}
	return OK;
}
//7.打印共享空间中双栈的数据
void PrintDoubleStack(SqDoubleStack doubleStack)
{
	for (int i = doubleStack.top1; i >= 0; i--)
		cout << doubleStack.data[i] << " ";
	cout << endl;
	for (int i = doubleStack.top2; i < MAXSIZE; i++)
		cout << doubleStack.data[i] << " ";
	cout << endl;
}
// 主函数
int main()
{
	//顺序存储结构 
	//定义一个空栈
	SqStack stack;
	stack.top = -1;

	//插入一个元素
	Push(&stack, 1);
	Push(&stack, 2);
	//过印栈的元素
	PrintSqStack(stack);
	//删除栈顶元素
	int e=0;
	Pop(&stack, &e);
	cout << "删除的栈顶元素是：" << e << endl;
	PrintSqStack(stack);

	//初始化共享空间的栈结构
	SqDoubleStack doubleStack;
	doubleStack.top1 = -1;	
	doubleStack.top2 = MAXSIZE;
	//两栈各插入两个数据
	DouPush(&doubleStack, 1, 1);
	DouPush(&doubleStack, 2, 1);
	DouPush(&doubleStack, 1, 2);
	DouPush(&doubleStack, 2, 2);
	//打印两栈的数据
	PrintDoubleStack(doubleStack);

	return 0;
}