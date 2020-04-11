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