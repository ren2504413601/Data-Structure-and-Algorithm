/*
*单源最短路径问题的贪心算法
*/
#include<iostream>
#include<vector>
#include<iterator>
using namespace std;
const int n=5;// n:定点个数
// g: 图(graph) 用邻接矩阵(adjacent matrix)表示
vector <vector<int> > g;
int s=0;// s:源点(source)
vector <bool> know; //know:各点是否已知最短路径
vector <int> dist; //dist:源点s到各点的最短路径长
vector <int> _prev; //_prev :各点到最短路径的前一顶点
void Dijkstra() //贪心算法实现
{
	//初始化know、dist、_prev
	know.assign(n, false);
	dist.assign(n, INT_MAX);
	_prev.resize(n);
	dist[s] = 0;//初始化源点到自身的路径长为0
	for (;;)
	{
		int min = INT_MAX, v = s;
		for (int i = 0; i < n; ++i)
			if (!know[i] && min>dist[i])
				min = dist[i], v = i;//寻找未知的最短路径长的顶点v
		if (min == INT_MAX) break; //如果找不到，退出
		know[v] = true; //找到将顶点v设置为已知
		for (int w=0; w < n; ++w)// 遍历所有指向v的顶点w
			if (!know[w] && g[v][w] < INT_MAX&&dist[w] < (dist[v] + g[v][w]))
				//调整w的最短路径长dist 和最短路径的前一顶点 _prev
				dist[w] = dist[v] + g[v][w], _prev[w] = v;
	}
}

void Print_SP(int v)
{
	if (v != s)
		Print_SP(_prev[v]);
	cout << v << " ";
}

int main()
{
	g.assign(n, vector<int>(n, INT_MAX));
	//构建图
	g[0][1] = 10; g[0][3] = 30; g[0][4] = 100;
	g[1][2] = 50;
	g[2][4] = 10;
	g[3][2] = 20; g[3][4] = 60;
	Dijkstra();
	copy(dist.begin(), dist.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		if (dist[i] != INT_MAX)
		{
			cout << s << "->" <<i<< ":";
			Print_SP(i);
			cout << endl;
		}
	}
	return 0;
}
