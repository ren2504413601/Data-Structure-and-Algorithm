/*旅行商问题分支限界法求解*/
#include<iostream>
#include<cstring> //'memset' is defined in header <cstring>
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