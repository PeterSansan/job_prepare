/*顺序表示例代码*/
#include<iostream>
#include <fstream>
using namespace std;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;//函数结果状态代码，如OK等

//0.线性表list的顺序存储结构
#define MAXSIZE 20 //存储空间初始化分配量

typedef int ElemType;	//ElemType类型根据实际情况而定，这里假设为int*
typedef struct
{
	ElemType data[MAXSIZE];//数组存储数据元素，最大值为MAXSIZE
	int length;//线性表当前长度
}SqList;

//1.打印链接
void PrintList(SqList L)
{
	for (int j = 0; j < L.length; j++)
		cout << L.data[j]<<' ';
	cout << endl;
}
//2.获取list中某一元素的值，
Status GetElem(SqList L, int i, ElemType *e)
{
	if (L.length == 0 || i < 1 || i>L.length)
		return ERROR;
	*e = L.data[i - 1];
	return OK;
}

//3.插入操作
//*操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1*/
Status ListInsert(SqList *L, int i, ElemType e)
{
	int k;
	if (L->length == MAXSIZE)	//顺序线性表已经满
		return ERROR;
	if (i<1 || i>L->length + 1)//当i不在范围内时
		return ERROR;

	if (i <= L->length)	//若插入数据位置不在表尾
	{
		for (k = L->length - 1; k >= i - 1; k--)
			L->data[k + 1] = L->data[k];
	}
	L->data[i - 1] = e;//将新元素输入
	L->length++;
	return OK;
}

//4.删除操作
Status ListDelete(SqList *L, int i, ElemType *e)
{
	int k;
	if (L->length == 0)	//顺序表为空
		return ERROR;
	if (i<1 || i>L->length)
		return ERROR;

	*e = L->data[i - 1];//存储删除的元素
	if (i <L->length)
	{
		for (k = i; k < L->length; k++)	//将删除位置后继无素前移
			L->data[k - 1] = L->data[k];
	}
	L->length--;
	return OK;
}
// 主函数
int main()
{
	//system("pause");
	//初始化list
	SqList li = { {1,2,3,4,5}, 5 };
	//打印顺序表数据
	cout << "原顺序表" << endl;
	PrintList(li);
	//获取一个元素数据
	ElemType gete = 0;
	if (GetElem(li, 3, &gete))
		cout <<"获取一个元素："<<gete << endl;

	//插入一个新的元素
	if (ListInsert(&li, 2, 7))
		PrintList(li);

	//删除一个元素操作
	ElemType e = 0;
	if (ListDelete(&li, 2, &e))
		PrintList(li);
	return 0;
}