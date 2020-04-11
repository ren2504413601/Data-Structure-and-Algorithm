/*小老鼠走迷宫问题*/
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
public://i,j表示迷宫的行，列
	int i;
	int j;
	int dir;//标志哪些已经被找过的路径
};
stac stack[MaxSize];
int top = -1;//栈的指针,指向当前位置
void Maze()
{
	int ii, jj, di, find;
	top++;
	stack[top].i = 1;//左上角开始(1,1)
	stack[top].j = 1;
	stack[top].dir = -1;
	mg[1][1] = -1;
	while (top > -1)
	{
		ii = stack[top].i;
		jj = stack[top].j;
		di = stack[top].dir;//位置:0 1 2 3->上 右 下 左
		if (ii == M - 2 && jj == N - 2)//到了目标地点(8,8),输出行走的路径并返回
		{
			cout << "迷宫通路" << endl;
			for (int k = 0; k <= top; k++)
			{
				cout << "(" << stack[k].i << "," << stack[k].j << ")";
					if ((k + 1) % 5 == 0) 
						cout << endl;
			}
			cout << endl;
			return;
		}
		find = 0;//0代表还未发现目的地
		while (di < 4 && find == 0)//循环四面的方块看哪一个是0
		{
			di++;
			switch (di)//确定下一个搜索位置
				{
			case 0:ii = stack[top].i - 1; jj = stack[top].j; break;//上
			case 1:ii = stack[top].i; jj = stack[top].j+1; break;//右
			case 2:ii = stack[top].i + 1; jj = stack[top].j; break;//下
			case 3:ii = stack[top].i; jj = stack[top].j-1; break;//左
			}
			if (mg[ii][jj] == 0) find = 1;
		}
		if (find == 1)//找到了，就近栈
		{
			stack[top].dir = di;
			top++;
			stack[top].i = ii;
			stack[top].j = jj;
			cout << "进栈:(" << stack[top].i << "," << stack[top].j << "," << di << ")" << endl;
			stack[top].dir = -1;//进栈后将栈的位置设置为-1，以防止返回寻找异常
			mg[ii][jj] = -1;
		}
		else //找不到，退栈
		{
			cout << "出栈:" << stack[top].i << "," << stack[top].j<<endl;
			mg[stack[top].i][stack[top].j] = 0;//出栈后把相应位置重新设置成0
			top--;
		}
	}
	cout << "没有路可走了!" << endl;
}
int main()
{
	Maze();
	return 0;
}
