//��С��������̰���㷨Kruskalʵ��
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct Edge
{
	int u, v, w;//u,v��������.w��Ȩֵ
	Edge(){}
	Edge(int u0, int v0, int w0) :u(u0), v(v0), w(w0){}
};

int n;//n:�������
vector<Edge> edges;//edges:ͼg�����б�
int sum;//sum:��С��������
vector<Edge> mst;//mst:��С���������ñ߼���ʾ

class DisjSets
{
	vector<int> s;
public:
	DisjSets(int n) :s(n, -1){};
	int find(int x)//Ѱ�ҵ㼯���ڵ�
	{
		if (s[x] < 0) return x;
		else return s[x] = find(s[x]);//ѹ��·��
	};
	void UnionSets(int root1, int root2)
	{
		if (s[root1] > s[root2])
		{
			s[root2] += s[root1];
			s[root1] = root2;
		}
		else
		{
			s[root1] += s[root2];
			s[root2] = s[root1];
		}
	};
};

bool Cmp(const Edge &lhs, const Edge &rhs)
{
	return lhs.w > rhs.w;
}

bool Kruskal()
{
	DisjSets ds(n);
	make_heap(edges.begin(), edges.end(), Cmp);//�Ա߼�����,��С��������
	int root1, root2;
	Edge e;
	while (!edges.empty())
	{
		//�ӱ���ѡȡȨֵ��С�ñ�e
		e = edges.front();
		/* pop_heap():Swaps the value in the position first and the value in the position last-1
		 *               and makes the subrange [first, last-1) into a max heap
		 */
		pop_heap(edges.begin(), edges.end(), Cmp);
		edges.pop_back();//pop_back():Removes the last element of the container.
		root1 = ds.find(e.u), root2 = ds.find(e.v);//��ȡu,v���ڵĵ㼯
		if (root1 != root2)
		{
			sum += e.w;//������С����������
			mst.push_back(e);//��e������С������mst��ȥ
			ds.UnionSets(root1, root2);
		}
		if (mst.size() == n - 1) return true;
	}
	return false;
}

int main()
{
	n = 6;
	edges.clear();
	edges.push_back(Edge(0, 1, 6)); edges.push_back(Edge(0, 2, 15));
	edges.push_back(Edge(0, 3, 10));
	edges.push_back(Edge(1, 3, 11)); edges.push_back(Edge(1, 4, 8));
	edges.push_back(Edge(2, 3, 5)); edges.push_back(Edge(2, 5, 9));
	edges.push_back(Edge(3, 4, 4)); edges.push_back(Edge(3, 5, 8));
	edges.push_back(Edge(4, 5, 12));
	sum = 0;
	mst.clear();
	if (Kruskal())
	{
		cout << sum << endl;
		for (vector<Edge>::iterator it = mst.begin(); it != mst.end(); ++it)
		{
			cout << it->u << "->" << it->v << endl;
		}
	}
	else
	{
		cout << "�ж��㲻�ܵ���!" << endl;
	}
	return 0;
}