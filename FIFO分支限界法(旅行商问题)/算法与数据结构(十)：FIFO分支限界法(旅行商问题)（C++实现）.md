# 算法与数据结构(十)：FIFO分支限界法(旅行商问题)（C++实现）

#### 分支限界法基本思想

分支限界法常以广度优先或者最小耗费（最大效益）优先的方式搜索问题的解空间树。问题的解空间树是表示问题解空间的一颗有序树，常见的有子集树和排列树。在搜索问题的解空间树时，分支限界法和回溯法对当前扩展节点所使用的扩展方式不同。在分支限界法中，每一个活节点只有一次机会成为扩展节点。活节点一旦成为扩展节点，就一次性产生其所有儿子节点。在这些儿子节点中，那些导致不可行解或者非最优解的儿子节点被舍弃，其余儿子节点被加入活节点表中。此后，从活结点表中选取下一节点成为当前扩展节点，并重复上述节点扩展过程。这个过程一直持续到找到所求的解或活结点表为空时终止。

队列式(FIFO)分支限界法：将活节点表组织成一个队列，并按队列先进先出的原则选择下一个节点为当前扩展节点。

#### 旅行商问题(TSP)问题

某销售员要到若干个城市销售商品，已知各个城市之间的路费（或旅费）。他要选定一条从驻地出发，经过每个城市一遍最后回到驻地的路线，使总的路线（或总的旅费最少）。

#### 主函数

```c++
/*旅行商问题分支限界法求解*/
#include<iostream>
using namespace std;
const int NoEdge = -1;
const int MAX = 20;
int G[MAX][MAX];
int ans[MAX], x[MAX];
int bestc, cc;
void init(int n)
{
	int i, j, len;
	memset(G, NoEdge, sizeof(G));
	while (cin >> i >> j)
	{
		if (i == 0 && j == 0) break;
		cin >> len;
		G[i][j] = len;
		G[j][i] = len;
	}
	for (i = 1; i <= n; i++) x[i] = i;
	bestc = 0x7fffffff;// 0x7fffffff/INT_MAX:整数的最大值
	cc = 0;
}
void Swap(int &i, int &j)
{
	int temp;
	temp = i;
	i = j;
	j = temp;
}
void Traveling(int i, int n)
{
	int j;
	if (i == (n + 1))
	{
		if ((G[x[n - 1]][x[n]] != NoEdge) && ((cc + G[x[n]][1]) < bestc) && G[x[n]][1] != NoEdge)
		{
			for (j = 1; j < n; j++) ans[j] = x[j];
			bestc = cc + G[x[n]][1];
		}
	}
	else
	{
		for (j = i; j <= n; j++)
		{
			if ((G[x[i - 1]][x[j]] != NoEdge) && ((cc + G[x[i - 1]][x[j]]) < bestc))
			{
				Swap(x[i], x[j]);
				cc += G[x[i - 1]][x[i]];
				Traveling(i + 1, n);
				cc -= G[x[i - 1]][x[i]];
				Swap(x[i], x[j]);
			}
		}
	}
}
void print(int n)
{
	cout << "最小旅行费用为:" << bestc << endl;
	cout << "最佳路径是：";
	for (int i = 1; i <= n; i++)
		cout << ans[i] << "->";
	cout << ans[1]<<endl;
}
int main()
{
	int n;
	cout << "请输入要旅行多少个城市:" << endl;
	while (cin >> n&&n)
	{
		cout << "输入两个城市之间的距离，例如 1 2 20，输入 0 0 结束" << endl;
		init(n);
		Traveling(2, n);
		print(n);
	}
	return 1;
}
```

n表示总共有多少个城市，bestc存储最小的旅行费用，ans[i]存储一个最佳旅行路线。程序运行结果如下图所示：

![二叉树](C:\Users\Administrator\Documents\Visual Studio 2013\Projects\FIFO分支限界法(旅行商问题)\FIFO分支限界法(旅行商问题).JPG)

#### 参考：算法分析与设计(C++描述) 石志国、刘冀伟、姚亦飞编著