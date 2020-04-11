#include"GreedyAlogrithm.h"
//����˵��: _weight ��Ʒ����,_value ��Ʒ��ֵ,_capacity ��������
GreedyAlogrithm::GreedyAlogrithm(int _weight[], int _value[], int _capacity)
{
	this->capacity = _capacity;
	this->value = _value;
	this->weight = _weight;
	this->profit = 0;
	return;
}
/*�������Ʒ�ĵ�λ��ֵ
*ָ������ָ�������һ����Ҫ�����ǰѺ����ĵ�ַ��Ϊ�������ݵ���������
*/
double *GreedyAlogrithm::ComputeRatio(){
	double *Ratio = new double[5];
	for (int i = 0; i < 5; i++)
		Ratio[i] = (double)value[i] / weight[i];
	return Ratio;
}
/*���ݵ�λ��ֵ��С������Ʒ�ļ�ֵ������������*/
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

/*���㱳������Ʒ������ֵ*/
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
