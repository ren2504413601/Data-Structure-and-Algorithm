#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n; //n:�������
vector<vector<int>> g;//g:���ڽӾ����ʾͼg
vector<bool> known; //known:�����Ƿ��Ѿ�ѡȡ
vector<int> dist; //dist:��ѡȡ�㼯��δѡȡ�㼯�ı߳�
vector<int> _prev; // ��С�������и����ǰһ����
int s; //s:���(start)
int sum; //sum:��С�������� 
bool Prim() //̰���㷨
{
	//��ʼ��konwn��dist��_prev
	known.assign(n, false);
	dist.assign(n, INT_MAX);
	_prev.resize(n);
	dist[s] = 0; //��㵽����ľ�����0
	int i;
	for (i = 0; i < n; ++i)
	{
		int min = INT_MAX, v;
		for (int i = 0; i < n; ++i)
		{
			if (!known[i] && min>dist[i])//Ѱ��δ֪�����·�����Ķ���
				min = dist[i], v = i;
		}
		if (min = INT_MAX) break;//�Ҳ���������
		known[v] = true;//�ҵ�������v���ó���֪
		sum += dist[v];

		for (int w = 0; w < n; ++w)
		{
			if (known[w] && g[v][w]<INT_MAX && dist[w]>g[v][w])//��������w�����·����dist�����·����ǰһ����_prev
				dist[w] = g[v][w], _prev[w] = v;
		}
	}
	return i == n; //���ѡȡ�Ķ������Ϊn ���ɹ�
}
int main()
{
	n = 6;//6������
	g.assign(n, vector<int>(n, INT_MAX));
	g[0][1] = g[1][0] = 6; g[0][2] = g[2][0] = 15; g[0][3] = g[3][0] = 10;
	g[1][3] = g[3][1] = 11; g[1][4] = g[4][1] = 8;
	g[2][3] = g[3][2] = 5; g[2][5] = g[5][2] = 9;
	g[3][4] = g[4][3] = 4; g[3][5] = g[5][3] = 8;
	g[4][5] = g[5][4] = 12;
	s = 0;//�������ѡ
	sum = 0;
	if (Prim())
	{
		cout << sum << endl;
		for (int i = 1; i < n; ++i)
			if (i != s) cout << _prev[i] << "->" << i << endl;
	}
	else
	{
		cout << "�ж��㲻�ܵ���!"<<endl;
	}
	return 0;
}