/*全排列问题*/
#include<iostream>
using namespace std;
const int N = 4;
int s[N] = { 3, 5, 7, 9 };
void print()
{
	for (int i = 0; i < N; i++)
	{
		cout << s[i] << " ";
	}
	cout << endl;
	//return;
}
void swap(int *a, int i, int j)
{
	int temp;
	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}
void backTrack(int i)
{
	if (i >= N) print();
	else
	{
		for (int j = i; j < N; j++)
		{
			swap(s, i, j);
			backTrack(i + 1);
			swap(s, i, j);
		}
	}
}
int main()
{
	cout << "所有的组合为:" << endl;
	backTrack(0);
	return 0;
}