# 算法与数据结构(八)：回溯算法（子集合问题）（C++实现）

#### 回溯算法基本思想

在实际运用中，回溯算法的基本思想是：首先为问题定义一个解空间，这个空间至少包含问题的一个解（可能就是最优的）。然后，先选择某一种可能的情况向前探索，在搜索的过程中，一旦发现原来的选择不优或者不能达到目标，就退回上一步重新选择，并继续向前搜索。如此反复进行，直至得到解或者证明无解存在。

#### 子集合问题

求数组集合的所有子集（不包含空集）

#### 主函数

```c++
/*子集合问题*/
#include<iostream>
using namespace std;
const int N = 4;
int s[N] = {3,5,7,9};
int x[N];
void print()
{
	for (int i = 0; i < N; i++)
	{
		if (x[i] == 1) cout << s[i]<<" ";
	}
	cout << endl;
	//return;
}
void Subset(int i)
{
	if (i >= N)
	{
		print();
		//return;
	}
	else
	{
		x[i] = 1;//搜索右子树
		Subset(i + 1);

		x[i] = 0;//搜索左子树
		Subset(i + 1);
	}
}
int main()
{
	cout << "数组的子集合为:" << endl;
	Subset(0);
	return 0;
}
```

程序运行结果如下图所示：

![二叉树](C:\Users\Administrator\Documents\Visual Studio 2013\Projects\回溯算法（子集合问题）\回溯算法（子集合问题）.JPG)

#### 参考：算法分析与设计(C++描述) 石志国、刘冀伟、姚亦飞编著