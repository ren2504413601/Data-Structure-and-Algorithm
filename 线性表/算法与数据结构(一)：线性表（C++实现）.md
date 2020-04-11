# 算法与数据结构(一)：线性表（C++实现）

在计算机内存中存放线性表的最简单和最常用的方式使用一组地址上连续的存储单元依次存储线性表的每一个元素。使线性表中相邻的元素存放在地址中相邻的物理存储单元中，这种存储结构称作顺序表。

对于顺序表可以执行很多操作。下面主要介绍用于数组描述的顺序表所进行的空间分配、元素插入、元素删除等操作。

#### 头文件定义线性表类的成员变量和成员函数

```c++
#include<iostream>
#ifndef SqList_H_ //没有定义"SqList_H_"则编译下面的语句，以防止命名冲突
#define SqList_H_//定义头文件
#define initSize 100//初始化线性表大小
#define increment 10 //增长步长
typedef int ElemType;//定义元素类型(int)
class SqList
{
private:
	ElemType *elem;//申明元素指针
	int length;//元素个数
	int listsize;//表长度
public:
	SqList();//构造函数
	bool isFull()const;//查看表是否空
	bool isEmpty()const;//查看表是否满
	~SqList();//析构函数
	ElemType getElem(int)const;//查看特定位置元素
	bool insert(int, ElemType);//插入特定位置元素
	bool insert(ElemType);//插入表末元素
	void create();//创建表
	void merge(SqList&, SqList&);//合并表排序
	bool del(int);//删除表元素
	void displayem();//显示表情况
};
#endif
```

注意：”ifndef SqList_H_“宏定义说明如果没有定义“SqList_H_”则编译下面的语句，防止命名冲突

#### 头文件类成员函数的实现

```c++
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
```

#### 主函数

```c++
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
```

简单的例子实现两个顺序表的合并，合并后得到的新的顺序表执行以下五种操作：查看表情况、查看表特定元素、在表末插入元素、在表特定位置插入元素、删除元素。程序运行结果如下图所示：

![线性表](C:\Users\Administrator\Documents\Visual Studio 2013\Projects\线性表\线性表.JPG)

#### 参考：算法分析与设计(C++描述) 石志国、刘冀伟、姚亦飞编著