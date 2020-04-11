#include"seqList.h"
using namespace std;
//构造函数
SqList::SqList(){
	elem = new ElemType[initSize];
	length = 0;
	listsize = initSize;
}
//是否为空
bool SqList::isFull()const{
	return length == listsize;
}
//是否满
bool SqList::isEmpty()const{
	return length == 0;
}
//析构函数
SqList::~SqList(){
	delete[]elem;
}
//读取表的元素(注意：这里要插入的位置i是指列表的第i个元素的位置,对应出的索引应该是i-1，插入元素(inset)类似)
ElemType SqList::getElem(int i)const{
	if (i<1 || i>length)
	{
		cout << "i-value is illegal!";
		return 0;
	}
	else return elem[i-1];
}
//特定位置插入元素
bool SqList::insert(int i,ElemType e){
	if (i<1 || i>length+1)
	{
		cout << "i-value is illegal!";
		return 0;
	}
	//表满重新分配内存
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
//表末插入元素
bool SqList::insert(ElemType e){
	//表满重新分配内存
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

//删除表
void SqList::create(){
	cout << "为表添加元素(输出0退出)!" << endl;
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
			cout << "表创建完毕，大小为" << listsize << "." << endl;
			cout << "表现有" << length << "个元素:"<< endl;
			for (int i = 1; i <= length; i++)
			{
				cout << getElem(i) << ",";
			}
			cout << endl;
			break;
		}
		
	}
}
//合并表
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
	cout << "合并后的元素为：" << endl;
	for (int m = 1; m <= length; m++)
		cout << getElem(m) << ",";
	cout << endl;
}
//删除表元素
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
	cout << "表的大小为:" << listsize << "." << endl;
	cout << "表现有" << length << "个元素:" << endl;
	for (int i = 1; i <= length; i++)
	{
		cout << getElem(i) << ",";
	}
	cout << endl;
}
