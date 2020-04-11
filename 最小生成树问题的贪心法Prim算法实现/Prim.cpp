#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n; //n:顶点个数
vector<vector<int>> g;//g:用邻接矩阵表示图g
vector<bool> known; //known:各点是否已经选取
vector<int> dist; //dist:已选取点集到未选取点集的边长
vector<int> _prev; // 最小生成树中各点的前一顶点
int s; //s:起点(start)
int sum; //sum:最小生成树长 
bool Prim() //贪心算法
{
	//初始化konwn、dist、_prev
	known.assign(n, false);
	dist.assign(n, INT_MAX);
	_prev.resize(n);
	dist[s] = 0; //起点到自身的距离是0
	int i;
	for (i = 0; i < n; ++i)
	{
		int min = INT_MAX, v;
		for (int i = 0; i < n; ++i)
		{
			if (!known[i] && min>dist[i])//寻找未知的最短路径长的顶点
				min = dist[i], v = i;
		}
		if (min = INT_MAX) break;//找不到，跳出
		known[v] = true;//找到将顶点v设置成已知
		sum += dist[v];

		for (int w = 0; w < n; ++w)
		{
			if (known[w] && g[v][w]<INT_MAX && dist[w]>g[v][w])//调整顶点w的最短路径长dist和最短路径的前一顶点_prev
				dist[w] = g[v][w], _prev[w] = v;
		}
	}
	return i == n; //如果选取的顶点个数为n ，成功
}
int main()
{
	n = 6;//6个顶点
	g.assign(n, vector<int>(n, INT_MAX));
	g[0][1] = g[1][0] = 6; g[0][2] = g[2][0] = 15; g[0][3] = g[3][0] = 10;
	g[1][3] = g[3][1] = 11; g[1][4] = g[4][1] = 8;
	g[2][3] = g[3][2] = 5; g[2][5] = g[5][2] = 9;
	g[3][4] = g[4][3] = 4; g[3][5] = g[5][3] = 8;
	g[4][5] = g[5][4] = 12;
	s = 0;//起点任意选
	sum = 0;
	if (Prim())
	{
		cout << sum << endl;
		for (int i = 1; i < n; ++i)
			if (i != s) cout << _prev[i] << "->" << i << endl;
	}
	else
	{
		cout << "有顶点不能到达!"<<endl;
	}
	return 0;
}