### 1.顺序容器输出
```
void print(vector<int> v)
{
	//	for ( auto beg = v.begin(), end = v.end(); beg != end; ++beg )
	//		cout<<*beg<<' ';
	for (auto &r : v)
		cout << r << ' ';
	cout << endl;
}
```
### 2.查找字符中的子串的个数

```
void str_()
{
	string str("babccbabcaabcccbabccabcabcabbabcc");
	int num = 0;
	string::size_type fi = str.find("abc", 0);
	while (fi != str.npos)
	{
		cout << fi << "   ";
		num++;
		fi = str.find("abc", fi + 1);
	}
	if (0 == num)
		cout << "not find!";
	cout << endl;
}
```
### 3.C++二维矩阵的定义

- 法1，vector

```
vector<vector<int> > v(n, vector<int>(m));
/*定义了一个vector容器，元素类型为vector<int>，初始化为包含m个vector<int>对象，
每个对象都是一个新创立的vector<int>对象的拷贝，而这个新创立的vector<int>对象被初始化为包含n个0。*/
```
- 法2,c++

```
int n=10,m=2;     //  
int **swp;      //动态申请二维数组 n行 m列  
swp=new int*[n];  
for(int i=0;i<n;i++)  
	swp[i]=new int[m];  
```
- 法3.c

```
int a,b;
cin>>a>>b;
int **ch = (int**) malloc(sizeof(int*)*a);
for(int i=0;i<a;i++)
{
	ch[i] = (int *) malloc(sizeof(int)*b);
```
- 法4；

```
	scanf("%d %d",&n,&m);//	注意用全局变量
	for(i=0;i<n;i++)
		for(j=0;i<m;j++)
			scanf("%d",&a[i][j]);
```
### 4.矩阵方向操作

```
int next[4][2]={{0,1},//向右走
			{1,0},		//向下走
			{0,-1},		//向左走
			{-1,0}};	//向上走
```
### 5.十进制转二进制

```
string ss(int &numd)
{
	string a;
	for (int i = 0; numd != 0; i++)
	{
		a = a + (numd % 2 ? '1' : '0');
		numd /= 2;
	}
	reverse(a.begin(), a.end());
	return a;
}
```
### 6.C++中多维数组的理解

```
int ia[3][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };
cout << **begin(ia) << endl;		//输出1
cout << *(*(end(ia)-1)+1) << endl;  //输出的是10，注意end是指到末地址的下一位
	cout << *(*(ia+2)+1) << endl; 	//输出为10
for (auto &a : ia)	//要使用范围for语句处理多维数组，除了最内层的循环外，其他所有循环的控制变量都应该是引用类型
	for (auto b : a)
		cout << b << endl;
	
for (auto p = begin(ia); p != end(ia); ++p)
{
	//q指向内层数组的首元素
	for (auto q = begin(*p); q != end(*p); ++q)
		cout << *q << ' ';	//输出q所指的整数值
	cout << endl;
}
```	
### ７.排序去除重复的单词

```
void movesame(vector<string> &s)
{
	//按字典序排序words,以便查找重复单词
	sort(s.begin(), s.end());
	auto end_unique = unique(s.begin(), s.end());
	s.erase(end_unique, s.end());
}
```
### 8.删除指定字符串

```
int main()
{
	string str,str1;
	cin >> str;
	cin >> str1;
	auto po = str.find(str1,0);
	while (po != str.npos)
	{
		str.erase(po, str1.size());
		po = str.find(str1,po+1);
	}
	cout << str;
	return 0;
}
```