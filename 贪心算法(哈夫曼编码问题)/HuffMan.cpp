/*��������������
* HuffMan.cpp
*/
#include<iostream>
#include<string>
using namespace std;
typedef struct
{
	int weight;
	int flag;
	int parent;
	int lchild;
	int rchild;
}hnodetype;//���������ṹ
typedef struct
{
	int bit[10];
	int start;
	char leaf;
}hcodetype;//�����¼
void huf(char cha[], int m[], int n)
//cha:��ǰ�����ַ���m:ÿ���ַ����ֵĴ���,n:�ַ��ܸ���
{
	int c,i,j,m1,m2,x1,x2,p;
	hnodetype *huffnode = new hnodetype[2 * n - 1];
	hcodetype *huffcode = new hcodetype[n],cd;
	//��ʼ����������
	for (i = 0; i < 2 * n - 1; i++)
	{
		huffnode[i].flag = 0;
		huffnode[i].lchild = -1;
		huffnode[i].rchild = -1;
		huffnode[i].parent= 0;
		huffnode[i].weight = 0;
	}
	for (i = 0; i < n; i++)
	{
		huffnode[i].weight=m[i];
		huffcode[i].leaf = cha[i];
	}
	for (i = 0; i < n - 1; i++)//����Ѱ����������,��x1,x2��¼
	{
		m1 = m2 = INT_MAX;
		x1 = x2 = 0;
		for (j = 0; j < n+i; j++)
		{
			if (huffnode[j].weight <= m1 && huffnode[j].flag == 0)
			{
				x2 = x1;
				x1 = j;
				m2 = m1;
				m1 = huffnode[j].weight;
			}
			else if (huffnode[j].weight <= m2 && huffnode[j].flag == 0)
			{
				x2 = j;
				m2 = huffnode[j].weight;
			}
		}
		huffnode[x1].parent = n + i;
		huffnode[x2].parent = n + i;
		huffnode[x1].flag = 1;
		huffnode[x2].flag = 1;
		huffnode[n + i].weight = huffnode[x1].weight + huffnode[x2].weight;
		huffnode[n + i].lchild = x1;
		huffnode[n + i].rchild = x2;
	}
	//���ɹ��������ı���
	for (i = 0; i < n; i++)
	{
		cd.start = n - 1;
		c = i;
		p=huffnode[c].parent;
		while (p != 0)
		{
			if (huffnode[p].lchild == c) cd.bit[cd.start] = 0;
			else cd.bit[cd.start] = 1;
			cd.start--;
			c = p;
			p = huffnode[c].parent;
		}
		cout << huffcode[i].leaf << ":";
		for (j = cd.start + 1; j < n; j++)
		{
			huffcode[i].bit[j] = cd.bit[j];
			cout << cd.bit[j];
		}
		cout << endl;
		huffcode[i].start = cd.start;
	}
	delete[] huffcode;
	delete[] huffnode;
}
void main()
{
	string str;
	int i = 0, j, n, m[100], h, k = 0;
	char cha[100];
	cout << "����һ���ַ���!" << endl;
	cin >> str;
	n=str.length();
	cout << "�ַ�������" << n << "���ַ�" << endl;
	//��������ַ�ɨ�裬ͳ�Ƴ�ÿ���ַ����ֵĴ���
	for (i = 0; i < n; i++)
	{
		j = 0;
		h = 0;
		while (str[j] != str[i]) j++;
		if (i == j)
		{
			cout << "�ַ�" << str[i] << "����";
			cha[k] = str[i];
		}
		else continue;
		for (j = i; j < n; j++)
		{
			if (str[i] == str[j])
				h++;
		}
		cout << h << "��"<<endl;
		m[k] = h;
		k++;
	}
	cout << "ÿ���ַ��Ĺ�����������:" << endl;
	huf(cha, m, k);
}