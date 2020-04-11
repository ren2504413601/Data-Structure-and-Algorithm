#include"seqList.h"
using namespace std;
//���캯��
SqList::SqList(){
	elem = new ElemType[initSize];
	length = 0;
	listsize = initSize;
}
//�Ƿ�Ϊ��
bool SqList::isFull()const{
	return length == listsize;
}
//�Ƿ���
bool SqList::isEmpty()const{
	return length == 0;
}
//��������
SqList::~SqList(){
	delete[]elem;
}
//��ȡ���Ԫ��(ע�⣺����Ҫ�����λ��i��ָ�б�ĵ�i��Ԫ�ص�λ��,��Ӧ��������Ӧ����i-1������Ԫ��(inset)����)
ElemType SqList::getElem(int i)const{
	if (i<1 || i>length)
	{
		cout << "i-value is illegal!";
		return 0;
	}
	else return elem[i-1];
}
//�ض�λ�ò���Ԫ��
bool SqList::insert(int i,ElemType e){
	if (i<1 || i>length+1)
	{
		cout << "i-value is illegal!";
		return 0;
	}
	//�������·����ڴ�
	if (isFull())
	{
		ElemType* newBase = new ElemType[listsize + increment];
		for (int j = 0; j < listsize; j++)
		{
			newBase[i] = elem[i];
		}
		delete[]elem;
		elem = newBase;
		listsize += increment;
	}
	ElemType *p = &(elem[i - 1]);
	ElemType *q = &(elem[length - 1]);
	for (; q >= p; --q)
	{
		*(q + 1) = *(q);
	}
	*p = e;
	++length;
	return 1;
}
//��ĩ����Ԫ��
bool SqList::insert(ElemType e){
	//�������·����ڴ�
	if (isFull())
	{
		ElemType* newBase = new ElemType[listsize + increment];
		for (int j = 0; j < listsize; j++)
		{
			newBase[j] = elem[j];
		}
		delete[]elem;
		elem = newBase;
		listsize += increment;
	}
	ElemType *p = &(elem[length]);
	*p = e;
	++length;
	return 1;
}

//ɾ����
void SqList::create(){
	cout << "Ϊ�����Ԫ��(���0�˳�)!" << endl;
	while (1)
	{
		int elem;
		cin >> elem;
		if (elem != 0)
		{
			insert(elem);
		}
		else
		{
			cout << "������ϣ���СΪ" << listsize << "." << endl;
			cout << "������" << length << "��Ԫ��:"<< endl;
			for (int i = 1; i <= length; i++)
			{
				cout << getElem(i) << ",";
			}
			cout << endl;
			break;
		}
		
	}
}
//�ϲ���
void SqList::merge(SqList &La, SqList &Lb)
{
	int i = 1, j = 1, k = 0;
	while (i<=La.length&&j<=Lb.length)
		{
			if (La.getElem(i) <= Lb.getElem(j))
			{
				insert(++k,La.getElem(i));
				++i;
			}
			else
			{
				insert(++k,Lb.getElem(j));
				++j;
			}
	}
	while (i <= La.length)
		{
			insert(++k, La.getElem(i));
			++i;
	}
	while (j <= Lb.length)
		{
			insert(++k, Lb.getElem(j));
			++j;
	}
	cout << "�ϲ����Ԫ��Ϊ��" << endl;
	for (int m = 1; m <= length; m++)
		cout << getElem(m) << ",";
	cout << endl;
}
//ɾ����Ԫ��
bool SqList::del(int i){
	if (i<1 || i>length)
	{
		cout << "i-value is illegal!";
		return 0;
	}
	else
	{
		ElemType *p = &(elem[i - 1]);
		ElemType *q = &(elem[length - 1]);
		for (++p; p <= q; ++p)
		{
			*(p - 1) = *p;
		}
		--length;
		return 1;
	}
}
void SqList::displayElem()
{
	cout << "��Ĵ�СΪ:" << listsize << "." << endl;
	cout << "������" << length << "��Ԫ��:" << endl;
	for (int i = 1; i <= length; i++)
	{
		cout << getElem(i) << ",";
	}
	cout << endl;
}
