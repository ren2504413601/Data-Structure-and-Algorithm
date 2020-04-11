/*
*��Դ���·�������̰���㷨
*/
#include<iostream>
#include<vector>
#include<iterator>
using namespace std;
const int n=5;// n:�������
// g: ͼ(graph) ���ڽӾ���(adjacent matrix)��ʾ
vector <vector<int> > g;
int s=0;// s:Դ��(source)
vector <bool> know; //know:�����Ƿ���֪���·��
vector <int> dist; //dist:Դ��s����������·����
vector <int> _prev; //_prev :���㵽���·����ǰһ����
void Dijkstra() //̰���㷨ʵ��
{
	//��ʼ��know��dist��_prev
	know.assign(n, false);
	dist.assign(n, INT_MAX);
	_prev.resize(n);
	dist[s] = 0;//��ʼ��Դ�㵽�����·����Ϊ0
	for (;;)
	{
		int min = INT_MAX, v = s;
		for (int i = 0; i < n; ++i)
			if (!know[i] && min>dist[i])
				min = dist[i], v = i;//Ѱ��δ֪�����·�����Ķ���v
		if (min == INT_MAX) break; //����Ҳ������˳�
		know[v] = true; //�ҵ�������v����Ϊ��֪
		for (int w=0; w < n; ++w)// ��������ָ��v�Ķ���w
			if (!know[w] && g[v][w] < INT_MAX&&dist[w] < (dist[v] + g[v][w]))
				//����w�����·����dist �����·����ǰһ���� _prev
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
	//����ͼ
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
