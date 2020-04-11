/*С�������Թ�����*/
#include<iostream>
using namespace std;
#define M 10
#define N 10
#define MaxSize 100
int mg[M + 1][N + 1] = {
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 1, 0, 0, 0, 1, 0, 1 },
	{ 1, 0, 0, 1, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 1, 1, 0, 0, 1 },
	{ 1, 0, 1, 1, 1, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
	{ 1, 0, 1, 0, 0, 0, 1, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 0, 1, 1, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
};
class stac
{
public://i,j��ʾ�Թ����У���
	int i;
	int j;
	int dir;//��־��Щ�Ѿ����ҹ���·��
};
stac stack[MaxSize];
int top = -1;//ջ��ָ��,ָ��ǰλ��
void Maze()
{
	int ii, jj, di, find;
	top++;
	stack[top].i = 1;//���Ͻǿ�ʼ(1,1)
	stack[top].j = 1;
	stack[top].dir = -1;
	mg[1][1] = -1;
	while (top > -1)
	{
		ii = stack[top].i;
		jj = stack[top].j;
		di = stack[top].dir;//λ��:0 1 2 3->�� �� �� ��
		if (ii == M - 2 && jj == N - 2)//����Ŀ��ص�(8,8),������ߵ�·��������
		{
			cout << "�Թ�ͨ·" << endl;
			for (int k = 0; k <= top; k++)
			{
				cout << "(" << stack[k].i << "," << stack[k].j << ")";
					if ((k + 1) % 5 == 0) 
						cout << endl;
			}
			cout << endl;
			return;
		}
		find = 0;//0����δ����Ŀ�ĵ�
		while (di < 4 && find == 0)//ѭ������ķ��鿴��һ����0
		{
			di++;
			switch (di)//ȷ����һ������λ��
				{
			case 0:ii = stack[top].i - 1; jj = stack[top].j; break;//��
			case 1:ii = stack[top].i; jj = stack[top].j+1; break;//��
			case 2:ii = stack[top].i + 1; jj = stack[top].j; break;//��
			case 3:ii = stack[top].i; jj = stack[top].j-1; break;//��
			}
			if (mg[ii][jj] == 0) find = 1;
		}
		if (find == 1)//�ҵ��ˣ��ͽ�ջ
		{
			stack[top].dir = di;
			top++;
			stack[top].i = ii;
			stack[top].j = jj;
			cout << "��ջ:(" << stack[top].i << "," << stack[top].j << "," << di << ")" << endl;
			stack[top].dir = -1;//��ջ��ջ��λ������Ϊ-1���Է�ֹ����Ѱ���쳣
			mg[ii][jj] = -1;
		}
		else //�Ҳ�������ջ
		{
			cout << "��ջ:" << stack[top].i << "," << stack[top].j<<endl;
			mg[stack[top].i][stack[top].j] = 0;//��ջ�����Ӧλ���������ó�0
			top--;
		}
	}
	cout << "û��·������!" << endl;
}
int main()
{
	Maze();
	return 0;
}
