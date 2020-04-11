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