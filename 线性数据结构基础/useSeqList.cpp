#include"seqList.h"
using namespace std;
void main()
{
	cout<<"����A:"<<endl;
	SqList sqa;
	sqa.creat();
	cout<<"����B:"<<endl;
	SqList sqb;
	sqb.creat();
	cout<<"�ϲ���A��B��Ԫ�أ�������С�����˳������C!"<<endl;
	SqList sqc;
	sqc.merge(sqa,sqb);
	cout<<"������C:"<<endl;
	cout<<"ѡ�����(A)"<<endl;
	cout<<"2.�鿴����ض����(C)"<<endl;
	cout<<"3.�����βԪ��(I)"<<endl;
	cout<<"4.�����ض�λ��Ԫ��(L)"<<endl;
	cout<<"5.ɾ��Ԫ��(D)"<<endl;
	char str;
	cin>>str;
//touppper()���ض�Ӧ�Ĵ�д��ĸ�����򷵻�ԭ����ֵ
	while(toupper(str)!='Q')
	{
		switch(toupper(str))
		{
		case 'A':
			sqc.displayElem();
			break;
		case 'C':
			cout<<"������Ҫ�鿴Ԫ�ص�λ��";
			int i;
			cin>>i;
			cout<<"��C�е�"<<i<<"��Ԫ��Ϊ��"<<sqc.getElem(i)<<endl;
			break;
		case 'I':
			cout<<"��������Ҫ���뵽��β��Ԫ��:";
			int elem;
			cin>>elem;
			sqc.insert(elem);
			sqc.displayElem();
			break;
		case 'L':
			cout<<"��������������뵽���λ�ú�Ԫ�أ�";
			int j,jelem;
			cin>>j;
			cin>>jelem;
			sqc.insert(j,jelem);
			sqc.displayElem();
			break;
		case 'D':
			cout<<"��������Ҫɾ��Ԫ�ص�λ�ã�";
			int k;
			cin>>k;
			sqc.del(k);
			sqc.displayElem();
			break;
		default:
			cout<<"��������ȷѡ��!"<<endl;
		}
		cout<<"������ѡ���������:";
		cin>>str;
	}
	cout<<"��������!"<<endl;
	cin.get();
	cin.get();


}