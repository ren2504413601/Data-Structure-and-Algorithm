/*������������
* X={x1,x2,...,xn}��ʾ�����ĸ������ĸ߶�
* d[i]��¼��iö����������֮������ϵͳ��໹�����صĵ������������������صĵ�iö������
* ��xk��X�����е���Сֵ��d(xk)=1
* d(xn)=1. �������d>=1.
*/
#include<iostream>
using namespace std;
const int N = 10;// ��󵼵�����
int x[N], d[N];

int main()
{
	int i,j,n;
	int dmax = 0, xh = 0;//dmax:���������صĵ���������xh:��һö���صĵ������
	cout << "����Ҫ���صĵ�������:" << endl;
	cin >> n;
	cout << "����ÿ�������ĸ߶ȣ�" << endl;
	for (i = 0; i < n; i++)
	{
		cin >> x[i];
		d[i] = 1;
	}
	for (i = n - 2; i >= 0; i--)//��̬�滮�㷨���Ӻ�����ǰ����
	{
		for (j = i + 1; j < n; j++)//������ǰ�ڵ��������нڵ�,�������������������
			if (x[j] <= x[i] && d[i] < (d[j] + 1))
				d[i] = d[j] + 1;
	}
	//�ҳ�������еĸ����͵�һö���ص��������
	for (i = 0; i < n; i++)
	{
		if (dmax < d[i])
		{
			dmax = d[i];
			xh = i;
		}	
	}
	cout << "���������صĵ�����Ϊ��" << dmax << endl;
	cout << "�����صĵ����߶������ǣ�";
	//������������
	cout << x[xh] << " ";
	int itemp = xh;
	for (i = xh+1; i < n;i++)
	{
		if ((x[i] <= x[itemp]) && (d[itemp] == d[i] + 1))
		{
			cout << x[i]<<" ";
			itemp = i;
		}
	}

	cout << endl;
	return 0;
}