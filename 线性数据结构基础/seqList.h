//完整线性表例子
#include<iostream>
#ifndef SqList_H
#define SqList_H_//定义头文件
#define initsize 100
#define increment 10
typedef int ElemType;//定义元素类型
class SqList
{
private:
	ElemType *elem;//声明元素指针
	int length;
	int listsize;
public:
	SqList();//初始化表
	bool isFull()const;//查看表是否满
	bool isEmpty()const;//查看表是否空
	ElemType getElem(int)const;//查看特定位置元素
	bool insert(int,ElemType);//插入特定位置元素
	bool insert(ElemType);//插入表尾元素
	void creat();//创建表
	void merge(SqList&,SqList&);//合并表并排序
	bool del(int);//删除表
	void displayElem();//显示表情况
	~SqList();//析构

};
#endif