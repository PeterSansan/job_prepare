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

/*malloc / free是C / C++语言的标准库函数，new / delete是C++的运算符。
对于用户自定义的对象而言，用maloc / free无法满足动态管理对象的要求。
对象在创建的同时要自动执行构造函数，对象在消亡之前要自动执行析构函数。
由于malloc / free是库函数而不是运算符，不在编译器控制权限之内，
不能够把执行构造函数和析构函数的任务强加于malloc / free。
因此C++需要一个能完成动态内存分配和初始化工作的运算符new，
以及一个能完成清理与释放内存工作的运算符delete。*/

/*1、new自动计算需要分配的空间，而malloc需要手工计算字节数
2、new是类型安全的，而malloc不是，比如：
int* p = new float[2]; // 编译时指出错误
int* p = malloc(2 * sizeof(float)); // 编译时无法指出错误 */
class Obj
{
public:
	Obj()
	{
		cout << "Initialization" << endl;
	}
	~Obj()
	{
		cout << "Destroy" << endl;
	}
	void Initialize()	//模拟构造函数
	{
		cout << "Initialization" << endl;
	}
	void  Destroy()		//模拟析构函数
	{
		cout << "Destroy" << endl;
	}
}obj;

void  UseMallocFree()
{
	Obj   * a = (Obj  *)malloc(sizeof(obj));      //  allocate memory   
	a->Initialize();                                    //  initialization  
	// …   
	a->Destroy();                                        // deconstruction   
	free(a);                                               // release memory  
}

void  UseNewDelete(void)
{
	Obj   * a = new  Obj;
	// …   
	delete a;
	a = NULL;
}

int main()
{
	UseMallocFree();
	UseNewDelete();
	return 0;
}