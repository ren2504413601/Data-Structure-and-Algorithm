# 算法与数据结构(十一)：动态规划算法（Floyd算法）（C++实现）

#### 动态规划问题

动态规划法主要适用于最优化问题的求解。这类问题会有多种可能的解，每个解都有一个值，动态规划就是找出其中最优（最大或者最小）值的解。若存在若干个最优解的话，只取其中一个。

#### 多源最短路径问题

多源最短路径问题就是指对一个给定的非负有向网图，求出其中任意两个节点之间的最短路径。求解这一问题比较著名的有两种方法：其一是图中每个节点作为源点共调用n次Dijkstra算法；其二是采用Floyd算法。这两种算法的时间复杂度均为O(n3)。

#### 主函数

```c++
/*多源最短路径问题的动态规划Folyd法实现*/
#include<iostream>
using namespace std;
const int INF = 100000;
const int N = 11;
int n = 10, map[N][N], dist[N][N][N];
void init()
{
	int i, j;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			map[i][j] = (i == j) ? 0 : INF;
	map[1][2] = 2, map[1][4] = 20, map[2][5] = 1;
	map[3][1] = 3, map[4][3] = 8, map[4][6] = 6;
	map[4][7] = 4, map[5][3] = 7, map[5][8] = 3;
	map[6][3] = 1, map[7][8] = 1, map[8][6] = 2;
	map[8][2] = 2, map[9][7] = 2, map[10][9] = 1;
}
/*
*dist(k)[i][j]的含义允许中间节点的最大序号为k时从Vi到Vj的最短路径长度
*dist(n-1)[i][j]就是Vi到Vj的最短路径长度
*/
void floyd_dp()
{
	int i, j, k;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			dist[i][j][0] = map[i][j];
	for (k = 1; k <=n; k++)
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
			{
				dist[i][j][k] = dist[i][j][k - 1];
				if (dist[i][k][k - 1] + dist[k][j][k - 1] < dist[i][j][k])
					dist[i][j][k] = dist[i][k][k - 1] + dist[k][j][k - 1];
			}
}
int main()
{
	int k, u, v;
	init();
	floyd_dp();
	cout << "请输入任意节点的名称，比如:1 3" << endl;
	while (cin >> u >> v, u || v)
	{
		for (k = 0; k <= n; k++)
		{
			if (dist[u][v][k] == INF) cout << "+oo" << endl;
			else cout << dist[u][v][k] << endl;
		}
	}
	return 0;
}
```

dist(k)[i][j]的含义允许中间节点的最大序号为k时从Vi到Vj的最短路径长度,dist(n-1)[i][j]就是Vi到Vj的最短路径长度。程序运行结果如下图所示：

![二叉树](C:\Users\Administrator\Documents\Visual Studio 2013\Projects\动态规划算法（Floyd算法）\动态规划算法（Floyd算法）.JPG)

#### 参考：算法分析与设计(C++描述) 石志国、刘冀伟、姚亦飞编著