/*导弹拦截问题
* X={x1,x2,...,xn}表示飞来的各导弹的高度
* d[i]记录第i枚导弹被拦截之后，这套系统最多还能拦截的导弹数量（包含被拦截的第i枚导弹）
* 若xk是X序列中的最小值，d(xk)=1
* d(xn)=1. 其它情况d>=1.
*/
#include<iostream>
using namespace std;
const int N = 10;// 最大导弹数量
int x[N], d[N];

int main()
{
	int i,j,n;
	int dmax = 0, xh = 0;//dmax:最多可以拦截的导弹数量，xh:第一枚拦截的导弹序号
	cout << "输入要拦截的导弹数量:" << endl;
	cin >> n;
	cout << "输入每个导弹的高度：" << endl;
	for (i = 0; i < n; i++)
	{
		cin >> x[i];
		d[i] = 1;
	}
	for (i = n - 2; i >= 0; i--)//动态规划算法，从后面向前搜索
	{
		for (j = i + 1; j < n; j++)//遍历当前节点后面的所有节点,在子序列中找最长子序列
			if (x[j] <= x[i] && d[i] < (d[j] + 1))
				d[i] = d[j] + 1;
	}
	//找出最长子序列的个数和第一枚拦截导弹的序号
	for (i = 0; i < n; i++)
	{
		if (dmax < d[i])
		{
			dmax = d[i];
			xh = i;
		}	
	}
	cout << "最多可以拦截的导弹数为：" << dmax << endl;
	cout << "被拦截的导弹高度依次是：";
	//依次输出最长序列
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