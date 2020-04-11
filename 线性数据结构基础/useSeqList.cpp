#include"seqList.h"
using namespace std;
void main()
{
	cout<<"创建A:"<<endl;
	SqList sqa;
	sqa.creat();
	cout<<"创建B:"<<endl;
	SqList sqb;
	sqb.creat();
	cout<<"合并表A、B的元素，并按从小到大的顺序放入表C!"<<endl;
	SqList sqc;
	sqc.merge(sqa,sqb);
	cout<<"操作表C:"<<endl;
	cout<<"选择操作(A)"<<endl;
	cout<<"2.查看表的特定情况(C)"<<endl;
	cout<<"3.插入表尾元素(I)"<<endl;
	cout<<"4.插入特定位置元素(L)"<<endl;
	cout<<"5.删除元素(D)"<<endl;
	char str;
	cin>>str;
//touppper()返回对应的大写字母，否则返回原来的值
	while(toupper(str)!='Q')
	{
		switch(toupper(str))
		{
		case 'A':
			sqc.displayElem();
			break;
		case 'C':
			cout<<"请输入要查看元素的位置";
			int i;
			cin>>i;
			cout<<"表C中第"<<i<<"个元素为："<<sqc.getElem(i)<<endl;
			break;
		case 'I':
			cout<<"请输入需要插入到表尾的元素:";
			int elem;
			cin>>elem;
			sqc.insert(elem);
			sqc.displayElem();
			break;
		case 'L':
			cout<<"请依次输入需插入到表的位置和元素：";
			int j,jelem;
			cin>>j;
			cin>>jelem;
			sqc.insert(j,jelem);
			sqc.displayElem();
			break;
		case 'D':
			cout<<"请输入需要删除元素的位置：";
			int k;
			cin>>k;
			sqc.del(k);
			sqc.displayElem();
			break;
		default:
			cout<<"请输入正确选项!"<<endl;
		}
		cout<<"请输入选项继续操作:";
		cin>>str;
	}
	cout<<"操作结束!"<<endl;
	cin.get();
	cin.get();


}