//�������Ա�����
#include<iostream>
#ifndef SqList_H
#define SqList_H_//����ͷ�ļ�
#define initsize 100
#define increment 10
typedef int ElemType;//����Ԫ������
class SqList
{
private:
	ElemType *elem;//����Ԫ��ָ��
	int length;
	int listsize;
public:
	SqList();//��ʼ����
	bool isFull()const;//�鿴���Ƿ���
	bool isEmpty()const;//�鿴���Ƿ��
	ElemType getElem(int)const;//�鿴�ض�λ��Ԫ��
	bool insert(int,ElemType);//�����ض�λ��Ԫ��
	bool insert(ElemType);//�����βԪ��
	void creat();//������
	void merge(SqList&,SqList&);//�ϲ�������
	bool del(int);//ɾ����
	void displayElem();//��ʾ�����
	~SqList();//����

};
#endif