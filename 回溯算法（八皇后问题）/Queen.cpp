/*∞Àª ∫ÛŒ Ã‚*/
#include<iostream>
using namespace std;
const int N = 8;
int x[N + 1];
int Count = 1;
bool canPlace(int i)
{
	for (int k = 1; k <i; k++)
	{
		if (x[k] == x[i] || abs(x[k] - x[i]) == abs(k - i))
			return false;
	}
	return true;
}

void print()
{
	cout << Count << ":";
	for (int i = 1; i <= N; i++)
		cout << x[i] << " ";
	cout << endl;
	Count++;
}

void Queen(int i)
{
	if (i > N)
	{
		print();
		return;
	}
	else
	{
		for (int j = 1; j <= N; j++)
		{
			x[i] = j;
			if (canPlace(i)) Queen(i + 1);
		}
	}
}
int main()
{
	Queen(1);
	return 0;
}