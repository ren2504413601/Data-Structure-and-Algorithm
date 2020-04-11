# 算法与数据结构(十二)：回溯算法（八皇后问题）（C++实现）

#### 回溯算法基本思想

在实际运用中，回溯算法的基本思想是：首先为问题定义一个解空间，这个空间至少包含问题的一个解（可能就是最优的）。然后，先选择某一种可能的情况向前探索，在搜索的过程中，一旦发现原来的选择不优或者不能达到目标，就退回上一步重新选择，并继续向前搜索。如此反复进行，直至得到解或者证明无解存在。

#### 八皇后问题

在8x8格的国际象棋上摆放八个皇后，使其不能相互攻击，即任意两个皇后都不能处在同一行、同一列或者同一斜线上。以深度优先的方式搜索解空间，并且在搜索的过程中使用剪枝函数来剪枝。根据条件x[i]==x[j]判断处于同一行，abs(k-i)==abs(k-i)判断是否处于同一斜线。

#### 主函数

```c++
/*八皇后问题*/
#include<iostream>
using namespace std;
const int N = 8;
int x[N + 1];
int Count = 1;
bool canPlace(int i)
{
	for (int k = 1; k <i; k++)
	{
		if (x[k] == x[i] || abs(x[k] - x[i]) == abs(k - i))
			return false;
	}
	return true;
}

void print()
{
	cout << Count << ":";
	for (int i = 1; i <= N; i++)
		cout << x[i] << " ";
	cout << endl;
	Count++;
}

void Queen(int i)
{
	if (i > N)
	{
		print();
		return;
	}
	else
	{
		for (int j = 1; j <= N; j++)
		{
			x[i] = j;
			if (canPlace(i)) Queen(i + 1);
		}
	}
}
int main()
{
	Queen(1);
	return 0;
}
```

利用函数"canPlace()"进行每一个皇后是否可以摆放的设定。程序运行结果如下图所示：

![二叉树](C:\Users\Administrator\Documents\Visual Studio 2013\Projects\回溯算法（八皇后问题）\回溯算法（八皇后问题）.JPG)

#### 参考：算法分析与设计(C++描述) 石志国、刘冀伟、姚亦飞编著