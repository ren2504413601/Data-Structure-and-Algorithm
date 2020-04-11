# 算法与数据结构(五)：背包问题（C++实现）

背包问题分为两类，部分背包问题、背包问题。背包问题是所有装入背包的物品都必须作为一个整体，比如电器、工具等，称之为0-1背包问题。部分背包问题是指装入背包的物品可以被部分装入，比如可以切片的面包等。

对部分背包问题可以描述为给定n种物品和一个背包，n种物品的重量和价值分别为w1,w2,...,wn和v1,v2,...,vn。背包问题可以容纳的总重量为c。选择装入背包的物品，使得装入背包的物品的总价值最大。

#### 头文件定义线性表类的成员变量和成员函数

```c++
#include<iostream>
class GreedyAlogrithm{
public:
	GreedyAlogrithm(int _weight[], int _value[], int capacity);
	double *ComputeRatio();
	void SortRatio(double _Ratio[]);
	double ComputeProfit();
private:
	int *weight;
	int *value;
	int capacity;
	double profit;
};
```

#### 头文件类成员函数的实现

```c++
#include"GreedyAlogrithm.h"
//参数说明: _weight 物品重量,_value 物品价值,_capacity 背包容量
GreedyAlogrithm::GreedyAlogrithm(int _weight[], int _value[], int _capacity)
{
	this->capacity = _capacity;
	this->value = _value;
	this->weight = _weight;
	this->profit = 0;
	return;
}
/*计算出物品的单位价值
*指向函数的指针变量的一个重要作用是把函数的地址作为参数传递到其他函数
*/
double *GreedyAlogrithm::ComputeRatio(){
	double *Ratio = new double[5];
	for (int i = 0; i < 5; i++)
		Ratio[i] = (double)value[i] / weight[i];
	return Ratio;
}
/*根据单位价值大小，对物品的价值重量进行排序*/
void GreedyAlogrithm::SortRatio(double _Ratio[]){
	for (int i = 0; i < 5; i++)
		for (int j = i + 1; j < 5; j++)
		{
			if (_Ratio[j] > _Ratio[i])
			{
				int Temp = _Ratio[j];
				_Ratio[j] = _Ratio[i];
				_Ratio[i] = Temp;

				Temp = value[i];
				value[i] = value[j];
				value[j] = Temp;
			}
		}
	return;
}

/*计算背包内商品的最大价值*/
double GreedyAlogrithm::ComputeProfit()
{
	int temp=0;
	int i = 0;
	while (temp <= capacity)
	{
		if (i == 5) break;
		else {
			if ((weight[i] + temp) <= capacity)
			{
				profit += value[i];
				temp += weight[i];
			}
			else if ((weight[i] + temp) > capacity)
			{
				int _weight = capacity - temp;
				double _Ratio =(double) value[i] / weight[i];
				profit +=_Ratio* _weight;
				temp += _weight;
			}
		}
		i++;
	}
	return profit;
}
```

#### 主函数

```c++
#include<iostream>
#include"GreedyAlogrithm.h"
using namespace std;
int main()
{
	int _weight[5] = { 1, 2, 3, 4, 5 };
	int _value[5] = {3,10,6,3,5};
	int _capacity = 10;
	GreedyAlogrithm *greedy = new GreedyAlogrithm(_weight, _value, _capacity);
	greedy->SortRatio(greedy->ComputeRatio());
	cout << "The Maximum Profit is: " << greedy->ComputeProfit() << endl;
	return 0;
}
```

程序运行结果如下图所示：

![线性表](C:\Users\Administrator\Documents\Visual Studio 2013\Projects\背包问题\背包问题.JPG)

#### 参考：算法分析与设计(C++描述) 石志国、刘冀伟、姚亦飞编著