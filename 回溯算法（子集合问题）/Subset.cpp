/*�Ӽ�������*/
#include<iostream>
using namespace std;
const int N = 4;
int s[N] = {3,5,7,9};
int x[N];
void print()
{
	for (int i = 0; i < N; i++)
	{
		if (x[i] == 1) cout << s[i]<<" ";
	}
	cout << endl;
	//return;
}
void Subset(int i)
{
	if (i >= N)
	{
		print();
		//return;
	}
	else
	{
		x[i] = 1;//����������
		Subset(i + 1);

		x[i] = 0;//����������
		Subset(i + 1);
	}
}
int main()
{
	cout << "������Ӽ���Ϊ:" << endl;
	Subset(0);
	return 0;
}