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
	void displayElem();//显示表情况
};
#endif