#include<iostream>
#ifndef SqList_H_ //û�ж���"SqList_H_"������������䣬�Է�ֹ������ͻ
#define SqList_H_//����ͷ�ļ�
#define initSize 100//��ʼ�����Ա��С
#define increment 10 //��������
typedef int ElemType;//����Ԫ������(int)

class SqList
{
private:
	ElemType *elem;//����Ԫ��ָ��
	int length;//Ԫ�ظ���
	int listsize;//����
public:
	SqList();//���캯��
	bool isFull()const;//�鿴���Ƿ��
	bool isEmpty()const;//�鿴���Ƿ���
	~SqList();//��������
	ElemType getElem(int)const;//�鿴�ض�λ��Ԫ��
	bool insert(int, ElemType);//�����ض�λ��Ԫ��
	bool insert(ElemType);//�����ĩԪ��
	void create();//������
	void merge(SqList&, SqList&);//�ϲ�������
	bool del(int);//ɾ����Ԫ��
	void displayElem();//��ʾ�����
};
#endif