/*0-1背包问题的FIFO分支限界方法*/
/*
* signed - target type will have signed representation (this is the default if omitted)
* unsigned - target type will have unsigned representation
*/
#include<iostream>
#include<stdlib.h>
using namespace std;
const int MAXNUM = 10;
struct node
{
	int step;
	double price;
	double weight;
	double max;
	double min;
	unsigned int  po;
};
typedef struct node DataType;
/*顺序队列类型定义*/
struct SeQueue
{
	int f, r;
	DataType q[MAXNUM];
};
typedef struct SeQueue *pSeQueue;
pSeQueue createEmptyQueue_seq(void)
{
	pSeQueue paqu;
	paqu = (pSeQueue)malloc(sizeof(struct SeQueue));
	if (paqu == NULL)
		cout << "Out of space!!" << endl;
	else
		paqu->f = paqu->r = 0;
	return paqu;
}
int isEmptyQueue_seq(pSeQueue paqu)
{
	return paqu->f == paqu->r;
}
bool isFullQueue_seq(pSeQueue paqu)
{
	return ((paqu->r + 1) % MAXNUM) == paqu->f;
}
/*在队列中插入元素x*/
void enQueue_seq(pSeQueue paqu, DataType x)
{
	if (isFullQueue_seq(paqu))
		cout << "the Queue is Full!"<<endl;
	else
	{
		paqu->q[paqu->r] = x;
		paqu->r = (paqu->r+1) % MAXNUM;
	}
}
/*对非空队列，获取队头元素*/
DataType frontQueue_seq(pSeQueue paqu)
{
	return paqu->q[paqu->f];
}
/*删除队头元素*/
void deQueue_seq(pSeQueue paqu)
{
	if (isEmptyQueue_seq(paqu))
		cout << "Empty Queue!!";
	else
		paqu->f = (paqu->f + 1) % MAXNUM;
}
/*物品按性价比从大到小排序*/
void sort(int n, double p[],double w[])
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i; j < n - 1; j++)
		{
			double a = p[j] / w[j];
			double b = p[j + 1] / w[j + 1];
			if (a < b)//换序(冒泡排序)
			{
				double temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
				temp = w[j];
				w[j] = w[j + 1];
				w[j + 1] = temp;
			}
		}
}
/*求最大可能的值*/
double up(int k, double m, int n, double p[], double w[])
{
	int i = k;
	double s = 0;
	while (i < n && w[i] < m)
	{
		m -= w[i];
		s += p[i];
		i++;
	}
	if (i < n && m>0)
	{
		s = s + m*p[i] / w[i];
		i++;
	}
	return s;
}
/*求最小可能的值*/
double down(int k, double m, int n, double p[], double w[])
{
	int i = k;
	double s = 0;
	while (i < n && w[i] < m)
	{
		m -= w[i];
		s += p[i];
		i++;
	}
	return s;
}
/*用队列实现分支限界法
* << ,>>实现二进制位移操作
* <<:左位移，>>:右位移
*1 << 1 等于 00000001 << 1 等于 00000010 等于十进制 2
*2 << 1 等于 00000010 << 1 等于 00000100 等于十进制 4
*向左移动多位。如向左移 2 位 00001110 << 2 -> 00001110
*/
double solve(double m, int n, double p[], double w[], unsigned long *po)
{
	double min;
	pSeQueue q = createEmptyQueue_seq();
	DataType x = { 0, 0, 0, 0, 0, 0 };
	sort(n, p, w);
	x.max = up(0, m, n, p, w);
	min=x.min = down(0, m, n, p, w);
	if (min == 0) return -1;
	enQueue_seq(q, x);
	while (!isEmptyQueue_seq(q))
	{
		int step;
		DataType y;
		x = frontQueue_seq(q);
		deQueue_seq(q);
		if (x.max < min) continue; //异常处理
		step = x.step + 1;
		if (step == n + 1) continue;//跳出循环
		y.max = x.price + up(step, m - x.weight, n, p, w);
		if (y.max >= min)//右子节点
		{
			y.min = x.price + down(step, m - x.weight, n, p, w);
			y.price = x.price;
			y.weight = x.weight;
			y.step = step;
			y.po = x.po << 1;
			if (y.min >= min)
			{
				min = y.min;
				if (step == n) *po = y.po;
			}
			enQueue_seq(q, y);
		}
		if (x.weight+w[step-1]<=m)//左子节点
		{
			y.max = x.price+p[step-1] + up(step, m - x.weight-w[step-1], n, p, w);
			if (y.max >= min)
			{
				y.min = x.price + p[step - 1] + down(step, m - x.weight-w[step-1], n, p, w);
				y.price = x.price + p[step - 1];
				y.weight = x.weight + w[step - 1];
				y.step = step;
				y.po = (x.po << 1)+1;
				if (y.min >= min)
				{
					min = y.min;
					if (step == n) *po = y.po;
				}
				enQueue_seq(q, y);
			}
		}

	}
	return min;
}
/*背包问题参数*/
const int n = 3;
double m = 30;
double p[n] = { 30, 20, 18 };
double w[n] = { 18, 15, 14 };
int main()
{
	double d;
	unsigned long po;
	d=solve(m, n, p, w, &po);
	if (d == -1)
		cout << "No solution!" << endl;
	else
	{
		for (int i = 0; i < n; i++)
			cout << "x" << i + 1 << "is" << ((po & (1 << (n - i - 1))) != 0) << endl;
		cout << "The max weight is:" << d << endl;
	}
	return 0;
}
