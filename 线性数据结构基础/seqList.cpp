#include"seqList.h"
using namespace std;
/*���캯��*/
SqList::SqList()
{
	elem=new ElemType(initsize);
	length=0;
	listsize=initsize;
}
/*�ж��Ƿ���*/
bool SqList::isFull()const
{
	return length==listsize;
}
/*�Ƿ�Ϊ��*/
bool SqList::isEmpty()const
{
	return length==0;
}
ElemType SqList::getElem(int i)const
{
	if(i>length||i<1)
	{
		cout<<"i-value is illegal!";
		return 0;
	}
	else
	{
		return elem[i-1];
	}
}
bool SqList::insert(int i,ElemType e)
{
	if(i>length+1||i<1)
	{
		cout<<"i-value is illeagal!";
		return false;
	}
	if(isFull())//�������·����ڴ�
	{
		ElemType *newBase=new ElemType[listsize+increment];
		for(int j=0;j<listsize;i++)
		{
			newBase[j]=elem[j];
			delete[]elem;//�ͷŶ�̬���������
			elem=newBase;
			listsize+=increment;
		}
		ElemType *p=&(elem[i-1]);
		ElemType *q=&(elem[length-1]);
		for(;q>=p;--q)
			*(q+1)=*(q);
		*p=e;
		++length;
		return true;
	}
}
bool SqList::insert(ElemType e)
{
	if(isFull())//�������·����ڴ�
	{
		ElemType *newBase=new ElemType[listsize+increment];
		for(int i=0;i<listsize;i++)
			newBase[i]=elem[i];
		delete []elem;
		elem=newBase;
		listsize+=increment;
	}
	ElemType *p=&(elem[length]);
	*p=e;
	++length;
	return true;
}
void SqList::creat()
{
	cout<<"Ϊ�����Ԫ��(����0�˳�!)"<<endl;
	while(true)
	{
		int elem;
		cin>>elem;
		if(elem!=0)
		{
			insert(elem);
		}
		else
		{
			cout<<"������ɣ���СΪ��"<<listsize<<","<<endl;
			cout<<"������"<<length<<"��Ԫ�أ�"<<endl;
			for(int i=1;i<=length;i++)
				cout<<getElem(i)<<",";
			cout<<endl;
			break;
		}
	}
}
void SqList::merge(SqList &La,SqList &Lb)
{
	int i=1,j=1,k=0;
	while(i<=La.length&&j<=Lb.length)
	{
		if(La.getElem(i)<=Lb.getElem(j))
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
	while(i<La.length)
	{
		insert(++k,La.getElem(i));
		++i;
	}
	while(j<Lb.length)
	{
		insert(++k,Lb.getElem(j));
		++j;
	}
	cout<<"�ϲ���Ԫ��Ϊ��"<<endl;
	for(int m=1;m<length;m++)
	{
		cout<<getElem(m)<<endl;
	}
}
//ɾ����i��Ԫ��
bool SqList::del(int i)
{
	if(i>length||i<1)
	{
		cout<<"i-value is illegal!";
		return false;
	}
	ElemType *p=&(elem[i-1]);
	ElemType *q=&(elem[length-1]);
	for(++p;p<=q;++p)
		*(p-1)=*p;		
	--length;		
	return true;

}
void SqList::displayElem()
{
	cout<<"��Ĵ�СΪ��"<<listsize<<"."<<endl;
	cout<<"������"<<length<<"��Ԫ��"<<endl;
	for(int i=1;i<=length;i++)
	{
		cout<<getElem(i)<<",";
	}
	cout<<endl;
}
SqList::~SqList()
{
	delete[]elem;
}
