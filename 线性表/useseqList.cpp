#include"seqList.h"
using namespace std;
void main()
{
	cout << "������A:" << endl;
	SqList sqa;
	sqa.create();
	cout << "������B:" << endl;
	SqList sqb;
	sqb.create();
	cout << "�ϲ�A��B,��A��B��ֵһ������C,���Ұ��մ�С��������!" << endl;
	SqList sqc;
	sqc.merge(sqa, sqb);
	cout << "������C" << endl;
	cout << "ѡ�����(Q)�˳�!" << endl;
	cout << "1.�鿴�����(A):" << endl;
	cout << "2.�鿴���ض�Ԫ��(C):" << endl;
	cout << "3.�����βԪ��(I):" << endl;
	cout << "4.�����ض�λ��Ԫ��(L):" << endl;
	cout << "5.ɾ��Ԫ��(D):" << endl;
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
			cout << "������Ҫ�鿴��λ��:";
			int i;
			cin >> i;
			cout << "���е�i��Ԫ��:" << sqc.getElem(i)<<endl;
			break;
		case 'I':
			cout << "������Ҫ�����β��Ԫ��";
			int elem;
			cin >> elem;
			sqc.insert(elem);
			sqc.displayElem();
			break;
		case 'L':
			int jelem, j;
			cout << "������Ҫ�����Ԫ��:";
			cin >> jelem;
			cout << "����Ҫ�����λ��:";
			cin >> j;
			sqc.insert(j, jelem);
			sqc.displayElem();
			break;
		case 'D':
			cout << "����ɾ��Ԫ��������λ��:";
			int k;
			cin >> k;
			sqc.del(k);
			sqc.displayElem();
			break;
		default:
			cout << "����ѡ���ȷ������������!" << endl;
		}
		cout << "����ѡ���������!";
		cin >> str;
	}
	cout << "��������!"<<endl;
	cin.get();
	cin.get();
}