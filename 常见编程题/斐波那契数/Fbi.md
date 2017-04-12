# 斐波那契系列问题的递归和动态规则



## 1. 基本斐波那契数问题

### 基本问题：

给定整数N，返回斐波那契数列的第N项，实现时间复杂度O(logN)的解法。

### 解法：

法一：暴力递归O(2^N)

```
//1.递归法
int Fbi(int n)
{
	if (n < 2)
		return n == 0 ? 0 : 1;
	return Fbi(n-1)+Fbi(n-2);
}
```

法二：从左到右迭代法，O(N)

```
int Fbi_b(int n)
{
	if (n < 1)
		return 0;
	if (n == 1 || n == 2)
		return 1;

	int res = 1;
	int pre = 1;
	int tmp = 0;
	for (int i = 3; i <= n; i++)
	{
		tmp = res;
		res = res + pre;
		pre = tmp;
	}
	return res;
}
```

法三：矩阵算法优化递推。O(logN)，递推公式F(N)=F(N-1)+F(N-2)，可以转换成如下公式：
$$
(F(n),F(n-1)) = (F(n-1),F(n-2)) \times
\left[
 \begin{matrix}
   1 & 1\\
   1 & 0 
  \end{matrix}
  \right]=(1,1)\times
  \left[
  \begin{matrix}
  1 & 1\\
  1 & 1
  \end{matrix}
  \right]^{n-2}
  \tag{1}
$$
那么这样问题就变成了如何用最愉的方法求一个矩阵的N次方的问题，而求矩阵的N次方的问题明显是一个能够在O(logN)时间内解决的问题。

假设一个整数是10，如何最快地求解10的75次方。

- 75的二进制形式是1001011

- 10的75次方 $ =10^{64}\times10^8\times10^2\times10^1$

因此算法描述如下：

```c++
初始化tmp;
for(p不等于0;p右移1位)
  	if(p与1相与不等于0)
    	res等于res与tmp相乘;
  	else 
    	res等于res与res相乘; 
返回res; 
```

因此最后的斐波那契数列第N项的全部代码如下：

```c++
int Fbi_c(int n)
{
	if(n<1)
    	return 0;
    if(n==1||n==2)
    	return 1;
    int base[2][2] = {{1,1},{1,0}};
    int res[2][2] = matrixPower(base,n-2);	//矩阵的次方运算
    return res[0][0]+res[1][0]; 	
}

```





