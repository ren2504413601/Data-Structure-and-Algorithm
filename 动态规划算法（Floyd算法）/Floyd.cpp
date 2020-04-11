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