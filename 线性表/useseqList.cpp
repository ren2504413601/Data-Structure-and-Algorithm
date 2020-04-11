#include"seqList.h"
using namespace std;
void main()
{
	cout << "创建表A:" << endl;
	SqList sqa;
	sqa.create();
	cout << "创建表B:" << endl;
	SqList sqb;
	sqb.create();
	cout << "合并A、B,把A、B的值一起放入表C,并且按照从小到大排序!" << endl;
	SqList sqc;
	sqc.merge(sqa, sqb);
	cout << "操作表C" << endl;
	cout << "选择操作(Q)退出!" << endl;
	cout << "1.查看表情况(A):" << endl;
	cout << "2.查看表特定元素(C):" << endl;
	cout << "3.插入表尾元素(I):" << endl;
	cout << "4.插入特定位置元素(L):" << endl;
	cout << "5.删除元素(D):" << endl;
	char str;
	cin >> str;
	while (toupper(str) != 'Q')
	{
		switch (toupper(str))
		{
		case 'A':
			sqc.displayElem();
			break;
		case 'C':
			cout << "请输入要查看的位置:";
			int i;
			cin >> i;
			cout << "表中第i个元素:" << sqc.getElem(i)<<endl;
			break;
		case 'I':
			cout << "请输入要插入表尾的元素";
			int elem;
			cin >> elem;
			sqc.insert(elem);
			sqc.displayElem();
			break;
		case 'L':
			int jelem, j;
			cout << "请输入要插入的元素:";
			cin >> jelem;
			cout << "输入要插入的位置:";
			cin >> j;
			sqc.insert(j, jelem);
			sqc.displayElem();
			break;
		case 'D':
			cout << "输入删除元素所处的位置:";
			int k;
			cin >> k;
			sqc.del(k);
			sqc.displayElem();
			break;
		default:
			cout << "输入选项不正确，请重新输入!" << endl;
		}
		cout << "输入选项继续操作!";
		cin >> str;
	}
	cout << "操作结束!"<<endl;
	cin.get();
	cin.get();
}