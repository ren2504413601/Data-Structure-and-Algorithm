#include<iostream>
#include<stdlib.h>
using namespace std;
#define INFINITY 0
#define MAX_VERTEX_NUM 10//��󶥵���
#define MAX_EDGE_NUM 40//���߸���
typedef enum { DG, DN, UDG, UDN }Graphkind;//ͼ������  enum:Enumeration declaration
typedef char VertexType;//������������
typedef struct ArcCell
{
	int adj;//��Ȩͼ(0,1�����Ƿ�����1Ϊ����),��Ȩͼ��Ȩֵ
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct
{
	VertexType vexs[MAX_VERTEX_NUM];//��������
	AdjMatrix arcs;//�ڽӾ���
	int vexnum, arcnum;//ͼ�ĵ�ǰ��������ͻ���
	Graphkind kind;
}MGraph;
int LocateVex(MGraph G, VertexType v1)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		if (G.vexs[i] == v1)
			return i;
	}
	return -1;
}
int CreateUDN(MGraph &G)//���������ʾ��������������G
{
	VertexType v1, v2;
	cout << "����ͼ�Ķ������:" << endl;
	cin >> G.vexnum;
	cout << "����ͼ�ı߸���:" << endl;
	cin >> G.arcnum;
	int i, j;
	for (i = 0; i < G.vexnum; i++)
	{
		cout << "���붥������:"<< endl;
		cin>>G.vexs[i];
	}
	for (i = 0; i < G.vexnum; i++)
		for (j = 0; j < G.vexnum; j++)
			G.arcs[i][j].adj = INFINITY;
	int w;
	for (int k = 0; k < G.arcnum; ++k)//�����ڽӾ���
	{
		cout << "�������������������:" << endl;
		cin >> v1 >> v2;
		cout << "����˱ߵ�Ȩֵ:" << endl;
		cin >> w;
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		G.arcs[i][j].adj = w;
		G.arcs[j][i].adj = G.arcs[i][j].adj;
	}
	return 1;
}
void dispMGraph(MGraph G)
{
	cout << "ͼ���ڽӾ����ǣ�" << endl;
	for (int i = 0; i < G.vexnum; i++)
	{
		for (int j = 0; j < G.vexnum; j++)
			cout << G.arcs[i][j].adj;
		cout << endl;
	}
}

void main()
{
	MGraph G;
	CreateUDN(G);
	dispMGraph(G);
}