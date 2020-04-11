#include<iostream>
#include<stdlib.h>
using namespace std;
#define INFINITY 0
#define MAX_VERTEX_NUM 10//最大顶点数
#define MAX_EDGE_NUM 40//最大边个数
typedef enum { DG, DN, UDG, UDN }Graphkind;//图的类型  enum:Enumeration declaration
typedef char VertexType;//顶点数据类型
typedef struct ArcCell
{
	int adj;//无权图(0,1代表是否相邻1为相邻),带权图是权值
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct
{
	VertexType vexs[MAX_VERTEX_NUM];//顶点向量
	AdjMatrix arcs;//邻接矩阵
	int vexnum, arcnum;//图的当前定点个数和弧数
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
int CreateUDN(MGraph &G)//采用数组表示法，构造无向网G
{
	VertexType v1, v2;
	cout << "输入图的顶点个数:" << endl;
	cin >> G.vexnum;
	cout << "输入图的边个数:" << endl;
	cin >> G.arcnum;
	int i, j;
	for (i = 0; i < G.vexnum; i++)
	{
		cout << "输入顶点向量:"<< endl;
		cin>>G.vexs[i];
	}
	for (i = 0; i < G.vexnum; i++)
		for (j = 0; j < G.vexnum; j++)
			G.arcs[i][j].adj = INFINITY;
	int w;
	for (int k = 0; k < G.arcnum; ++k)//构造邻接矩阵
	{
		cout << "输入边依附的两个顶点:" << endl;
		cin >> v1 >> v2;
		cout << "输入此边的权值:" << endl;
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
	cout << "图的邻接矩阵是：" << endl;
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