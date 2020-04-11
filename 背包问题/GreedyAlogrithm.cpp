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
